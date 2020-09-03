#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
typedef char ElemType;
typedef struct 
{	
	ElemType data[MaxSize];
	int front,rear;		//���׺Ͷ�βָ��
} SqQueue;
void InitQueue(SqQueue *&q)
{
	q=(SqQueue *)malloc (sizeof(SqQueue));
	q->front=q->rear=0;
}
void ClearQueue(SqQueue *&q)
{
	free(q);
}
int QueueEmpty(SqQueue *q)
{
	return(q->front==q->rear);
}
int enQueue(SqQueue *&q,ElemType e)
{
	if ((q->rear+1)%MaxSize==q->front)  //����
		return 0;
	q->rear=(q->rear+1)%MaxSize;
	q->data[q->rear]=e;
	return 1;
}
int deQueue(SqQueue *&q,ElemType &e)
{
	if (q->front==q->rear)  //�ӿ�
		return 0;
	q->front=(q->front+1)%MaxSize;
	e=q->data[q->front];
	return 1;
}
