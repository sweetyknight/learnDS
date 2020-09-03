//�ļ���:exp3-3.cpp
#include <stdio.h>
#include <malloc.h>
#define MaxSize 5
typedef char ElemType;
typedef struct 
{
	ElemType elem[MaxSize];
	int front,rear;		//���׺Ͷ�βָ��
} SqQueue;
extern void InitQueue(SqQueue *&q);
extern void ClearQueue(SqQueue *&q);
extern int QueueLength(SqQueue *q);
extern QueueEmpty(SqQueue *q);
extern int enQueue(SqQueue *&q,ElemType e);
extern int deQueue(SqQueue *&q,ElemType &e);
void main()
{
	ElemType e;
	SqQueue *q;
	printf("(1)��ʼ������q\n");
	InitQueue(q);
	printf("(2)���ν�����Ԫ��a,b,c\n");
	if (enQueue(q,'a')==0) printf("����,���ܽ���\n");
	if (enQueue(q,'b')==0) printf("����,���ܽ���\n");
	if (enQueue(q,'c')==0) printf("����,���ܽ���\n");
	printf("(3)����Ϊ%s\n",(QueueEmpty(q)?"��":"�ǿ�"));
	if (deQueue(q,e)==0) 
		printf("�ӿ�,���ܳ���\n");
	else
		printf("(4)����һ��Ԫ��%c\n",e);
	printf("(5)����q��Ԫ�ظ���:%d\n",QueueLength(q));
	printf("(6)���ν�����Ԫ��d,e,f\n");
	if (enQueue(q,'d')==0) printf("����,���ܽ���\n");
	if (enQueue(q,'e')==0) printf("����,���ܽ���\n");
	if (enQueue(q,'f')==0) printf("����,���ܽ���\n");
	printf("(7)����q��Ԫ�ظ���:%d\n",QueueLength(q));
	printf("(8)����������:");
	while (!QueueEmpty(q))
	{	deQueue(q,e);
		printf("%c ",e);
	}
	printf("\n");
	printf("(9)�ͷŶ���\n");
	ClearQueue(q);
}
