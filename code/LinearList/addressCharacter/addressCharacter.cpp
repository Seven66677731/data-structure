# include<stdio.h>

void test1(int x) {
    x = 1024;
    printf("test�����ڲ� x=%d\n", x);
}

void test2(int& x) {
    x = 1024;
    printf("test�����ڲ� x=%d\n", x);
}

int main() {
    int x = 1;
    printf("����test����ǰ x=%d\n", x);
    test1(x);
    printf("����test������ x=%d\n", x);
    printf("================\n");
    printf("����test����ǰ x=%d\n", x);
    test2(x);
    printf("����test������ x=%d\n", x);
    return 0;
}
