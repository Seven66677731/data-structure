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
	//栈满
	if(S.top==maxSize){

		return false;
	}
	//元素入栈,再栈顶指针先加一
	//S.top++;
	S.data[S.top++] = e;
	return true;
}

bool pop(SqStcak& S, int& e) {
	//栈空
	if (isEmpty(S)) {
		return false;
	}
	//栈顶指针减一,再栈顶元素出栈,
	e = S.data[--S.top];
	return true;
}

bool getTop(SqStcak S, int& e) {
	//栈空
	if (isEmpty(S)) {
		return false;
	}
	//栈顶元素出栈,再栈顶指针减一
	e = S.data[S.top];
	return true;
}

void destroy(SqStcak &S) {
	S.top = 0;
}

void print(SqStcak S) {
	int e;	
	//栈空
	if (isEmpty(S)) {
		printf("栈空");
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