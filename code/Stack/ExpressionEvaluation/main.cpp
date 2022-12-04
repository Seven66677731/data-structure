
#include<stdlib.h>
#include<stdio.h>

#define Maxsize 10
typedef struct node{
    char data[Maxsize];
    int top;
} Stack;

bool Isempty(Stack &s) {
    if (s.top == -1) {
        return true;
    }
    return false;
}

bool IsFull(Stack &s) {
    if (s.top + 1 == Maxsize) {
        return true;
    }
    return false;
}

void InitStack(Stack &s) {
    s.top = -1;
}

bool PushStack(Stack &s, char data) {
    if (IsFull(s)) {
        return false;
    }
    s.data[++s.top] = data;
    return true;
}

bool PopStack(Stack &s, char &data) {
    if (Isempty(s)) {
        return false;
    }
    data = s.data[s.top--];
    return true;
}

bool GetTop(Stack &s, char &data) {
    if (Isempty(s)) {
        return false;
    }
    data = s.data[s.top];
    return true;
}

int length(char str[]) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

bool IsNumber(char a) {
    if (a >= '0' && a <= '9') {
        return true;
    }
    return false;
}

void change(Stack &s, char str[], char last[]) {
    int len = length(str);
    int flag = -1;
    char data;
    for (int i = 0; i < len; i++) {
        /*
        如果是数字，直接拿出来，不做任何处理
        */
        if (IsNumber(str[i])) {
            flag++;
            last[flag] = str[i];
        }
            /*
            加减运算符优先级最低，如果栈顶元素为空则直接⼊栈，否则将栈中存储的运算符全部弹栈，
            如果遇到左括号则停⽌，将弹出的左括号从新压栈，因为左括号要和⼜括号匹配时弹出，
            这个后⾯单独讨论。弹出后将优先级低的运算符压⼊栈中
            */
        else if (str[i] == '+' || str[i] == '-') {
            if (Isempty(s)) {
                PushStack(s, str[i]);
            } else {
                while (!Isempty(s) && s.data[s.top] != '(') {
                    PopStack(s, data);
                    flag++;
                    last[flag] = data;
                }
                PushStack(s, str[i]);
            }
        }
        /*
        乘、除、左括号都是优先级⾼的，直接压栈
        */
        else if (str[i]== '(' || str[i] == '*' || str[i] == '/') {
            PushStack(s, str[i]);
        }
        /*
        当遇到右括号是，把括号⾥剩余的运算符弹出，直到匹配到左括号为⽌
        左括号只弹出不打印（右括号也不压栈）
        */
        else if (str[i]== ')') {
            PopStack(s, data);
            while (data != '(') {flag++;last[flag] =data;
                PopStack(s, data);
            }
        }
    }
/*
最后把栈中剩余的运算符依次弹栈
 */
    while (!Isempty(s)) {
        PopStack(s, data);
        flag++;
        last[flag] = data;
    }
    last[++flag] = '\0';
}

bool lastnum(Stack &s, char str[], char &data) {
    int len = length(str);
    char a, b, c;
    int x, y;
    for (int i = 0; i < len; i++) {
        if (IsNumber(str[i])) {
            PushStack(s, str[i]);
        } else {
            PopStack(s, b);
            PopStack(s, a);
            if (str[i] == '+') {
                x = a - '0';
                y = b - '0';
                x = x + y;
            } else if (str[i]== '-') {
                x = a - '0';
                y = b - '0';
                x = x - y;
            } else if (str[i] == '*') {
                x = a - '0';
                y = b - '0';
                x = x * y;
            } else if (str[i]== '/') {
                x = a - '0';
                y = b - '0';
                x = x / y;
            }
            c = x + 48;
            PushStack(s, c
            );
        }
    }
    PopStack(s, data);
}


int main() {
    Stack s;
    InitStack(s);
    char data;
    char str[] = "(1+2)*3";
    int len = length(str);
    char last[] = "";
    change(s, str, last);
    lastnum(s, last, data);
    int zdk = data - '0';

    printf("%d", zdk);
}