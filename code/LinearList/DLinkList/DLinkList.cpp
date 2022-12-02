#include<stdio.h>
#include<stdlib.h>

typedef struct DNode{
	int data;
	DNode* prior, *next;
}DNode,*DLInkList;


bool initDLInkList(DLInkList &L) {
	L = (DNode*)malloc(sizeof(DNode));
	if (L == NULL) {
		return false;
	}
	L->prior = NULL;
	L->next = NULL;
	return true;
}

bool isEmpty(DLInkList L) {
	return (L->next == NULL);
}

/*
��p�������s���
*/
bool insertNextDNode(DNode* p, DNode* s) {
	//�ж�p,q�ĺϷ���
	if (p == NULL || s == NULL) {
		return false;
	}
	//s����nextΪp��next
	s->next = p->next;
	//�ж�p�Ƿ�Ϊ���һ����㣬��ֹp->next->prior��ָ�����
	if (p->next != NULL) {
		p->next->prior = s;
	}

	//s����priorΪp
	s->prior = p;
	//p��nextΪs
	p->next = s;
	return true;
}

/*
ɾ��p�ĺ�̽��
*/
bool deleteNextDNode(DNode* p) {
	if (p == NULL) {
		return false;
	}
	DNode* q = p->next;
	p->next = q->next;
	if (q->next != NULL) {
		q->next->prior = p;
	}
	free(q);
	return true;
}




int main() {
	DLInkList L;
	initDLInkList(L);
	printf("%d\n", isEmpty(L));
	return 0;
}