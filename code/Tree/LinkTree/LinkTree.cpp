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
 * 带头节点
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

//创建二叉树
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

//先序遍历 O(h) h为树的高度
void preOrder(BiTree t) {
    if (t != NULL) {
        visit(t);
        preOrder(t->l);
        preOrder(t->r);
    }
}

//中序遍历 O(h) h为树的高度
void inOrder(BiTree t) {
    if (t != NULL) {
        preOrder(t->l);
        visit(t);
        preOrder(t->r);
    }
}

//后序遍历 O(h) h为树的高度
void postOrder(BiTree t) {
    if (t != NULL) {
        preOrder(t->l);
        preOrder(t->r);
        visit(t);
    }
}

//求树的高度
int treeDepth(BiTree t) {
    if (t == NULL) {
        return 0;
    } else {
        int l = treeDepth(t->l);
        int r = treeDepth(t->r);
        return l > r ? l + 1 : r + 1;
    }
}

//层次遍历
void levelOrder(BiTree T) {
    //辅助队列
    LinkQueue Q;
    initLinkQueue(Q);
    BiTree p;
    //根节点入队
    enQueue(Q, T);
    //队列不为空则循环，对头结点出队
    while (deQueue(Q, p)) {
        //访问出队结点
        visit(p);
        //左孩子不为空则左孩子入队
        if (p->l != NULL) {
            enQueue(Q, p->l);
        }
        //右孩子不为空则左孩子入队
        if (p->r != NULL) {
            enQueue(Q, p->r);
        }
    }
}

int main() {

    BiTree root = NULL;

    //ABC##DE#G##F###
    createTree(root);

    printf("\n先序:");
    preOrder(root);
    printf("\n中序:");
    inOrder(root);
    printf("\n后序:");
    postOrder(root);
    printf("\n层次:");
    levelOrder(root);



    return 0;
}