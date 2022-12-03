#include <iostream>

#include<stdio.h>
#include<stdlib.h>


typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, * LinkList;


bool initLinkList(LinkList &L) {
	L = NULL;
	return true;
}

bool Empty(LinkList L) {
	return (L == NULL);
}

/*
在第i个位置插入e
*/
bool insert(LinkList& L, int i, int e) {
	//判断i的合法性
	if (i < 1) {
		return false;
	}
	//判断i=1是的情况
	if (i == 1) {
		LNode* s = (LNode*)malloc(sizeof(LNode));
		s->data = e;
		s->next = L;
		L = s;
		return true;
	}
	//使用p指向L的头节点
	LNode* p = L;
	//用j代表第几个节点
	int j = 1;
	//找到第i-1个节点
	while (p != NULL && j < i - 1) {
		p = p->next;
		j++;
	}
	//如果超出链表尾部
	if (p == NULL) {
		return false;
	}

	//申请节点内存
	LNode* s = (LNode*)malloc(sizeof(LNode));

	//插入节点
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}

void print(LinkList L) {
	while (L != NULL) {
		if (L->next != NULL) {
			printf("%d->", L->data);
		}
		else {
			printf("%d", L->data);
		}
		L =L->next;
	}
}

/*
删除第i个位置并返回e,O(n)
*/
bool deleteList(LinkList& L, int i, int& e) {
	if (i < 1) {
		return false;
	}
	if (i == 1) {
		LNode* q = L;
		e = q->data;
		q->next = L->next;
		free(L);
		return true;
	}
	LNode* p = L;
	//用j代表第几个节点
	int j = 1;
	//找到第i-1个节点
	while (p != NULL && j < i - 1) {
		p = p->next;
		j++;
	}
	//如果超出链表尾部
	if (p == NULL || p->next == NULL) {
		return false;
	}
	LNode* q = p->next;
	e = q->data;
	p->next = q->next;
	free(q);
	return true;
}

/*
尾插法，O(n)
*/
LinkList listTailInsert(LinkList& L) {
	//初始化链表
	//initLinkList(L);

	//尾指针指向L
	LNode* p = L;

	//输入值x
	int x;
	scanf_s("%d", &x);
	//x=-1时停止输入
	while (x != -1) {
		if (p == NULL) {
			LNode* s = (LNode*)malloc(sizeof(LNode));
			s->data = x;
			s->next = NULL;
			L = s;
			p = L;
		}
		else
		{
			//新建结点
			LNode* s = (LNode*)malloc(sizeof(LNode));
			s->data = x;
			p->next = s;
			p = s;
		}

		scanf_s("%d", &x);
	}
	p->next = NULL;
	return L;
}


/*
头插法，O(n)
*/
LinkList listHeadInsert(LinkList& L) {
	//初始化链表
	initLinkList(L);

	//输入值x
	int x;
	scanf_s("%d", &x);
	//x=-1时停止输入
	while (x != -1) {
		//新建结点
		LNode* s = (LNode*)malloc(sizeof(LNode));
		//设置新建结点的值为x
		s->data = x;
		//新建结点的next为L
		s->next = L;
		//L指向新建结点
		L = s;
		scanf_s("%d", &x);
	}
	return L;
}




//求表的长度
int Length(LinkList L) {
	int len = 1; //统计表长
	LNode* p = L;
	while (p->next != NULL) {
		p = p->next;
		len++;
	}
	return len;
}


LinkList reserve(LinkList L) {

	LinkList reserveList;
	initLinkList(reserveList);

	LNode* p = L;
	while (p != NULL) {
		LNode* s = (LNode*)malloc(sizeof(LNode));
		s->data = p->data;
		s->next = reserveList;
		reserveList = s;
		p = p->next;
	}

	return reserveList;
}

int main() {
	LinkList  L;
	initLinkList(L);
	insert(L, 1, 1);
	insert(L, 2, 2);
	insert(L, 3, 3);
	////printf("%d", Length(L));



	//int e = 0;
	//deleteList(L, 3, e);
	//printf("%d", e);

	//L=listHeadInsert(L);
	print(L);
	L = reserve(L);
	print(L);

	return 0;
}