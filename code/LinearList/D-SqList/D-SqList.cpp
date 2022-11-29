#include<stdlib.h>

#define initSize 10

typedef struct {
	int* data;
	int maxSize;
	int Length;
}SqList;


void initList(SqList& L) {
	L.data = (int*)malloc(sizeof(int) * initSize);
	L.data = 0;
	L.maxSize = initSize;
}

void increaseSize(SqList& L, int len) {
	int* p = L.data;
	L.data = (int*)malloc(sizeof(int) * (L.maxSize + len));
	for (int i = 0; i < L.maxSize; i++) {
		L.data[i] = p[i];
	}
	L.maxSize = L.maxSize + len;
	free(p);
}


int main() {
	SqList L;
	initList(L);
	increaseSize(L, 5);

}