//�ļ���:exp3-4.cpp
#include <stdio.h>
#include <malloc.h>
#define MaxSize 5
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
extern void InitQueue(LiQueue *&q);
extern void ClearQueue(LiQueue *&q);
extern int QueueLength(LiQueue *q);
extern int QueueEmpty(LiQueue *q);
extern void enQueue(LiQueue *&q,ElemType e);
extern int deQueue(LiQueue *&q,ElemType &e);
void main()
{
	ElemType e;
	LiQueue *q;
	printf("(1)��ʼ������q\n");
	InitQueue(q);
	printf("(2)���ν�����Ԫ��a,b,c\n");
	enQueue(q,'a');
	enQueue(q,'b');
	enQueue(q,'c');
	printf("(3)����Ϊ%s\n",(QueueEmpty(q)?"��":"�ǿ�"));
	if (deQueue(q,e)==0) 
		printf("�ӿ�,���ܳ���\n");
	else
		printf("(4)����һ��Ԫ��%c\n",e);
	printf("(5)����q��Ԫ�ظ���:%d\n",QueueLength(q));
	printf("(6)���ν�����Ԫ��d,e,f\n");
	enQueue(q,'d');
	enQueue(q,'e');
	enQueue(q,'f');
	printf("(7)����q��Ԫ�ظ���:%d\n",QueueLength(q));
	printf("(8)����������:");
	while (!QueueEmpty(q))
	{	deQueue(q,e);
		printf("%c ",e);
	}
	printf("\n");
	printf("(9)�ͷ�����\n");
	ClearQueue(q);
}
