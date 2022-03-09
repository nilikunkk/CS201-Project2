void test5(int a, int b, int c, int d, int e){
    a = b * c;
    d = b;
    c = a + b;
    e = d * c;
    d = c + 5;
}
int main(){
	test5(1,2,3,4,5);
	return 0;
}
