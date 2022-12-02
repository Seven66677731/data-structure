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
�ڵ�i��λ�ò���e
*/
bool insert(LinkList& L, int i, int e) {
	//�ж�i�ĺϷ���
	if (i < 1) {
		return false;
	}
	//�ж�i=1�ǵ����
	if (i == 1) {
		LNode* s = (LNode*)malloc(sizeof(LNode));
		s->data = e;
		s->next = L;
		L = s;
		return true;
	}
	//ʹ��pָ��L��ͷ�ڵ�
	LNode* p = L;
	//��j����ڼ����ڵ�
	int j = 1;
	//�ҵ���i-1���ڵ�
	while (p != NULL && j < i - 1) {
		p = p->next;
		j++;
	}
	//�����������β��
	if (p == NULL) {
		return false;
	}

	//����ڵ��ڴ�
	LNode* s = (LNode*)malloc(sizeof(LNode));

	//����ڵ�
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
ɾ����i��λ�ò�����e,O(n)
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
	//��j����ڼ����ڵ�
	int j = 1;
	//�ҵ���i-1���ڵ�
	while (p != NULL && j < i - 1) {
		p = p->next;
		j++;
	}
	//�����������β��
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
β�巨��O(n)
*/
LinkList listTailInsert(LinkList& L) {
	//��ʼ������
	//initLinkList(L);
	
	//βָ��ָ��L
	LNode* p = L;

	//����ֵx
	int x;
	scanf_s("%d", &x);
	//x=-1ʱֹͣ����
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
			//�½����
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
ͷ�巨��O(n)
*/
LinkList listHeadInsert(LinkList& L) {
	//��ʼ������
	initLinkList(L);

	//����ֵx
	int x;
	scanf_s("%d", &x);
	//x=-1ʱֹͣ����
	while (x != -1) {
		//�½����
		LNode* s = (LNode*)malloc(sizeof(LNode));
		//�����½�����ֵΪx
		s->data = x;
		//�½�����nextΪL
		s->next = L;
		//Lָ���½����
		L = s;	
		scanf_s("%d", &x);
	}
	return L;
}




//���ĳ���
int Length(LinkList L) {
	int len = 1; //ͳ�Ʊ�
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
	//insert(L, 1, 1);
	//insert(L, 2, 2);
	//insert(L, 3, 3);
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