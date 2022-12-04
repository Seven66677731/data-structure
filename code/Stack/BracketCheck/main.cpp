#include <iostream>
#include<cstdio>
#include<cstdlib>
#include <cstring>

typedef struct LNode {
    char data;
    LNode *next;
} *LinkStack;

/*
带头结点
*/
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


bool bracketCheck(char str[]) {
    LinkStack S;
    //初始化栈
    initLinkStack(S);

    for (int i = 0; i < strlen(str); ++i) {
        char c = str[i];
        if (c == '(') {
            push(S, ')');
        } else if (c == '{') {
            push(S, '}');
        } else if (c == '[') {
            push(S, ']');
        } else {
            //忽略非括号
            if (c == ')' || c == '}' || c == ']') {
                //匹配到单独的右括号
                if (isEmpty(S)) {
                    return false;
                }
                char e;
                pop(S, e);
                //判断弹出元素的合法性
                if (c != e) {
                    return false;
                }
            }
        }
    }
    //判断栈是否有剩余的左括号
    return isEmpty(S);
}

int main() {
    printf("%d", bracketCheck("{}{[(s)]}"));
    return 0;
}
