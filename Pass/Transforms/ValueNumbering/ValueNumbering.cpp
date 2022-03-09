#include "llvm/Pass.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/Instruction.h"
#include <string>

#include "llvm/Support/FormatVariadic.h"

using namespace llvm;
using namespace std;

#define DEBUG_TYPE "ValueNumbering"

using namespace llvm;

//which starts out an anonymous namespace
//It makes the things declared inside of the anonymous namespace visible only to the current file. 
namespace {

struct ValueNumbering : public FunctionPass {
    //string func_name = "test1";
    static char ID;
    ValueNumbering() : FunctionPass(ID) {}

    bool runOnFunction(Function &F)override{
        errs()<<"ValueNumbering:"<<F.getName()<<"\n";
        //if (F.getName() != func_name) return false;
        
        map<Value*, int> valueMap;  //map store values
        map<string, int> exprMap;   //map store expressions
        int counter=1;              //value number start

        for(auto& basic_block:F){
            for(auto& inst:basic_block){
                //load
                if(inst.getOpcode()==Instruction::Load){
                    Value* source= inst.getOperand(0);  
                    Value* target= &inst;               
                    //not found
                    if (valueMap.find(source)==valueMap.end()){
                        valueMap[source]=counter;
                        counter++;
                    }
                    valueMap[target]=valueMap[source];
                    //print
                    errs()<<formatv("{0,-50}",inst);
                    errs()<<valueMap[target]<<"="<<valueMap[source]<<"\n";
                }

                //store
                if(inst.getOpcode() == Instruction::Store){
                    Value* source= inst.getOperand(0);
                    Value* target= inst.getOperand(1);
                    //VN
                    if (valueMap.find(source)==valueMap.end()){
                        valueMap[source]=counter;
                        counter++;
                    }
                    valueMap[target]=valueMap[source];

                    //print
                    errs()<<formatv("{0,-50}",inst);
                    errs()<<valueMap[target]<<"="<<valueMap[source]<<"\n";
                }

                //binary op
                if (inst.isBinaryOp()){
                    auto* ptr = dyn_cast<User>(&inst);
                    for (auto it = ptr->op_begin(); it != ptr->op_end(); ++it) {
                        if(valueMap.find(*it)==valueMap.end()){
                            valueMap[*it]=counter;
                            counter++;
                        }                  
                    }

                    //string for expression
                    string expr=to_string(valueMap[inst.getOperand(0)])+" "+inst.getOpcodeName()+" "+to_string(valueMap[inst.getOperand(1)]);

                    string signal;
                    //VN for expression
                    if(exprMap.find(expr)!=exprMap.end()){
                        signal ="(redundant)";
                    }else{
                        signal="";
                        exprMap[expr]=counter;
                        counter++;
                    }
                    valueMap[&inst]=exprMap[expr];
                    //output
                    errs()<<formatv("{0,-50}",inst);
                    errs()<<valueMap[&inst]<<"="<<expr<<signal<<"\n";
                }//end if
            }//end for inst
        }//end for block
        return false;
    }
}; // end of struct ValueNumbering
}  // end of anonymous namespace



//We initialize pass ID here. LLVM uses ID’s address to identify a pass,
//so initialization value is not important.
char ValueNumbering::ID = 0;

//we register our class ValueNumbering, giving it a command line argument “ValueNumbering”, and a name “ValueNumbering Pass”.
//The last two arguments describe its behavior: 
//if a pass walks CFG without modifying it then the third argument is set to true; 
//if a pass is an analysis pass, for example dominator tree pass, then true is supplied as the fourth argument.
static RegisterPass<ValueNumbering> X("ValueNumbering", "ValueNumbering Pass",
                             false /* Only looks at CFG */,
                             false /* Analysis Pass */);
