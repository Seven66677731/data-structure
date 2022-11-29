#include<stdio.h>

#define maxSize  10
typedef struct {
	int data[maxSize];
	int length;
}SqList;


void InitList(SqList& L) {
	//���������ݳ�ʼ������ֹ���֡������ݡ�����ʡ��
	for (int i = 0; i < maxSize; i++) {
		L.data[i] = 0;
	}
	L.length = 0;
}

bool insertList(SqList &L ,int i,int e) {
	// �ж�i�ķ�Χ�Ƿ���Ч
	if (i<1||i>L.length+1) {
		return false;
	}
	// ���Ա��������޷�����
	if (L.length >= maxSize) {
		return false;
	}
	
	// ����i��Ԫ��֮���Ԫ�غ���
	for (int j = L.length; j >= i; j--) {
		L.data[j] = L.data[j - 1];
	}
	
	//����
	L.data[i-1] = e;

	//���ȼ�һ
	L.length++;
	return true;
}

bool deleteList(SqList& L, int i, int &e) {
	// �ж�i�ķ�Χ�Ƿ���Ч
	if (i<1 || i>L.length + 1) {
		return false;
	}

	// ����ɾ��Ԫ����e��
	e = L.data[i - 1];

	// ����i��Ԫ��λ�ú��Ԫ��ǰ��
	for (int j = i; j <= L.length; j++) {
		L.data[j-1] = L.data[j];
	}
	
	//���ȼ�һ
	L.length--;
	return true;
}


void print(SqList L) {
	for (int i = 0; i < L.length; i++) {
		printf("%d", L.data[i]);
	}
}

int main() {
	SqList L;
	InitList(L);
	insertList(L, 1, 1);
	insertList(L, 2, 2);
	int e=0;
	deleteList(L, 1, e);
	printf("%d\n", e);
	
	print(L);
	return 0;
}