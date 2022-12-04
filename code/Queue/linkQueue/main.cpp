#include <iostream>
#include <stdio.h>

typedef struct LinkNode{
    int data;
    LinkNode* next;
}LinkNode;

typedef struct {
    LinkNode* front,*rear;
}LinkQueue;


/**
 * 不带头节点
 * @return
 */

//void initLinkQueue(LinkQueue &Q){
//    Q.front=Q.rear=NULL;
//}
//
//bool enQueue(LinkQueue &Q,int e){
//    LinkNode* p = (LinkNode *) malloc(sizeof (LinkNode));
//    p->data=e;
//    p->next=NULL;
//
//    //插入第一个结点
//    if(Q.front==NULL){
//        Q.rear=p;
//        Q.front=p;
//    }
//    //插入非第一结点
//    else{
//        Q.rear->next=p;
//        Q.rear=p;
//    }
//    return true;
//}
//
//bool deQueue(LinkQueue &Q,int &e){
//    if(Q.front==Q.rear){
//        return false;
//    }
//
//    e=Q.front->data;
//    Q.front=Q.front->next;
//    return true;
//}


/**
 * 带头节点
 * @return
 */
void initLinkQueue(LinkQueue &Q){
    LinkNode* p = (LinkNode *) malloc(sizeof (LinkNode));
    Q.front=Q.rear=p;
    Q.front->next= NULL;
}

bool enQueue(LinkQueue &Q,int e){
    LinkNode* p = (LinkNode *) malloc(sizeof (LinkNode));
    p->data=e;
    p->next=NULL;

    Q.rear->next=p;
    Q.rear=p;
    return true;
}

bool deQueue(LinkQueue &Q,int &e){
    if(Q.front->next==NULL){
        return false;
    }

    e=Q.front->next->data;
    Q.front=Q.front->next;
    return true;
}


void print(LinkQueue &Q){
    int e;
    while (deQueue(Q,e)){
        printf("%d,",e);
    }
    printf("\n");
}

int main() {
    LinkQueue Q;
    initLinkQueue(Q);
    enQueue(Q,1);
    enQueue(Q,2);
    enQueue(Q,3);

    print(Q);

    printf("%d",(Q.rear==Q.front));


    return 0;
}
