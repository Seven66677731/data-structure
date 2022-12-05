/**
 * 中缀表达式转后缀表达式求值
 */

#include<stdio.h>
#include<stdlib.h>
#include <cstring>

/*
带头结点
*/
typedef struct LNode {
    char data;
    LNode *next;
} *LinkStack;

bool initLinkStack(LinkStack &S) {
    S = (LNode *) malloc(sizeof(LNode));
    if (S == NULL) {
        return false;
    }
    S->next = NULL;
    return true;
}

bool isEmpty(LinkStack S) {
    return S->next == NULL;
}

bool push(LinkStack &S, char e) {
    LNode *p = (LNode *) malloc(sizeof(LNode));
    if (p == NULL) {
        return false;
    }
    p->next = S->next;
    p->data = e;
    S->next = p;

    return true;
}


bool pop(LinkStack &S, char &e) {
    if (isEmpty(S)) {
        return false;
    }

    LNode *p = S->next;

    S->next = S->next->next;
    e = p->data;

    return true;
}



char getTop(LinkStack S) {
    return S->next->data;
}

/*
计算结果
*/
char calc(char a, char b, char o) {
    int x = a - '0';
    int y = b - '0';
    if (o == '+') {
        return x + y;
    } else if (o == '-') {
        return x - y;
    } else if (o == '*') {
        return x * y;
    } else if (o == '/') {
        return x / y;
    }
}


char getResult(char str[]) {
    //数字栈
    LinkStack A;
    initLinkStack(A);
    //运算符栈
    LinkStack B;
    initLinkStack(B);

    char a, b, o, result;

    for (int i = 0; i < strlen(str); ++i) {
        char c = str[i];
        //如果为数字则直接如数字栈
        if (c >= '0' && c <= '9') {
            push(A, c);
        } else {
            //如果为)则出运算符栈，直到出栈的为(
            if (c == ')') {
                while (pop(B, o)) {
                    if (o == '(') {
                        break;
                    } else {
                        pop(A, b);
                        pop(A, a);
                        result = calc(a, b, o);
                        push(A, result + 48);
                    }
                }

            } else {
                //栈空，(，栈顶元素不为(,*/时栈顶元素不为*/ 以上情况均运算符栈
                if (isEmpty(B) || getTop(B) == '(' || c == '(' || c == '*' || c == '/' && getTop(B) == '+' ||
                    getTop(B) == '-') {

                    push(B, c);

                } else {
                    //不满足上述条件时
                    //出一个运算符栈元素
                    pop(B, o);

                    //先出数字栈的元素为右操作数
                    pop(A, b);
                    //后出数字栈的元素为左操作数
                    pop(A, a);
                    //计算两个值的结果，并压回数字栈
                    result = calc(a, b, o);
                    push(A, result + 48);
                    //操作符最后入操作符栈
                    push(B, c);
                }
            }
        }
    }

    //将操作符栈的元素全部出栈，并计算结果
    while (pop(B, o)) {
        pop(A, b);
        pop(A, a);
        result = calc(a, b, o);
        push(A, result + 48);
    }
    pop(A, result);


    return result - 48;
}

int main() {
    printf("%d", getResult("(2-1*2)+3*8/4"));
}