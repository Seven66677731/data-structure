#include<stdio.h>
#include<stdlib.h>

#define maxSize 10

typedef struct {
	int data[maxSize];
	int top;
}SqStcak;


void initStack(SqStcak &S) {
	S.top = 0;
}

bool isEmpty(SqStcak S) {
	return S.top == 0;
}

bool push(SqStcak &S,int e) {	
	//ջ��
	if(S.top==maxSize){

		return false;
	}
	//Ԫ����ջ,��ջ��ָ���ȼ�һ
	//S.top++;
	S.data[S.top++] = e;
	return true;
}

bool pop(SqStcak& S, int& e) {
	//ջ��
	if (isEmpty(S)) {
		return false;
	}
	//ջ��ָ���һ,��ջ��Ԫ�س�ջ,
	e = S.data[--S.top];
	return true;
}

bool getTop(SqStcak S, int& e) {
	//ջ��
	if (isEmpty(S)) {
		return false;
	}
	//ջ��Ԫ�س�ջ,��ջ��ָ���һ
	e = S.data[S.top];
	return true;
}

void destroy(SqStcak &S) {
	S.top = 0;
}

void print(SqStcak S) {
	int e;	
	//ջ��
	if (isEmpty(S)) {
		printf("ջ��");
	}
	
	while (pop(S,e))
	{
		printf("%d-", e);
	}
	printf("\n");
}

int main() {
	SqStcak S;
	initStack(S);

	push(S, 1);
	push(S, 2);
	push(S, 3);
	
	//pop(S, e);

	print(S);
	destroy(S);
	print(S);

	return 0;
}