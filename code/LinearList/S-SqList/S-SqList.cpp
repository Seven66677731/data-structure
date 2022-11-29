#include<stdio.h>

#define maxSize  10
typedef struct {
	int data[maxSize];
	int length;
}SqList;


void InitList(SqList& L) {
	//将所有数据初始化，防止出现“脏数据”，可省略
	for (int i = 0; i < maxSize; i++) {
		L.data[i] = 0;
	}
	L.length = 0;
}

bool insertList(SqList &L ,int i,int e) {
	// 判断i的范围是否有效
	if (i<1||i>L.length+1) {
		return false;
	}
	// 线性表已满，无法插入
	if (L.length >= maxSize) {
		return false;
	}
	
	// 将第i个元素之后的元素后移
	for (int j = L.length; j >= i; j--) {
		L.data[j] = L.data[j - 1];
	}
	
	//插入
	L.data[i-1] = e;

	//长度加一
	L.length++;
	return true;
}

bool deleteList(SqList& L, int i, int &e) {
	// 判断i的范围是否有效
	if (i<1 || i>L.length + 1) {
		return false;
	}

	// 返回删除元素至e中
	e = L.data[i - 1];

	// 将第i个元素位置后的元素前移
	for (int j = i; j <= L.length; j++) {
		L.data[j-1] = L.data[j];
	}
	
	//长度减一
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