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
��ָ���ڵ�ǰ����ڵ� O(1)
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
��ָ���ڵ�����ڵ�e O(1)
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
��λ���� O(n)
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
��ֵ���� O(n)
*/
LNode* locatelElem(LinkList L, int e) {
	LNode* p = L->next;
	while (p->data != e&&p!=NULL) {
		p = p->next;
	}
	return p;
}

/*
�ڵ�i��λ�ò���e O(n)
*/
bool insert(LinkList &L, int i, int e) {
	//�ж�i�ĺϷ���
	if (i < 1) {
		return false;
	}
	////ʹ��pָ��L��ͷ�ڵ�
	//LNode* p=L;
	////��j����ڼ����ڵ�
	//int j = 0;
	////�ҵ���i-1���ڵ�
	//while (p != NULL && j < i-1) {
	//	p = p->next;
	//	j++;
	//}
	LNode* p = getElem(L, i - 1);
	//	//�����������β��
	//if (p == NULL) {
	//	return false;
	//}

	////����ڵ��ڴ�
	//LNode* s = (LNode *)malloc(sizeof(LNode));

	////����ڵ�
	//s->data = e;
	//s->next = p->next;
	//p->next = s;
	//return true;
	return insertNextNode(p, e);
}


/*
ɾ����i��λ�ò�����e,O(n)
*/
bool deleteList(LinkList& L, int i, int& e) {
	if (i < 1) {
		return false;
	}
	LNode* p = L;
	//��j����ڼ����ڵ�
	int j = 0;
	//�ҵ���i-1���ڵ�
	while (p != NULL && j < i - 1) {
		p = p->next;
		j++;
	}
	//�����������β��
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
ɾ��ָ���ڵ㲢����e, O(1)
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

//���ĳ���
int Length(LinkList L) {
	int len = 0; //ͳ�Ʊ�
	LNode * p = L;
	while (p->next !=NULL){
		p = p->next;
		len++;
	}
	return len;
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
	//print(L);
	insert(L, 1, 1);
	insert(L, 2, 2);
	insert(L, 3, 3);
	print(L);
	int e=0;
	deleteList(L, 3, e);
	printf("%d", e);

	printf("%d", getElem(L, 1)->data);

	printf("%d", Length(L));
	return 0;
}