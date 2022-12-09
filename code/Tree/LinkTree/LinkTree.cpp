//
// Created by 22600 on 2022/12/9.
//

#include <stdio.h>
#include <stdlib.h>

#define ElemType char


typedef struct BiTNode {
    ElemType data;
    BiTNode *l, *r;
} BiTNode, *BiTree;

typedef struct LinkNode {
    BiTNode *data;
    LinkNode *next;
} LinkNode;

typedef struct {
    LinkNode *front, *rear;
} LinkQueue;

/**
 * ��ͷ�ڵ�
 * @return
 */
void initLinkQueue(LinkQueue &Q) {
    LinkNode *p = (LinkNode *) malloc(sizeof(LinkNode));
    Q.front = Q.rear = p;
    Q.front->next = NULL;
}

bool enQueue(LinkQueue &Q, BiTree e) {
    LinkNode *p = (LinkNode *) malloc(sizeof(LinkNode));
    p->data = e;
    p->next = NULL;

    Q.rear->next = p;
    Q.rear = p;
    return true;
}

bool deQueue(LinkQueue &Q, BiTree &e) {
    if (Q.front->next == NULL) {
        return false;
    }

    e = Q.front->next->data;
    Q.front = Q.front->next;
    return true;
}

//����������
void createTree(BiTree &T) {
    char c;
    c = getchar();
    if (c == '#') {
        T = NULL;
    } else {
        T = (BiTNode *) malloc(sizeof(BiTNode));
        T->data = c;
        createTree(T->l);
        createTree(T->r);
    }
}

void visit(BiTree t) {
    printf("%c", t->data);
}

//������� O(h) hΪ���ĸ߶�
void preOrder(BiTree t) {
    if (t != NULL) {
        visit(t);
        preOrder(t->l);
        preOrder(t->r);
    }
}

//������� O(h) hΪ���ĸ߶�
void inOrder(BiTree t) {
    if (t != NULL) {
        preOrder(t->l);
        visit(t);
        preOrder(t->r);
    }
}

//������� O(h) hΪ���ĸ߶�
void postOrder(BiTree t) {
    if (t != NULL) {
        preOrder(t->l);
        preOrder(t->r);
        visit(t);
    }
}

//�����ĸ߶�
int treeDepth(BiTree t) {
    if (t == NULL) {
        return 0;
    } else {
        int l = treeDepth(t->l);
        int r = treeDepth(t->r);
        return l > r ? l + 1 : r + 1;
    }
}

//��α���
void levelOrder(BiTree T) {
    //��������
    LinkQueue Q;
    initLinkQueue(Q);
    BiTree p;
    //���ڵ����
    enQueue(Q, T);
    //���в�Ϊ����ѭ������ͷ������
    while (deQueue(Q, p)) {
        //���ʳ��ӽ��
        visit(p);
        //���Ӳ�Ϊ�����������
        if (p->l != NULL) {
            enQueue(Q, p->l);
        }
        //�Һ��Ӳ�Ϊ�����������
        if (p->r != NULL) {
            enQueue(Q, p->r);
        }
    }
}

int main() {

    BiTree root = NULL;

    //ABC##DE#G##F###
    createTree(root);

    printf("\n����:");
    preOrder(root);
    printf("\n����:");
    inOrder(root);
    printf("\n����:");
    postOrder(root);
    printf("\n���:");
    levelOrder(root);



    return 0;
}