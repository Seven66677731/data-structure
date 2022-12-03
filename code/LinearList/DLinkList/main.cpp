#include<stdio.h>
#include<stdlib.h>

typedef struct DNode{
    int data;
    DNode* prior, *next;
}DNode,*DLInkList;


bool initDLInkList(DLInkList &L) {
    L = (DNode*)malloc(sizeof(DNode));
    if (L == NULL) {
        return false;
    }
    L->prior = NULL;
    L->next = NULL;
    return true;
}

bool isEmpty(DLInkList L) {
    return (L->next == NULL);
}

/*
在p结点后插入s结点
*/
bool insertNextDNode(DNode* p, DNode* s) {
    //判断p,q的合法性
    if (p == NULL || s == NULL) {
        return false;
    }
    //s结点的next为p的next
    s->next = p->next;
    //判断p是否为最后一个结点，防止p->next->prior空指针错误
    if (p->next != NULL) {
        p->next->prior = s;
    }

    //s结点的prior为p
    s->prior = p;
    //p的next为s
    p->next = s;
    return true;
}

/*
删除p的后继结点
*/
bool deleteNextDNode(DNode* p) {
    if (p == NULL) {
        return false;
    }
    DNode* q = p->next;
    p->next = q->next;
    if (q->next != NULL) {
        q->next->prior = p;
    }
    free(q);
    return true;
}




int main() {
    DLInkList L;
    initDLInkList(L);
    printf("%d\n", isEmpty(L));
    return 0;
}
