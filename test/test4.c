void test4(int a, int b, int c, int d){
    a = b + c;
    b = a - d;
    c = b + c;
    d = a - d;
}
int main(){
	test4(1,2,3,4);
	return 0;
}
