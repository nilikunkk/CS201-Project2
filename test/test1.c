void test1(int a, int b, int c, int d, int e, int f, int g) {
    c = a + b;
    d = c + 5;
    e = a + b;
    f = e + 5;
    g = d + f;
}
int main(){
	test1(1,2,3,4,5,6,7);
	return 0;
}
