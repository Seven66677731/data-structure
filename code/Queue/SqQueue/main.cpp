#include <iostream>
#include <stdio.h>

#define maxSize 10

typedef struct {
    int data[maxSize];
    int front, rear;
} SqQueue;

void initQueue(SqQueue &Q) {
    Q.front = Q.rear = 0;
}

bool isEmpty(SqQueue Q) {

    return Q.front == Q.rear;
}

bool isFull(SqQueue Q) {
    //队尾指针的下一个是否为队头指针
    return (Q.rear + 1) % maxSize == Q.front;
}

bool enQueue(SqQueue &Q, int e) {
    if (isFull(Q)) {
        return false;
    }

    Q.data[Q.rear] = e;
    //循环队列实现入队
    Q.rear = (Q.rear + 1) % maxSize;
    return true;
}

bool deQueue(SqQueue &Q, int &e) {
    if (isEmpty(Q)) {
        return false;
    }
    e = Q.data[Q.front];
    //循环队列实现出队
    Q.front = (Q.front + 1) % maxSize;
    return true;
}

bool getHead(SqQueue Q, int &e) {
    if (isEmpty(Q)) {
        return false;
    }
    e = Q.data[Q.front];
    return true;
}

int getLength(SqQueue Q){
    return(Q.rear+maxSize-Q.front)%maxSize;
}

void print(SqQueue Q) {
    int e;
    while (deQueue(Q, e)) {
        printf("%d,", e);
    }
    printf("\n");
}


int main() {
    SqQueue Q;
    initQueue(Q);
    enQueue(Q, 1);
    enQueue(Q, 2);
    enQueue(Q, 3);

    print(Q);

    printf("%d", getLength(Q));
    return 0;
}
