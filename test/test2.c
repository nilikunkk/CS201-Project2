void test2(int a, int b, int c, int x, int y) {
    b = x + y;
    a = x + y;
    a = 17;
    c = x + y;
}

int main(){
	test2(1,2,3,4,5);
	return 0;
}

