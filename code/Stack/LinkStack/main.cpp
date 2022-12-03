#include<stdio.h>
#include<stdlib.h>

typedef struct LNode {
	int data;
 	LNode* next;
} * LinkStack;

/*
不带头节点
*/
bool initLinkStack(LinkStack& S) {
	S = NULL;
	return true;
}

bool isEmpty(LinkStack S) {
	return S == NULL;
}

bool push(LinkStack& S,int e) {
	LNode* p = (LNode*)malloc(sizeof(LNode));
	if (p == NULL) {
		return false;
	}	
	p->data = e;
	p->next=S;
	
	S = p;

	return true;
}

bool pop(LinkStack& S, int &e) {
	if (isEmpty(S)) {
		return false;
	}

	LNode* p = S;
	S = S->next;
	e = p->data;

	return true;
}

void print(LinkStack S) {
	int e;
	while (pop(S,e))
	{
		printf("%d", e);
	}
}


///*
//带头结点
//*/
//bool initLinkStack(LinkStack& S) {
//	S = (LNode*)malloc(sizeof(LNode));
//	if (S == NULL) {
//		return false;
//	}
//	S->next = NULL;
//	return true;
//}
//
//bool isEmpty(LinkStack S) {
//	return S->next == NULL;
//}
//
//bool push(LinkStack& S,int e) {
//	LNode* p = (LNode*)malloc(sizeof(LNode));
//	if (p == NULL) {
//		return false;
//	}
//	p->next = S->next;
//	p->data = e;
//	S->next = p;
//
//	return true;
//}
//
//
//bool pop(LinkStack& S, int &e) {
//	if (isEmpty(S)) {
//		return false;
//	}
//
//	LNode* p =S->next;
//
//	S->next = S->next->next;
//	e = p->data;
//
//	return true;
//}
//
//
//
//
//void print(LinkStack S) {
//	int e;
//	while (pop(S,e))
//	{
//		printf("%d", e);
//	}
//}

int main(){
	LinkStack S;

	initLinkStack(S);
	
	push(S, 1);
	push(S, 2);
	push(S, 3);
	push(S, 4);
	push(S, 4);
	push(S, 4);
	push(S, 4);
	push(S, 4);


	print(S);
	
	return 0;
}