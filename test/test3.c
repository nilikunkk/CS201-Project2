void test3(int a, int c, int d, int x, int y, int z) {
    a = x + y;
    z = y;
    d = 17;
    c = x + z;
}
int main(){
	test3(1,2,3,4,5,6);
	return 0;
}
