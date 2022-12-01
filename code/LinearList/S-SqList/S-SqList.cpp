#include<stdio.h>

#define maxSize  10
typedef struct {
	int data[maxSize];
	int length;
}SqList;

/*
初始化顺序表
*/
void InitList(SqList& L) {
	//将所有数据初始化，防止出现“脏数据”，可省略
	for (int i = 0; i < maxSize; i++) {
		L.data[i] = 0;
	}
	L.length = 0;
}

/*
在指定位置插入数据
*/
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

/*
删除指定位置的值
*/
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

/*
按位查找，时间复杂度O(1)
*/
int get(SqList L, int i) {
	return L.data[i - 1];
}


/*
按值查找，时间复杂度O(n)
*/
int locate(SqList L, int e) {
	for (int i = 0; i < L.length; i++) {
		if (L.data[i] == e) {
			return i+1;
			break;
		}
	}
	return 0;
}

/*
打印顺序表
*/
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
	//int e=0;
	//deleteList(L, 1, e);
	//printf("%d\n", e);
	printf("%d",locate(L, 1));


	//print(L);
	return 0;
}