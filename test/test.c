void test(int a, int b, int c, int d, int e, int f)
{
    c = a + b;
    d = b + c;
    e = a + b;
    f = b + e;
}

int main(){
    test(1,2,3,4,5,6);
    return 0;
}
