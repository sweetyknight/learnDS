//�ļ���:algo3-4.cpp
#include <stdio.h>
#include <malloc.h>
typedef char ElemType;
typedef struct qnode
{
	ElemType data;
	struct qnode *next;
} QNode;
typedef struct
{
	QNode *front;
	QNode *rear;
} LiQueue;
void InitQueue(LiQueue *&q)
{
	q=(LiQueue *)malloc(sizeof(LiQueue));
	q->front=q->rear=NULL;
}
void ClearQueue(LiQueue *&q)
{
	QNode *p=q->front,*r;
	if (p!=NULL)		//�ͷ����ݽ��ռ�ÿռ�
	{
		r=p->next;
		while (r!=NULL)
		{
			free(p);
			p=r;r=p->next;
		}
	}
	free(q);			//�ͷ�ͷ���ռ�ÿռ�
}
int QueueLength(LiQueue *q)
{
	int n=0;
	QNode *p=q->front;
	while (p!=NULL)
	{
		n++;
		p=p->next;
	}
	return(n);
}
int QueueEmpty(LiQueue *q)
{
	if (q->rear==NULL)
		return 1;
	else
		return 0;
}
void enQueue(LiQueue *&q,ElemType e)
{
	QNode *s;
    s=(QNode *)malloc(sizeof(QNode));
	s->data=e;
	s->next=NULL;
    if (q->rear==NULL)		//������Ϊ��,���½���Ƕ��׽�����Ƕ�β���
		q->front=q->rear=s;
	else
	{
		q->rear->next=s;  //��*s���������β,rearָ����
		q->rear=s;
	}
}
int deQueue(LiQueue *&q,ElemType &e)
{
	QNode *t;
	if (q->rear==NULL)		//����Ϊ��
		return 0;
	if (q->front==q->rear)  //������ֻ��һ�����ʱ
	{
		t=q->front;
		q->front=q->rear=NULL;
	}
	else					//�������ж�����ʱ
	{
		t=q->front;
		q->front=q->front->next;
	}
	e=t->data;
    free(t);
	return 1;
}
