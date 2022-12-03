# include<stdio.h>

void test1(int x) {
    x = 1024;
    printf("test函数内部 x=%d\n", x);
}

void test2(int& x) {
    x = 1024;
    printf("test函数内部 x=%d\n", x);
}

int main() {
    int x = 1;
    printf("调用test函数前 x=%d\n", x);
    test1(x);
    printf("调用test函数后 x=%d\n", x);
    printf("================\n");
    printf("调用test函数前 x=%d\n", x);
    test2(x);
    printf("调用test函数后 x=%d\n", x);
    return 0;
}
