#include <stdio.h>
#include <malloc.h>
typedef char ElemType;
typedef struct DNode  	//����˫����������
{
	ElemType data;
	struct DNode *prior;	//ָ��ǰ�����
	struct DNode *next;		//ָ���̽��
} DLinkList;
void InitQueue(DLinkList *&q)
{
	q=(DLinkList *)malloc(sizeof(DLinkList));
	q->prior=q;
	q->next=q;
}
int QueueEmpty(DLinkList *q)
{
	return(q->prior==q);
}
void enQueue(DLinkList *&q,ElemType e)
{
	DLinkList *p;
	p=(DLinkList *)malloc(sizeof(DLinkList *));
	p->data=e;
	q->prior->next=p;	//q->priorָ��ԭ����β���
	p->prior=q->prior;
	p->next=q;
	q->prior=p;
}
int deQueue(DLinkList *&q,ElemType &e)
{
	DLinkList *p;
	if (q->prior==q)	//ԭ��Ϊ��
		return(0);
	p=q->next;
	q->next=p->next;
	p->next->prior=q;
	e=p->data;
	free(p);
	return(1);
}
void main()
{
	ElemType e;
	DLinkList *q;
	InitQueue(q);
	printf("�ӿշ�:%d\n",QueueEmpty(q));
	printf("����a,b,c,d,e\n");
	enQueue(q,'a');
	enQueue(q,'b');
	enQueue(q,'c');
	enQueue(q,'d');
	enQueue(q,'e');
	printf("�ӿշ�:%d\n",QueueEmpty(q));
	printf("��������:");
	while (!QueueEmpty(q))
	{
	   deQueue(q,e);
	   printf("%c ",e);
	}
	printf("\n");
}


