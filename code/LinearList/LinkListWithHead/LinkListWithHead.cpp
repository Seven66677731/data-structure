#include<stdio.h>
#include<stdlib.h>

typedef struct LNode {
	int data;
	LNode* next;
}LNode,*LinkList;


bool initLinkList(LinkList &L) {
	L = (LNode*)malloc(sizeof(LNode));
	if (L == NULL) {
		return false;
	}
	L->next = NULL;
	return true;
}

bool Empty(LinkList L){
	return (L->next == NULL);
}


/*
在指定节点前插入节点 O(1)
*/
bool insertPriorNode(LNode* p, int e) {

	if (p == NULL) {
		return false;
	}
	LNode* s = (LNode*)malloc(sizeof(LNode));

	s->next = p->next;
	p->next = s;
	s->data = p->data;
	p->data = e;
	return true;
}

/*
在指定节点后插入节点e O(1)
*/
bool insertNextNode(LNode* p, int e) {
	if (p == NULL) {
		return false;
	}
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL) {
		return false;
	}
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}

/*
按位查找 O(n)
*/
LNode* getElem(LinkList L, int i) {
	if (i < 0) {
		return NULL;
	}
	LNode* p;
	int j = 0;
	p = L;

	while (p != NULL && j < i)
	{
		p = p->next;
		j++;
		
	}
	return p;
}

/*
按值查找 O(n)
*/
LNode* locatelElem(LinkList L, int e) {
	LNode* p = L->next;
	while (p->data != e&&p!=NULL) {
		p = p->next;
	}
	return p;
}

/*
在第i个位置插入e O(n)
*/
bool insert(LinkList &L, int i, int e) {
	//判断i的合法性
	if (i < 1) {
		return false;
	}
	////使用p指向L的头节点
	//LNode* p=L;
	////用j代表第几个节点
	//int j = 0;
	////找到第i-1个节点
	//while (p != NULL && j < i-1) {
	//	p = p->next;
	//	j++;
	//}
	LNode* p = getElem(L, i - 1);
	//	//如果超出链表尾部
	//if (p == NULL) {
	//	return false;
	//}

	////申请节点内存
	//LNode* s = (LNode *)malloc(sizeof(LNode));

	////插入节点
	//s->data = e;
	//s->next = p->next;
	//p->next = s;
	//return true;
	return insertNextNode(p, e);
}


/*
删除第i个位置并返回e,O(n)
*/
bool deleteList(LinkList& L, int i, int& e) {
	if (i < 1) {
		return false;
	}
	LNode* p = L;
	//用j代表第几个节点
	int j = 0;
	//找到第i-1个节点
	while (p != NULL && j < i - 1) {
		p = p->next;
		j++;
	}
	//如果超出链表尾部
	if (p == NULL || p->next==NULL) {
		return false;
	}
	LNode* q = p->next;
	e = q->data;
	p->next = q->next;
	free(q);
	return true;
}

/*
删除指定节点并返回e, O(1)
*/
bool deleteNode(LNode *p, int& e) {
	if (p == NULL) {
		return false;
	}
	LNode* q = p->next;
	p->data = q->data;
	p->next = q->next;
	free(q);
	return true;
}

//求表的长度
int Length(LinkList L) {
	int len = 0; //统计表长
	LNode * p = L;
	while (p->next !=NULL){
		p = p->next;
		len++;
	}
	return len;
}

/*
尾插法，O(n)
*/
LinkList listTailInsert(LinkList &L) {
	//初始化链表
	//initLinkList(L);
	//尾指针指向头节点
	LNode * p = L;
	//输入值x
	int x;
	scanf_s("%d", &x);
	//x=-1时停止输入
	while (x!=-1){
		//新建结点
		LNode* 	s=(LNode*)malloc(sizeof(LNode));
		//设置新建结点的值为x
		s->data = x;
		//尾指针的next为新建结点
		p->next = s;
		//尾指针指向新建结点
		p = s;
		scanf_s("%d",& x);
	}
	//尾指针的next指向NULL
	p->next = NULL;
	return L;
}

/*
头插法，O(n)
*/
LinkList listHeadInsert(LinkList& L) {
	//初始化链表
	//initLinkList(L);
	//p指针指向头节点
	LNode* p = L;
	//输入值x
	int x;
	scanf_s("%d", &x);
	//x=-1时停止输入
	while (x != -1) {
		//新建结点
		LNode* s = (LNode*)malloc(sizeof(LNode));
		//设置新建结点的值为x
		s->data = x;
		//新建结点的next为原来头指针的next
		s->next = p->next;
		//头节点的next为新建结点
		p->next = s;
		scanf_s("%d", &x);
	}
	return L;
}

/*
使用头插法，逆置链表
*/
LinkList reserve(LinkList L) {
	LinkList reserveList;
	initLinkList(reserveList);

	LNode* r = reserveList;
	
	LNode* p = L->next;
	while (p!= NULL) {
		LNode* s = (LNode*)malloc(sizeof(LNode));
		s->data = p->data;
		s->next = r->next;
		r->next = s;
		p = p->next;
	}
	return reserveList;
}

void print(LinkList L) {
	L = L->next;
	while (L!=NULL){
		if(L->next!=NULL){
			printf("%d->",L->data);
		}
		else{
			printf("%d", L->data);
		}
		L = L->next;
	}
	printf("\n");
}

int main() {
	LinkList  L;
	initLinkList(L);
	////print(L);
	insert(L, 1, 1);
	insert(L, 2, 2);
	insert(L, 3, 3);
	//print(L);
	//int e=0;
	//deleteList(L, 3, e);
	//printf("%d", e);

	//printf("%d", getElem(L, 1)->data);

	//printf("%d", Length(L));

	//L= listTailInsert(L);
	//L = listHeadInsert(L);
	print(L);
	L = reserve(L);

	print(L);
	return 0;
}