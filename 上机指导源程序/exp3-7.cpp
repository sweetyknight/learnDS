//�ļ���:exp3-7.cpp
#include <stdio.h>
#include <malloc.h>
#define N 3					//ͣ����������ͣ����
#define M 4					//�򳵳�������ͣ����
#define Price 2				//ÿ��λͣ������
typedef struct 
{
	int CarNo[N];			//���ƺ�
	int CarTime[N];			//����ʱ��
	int top;				//ջָ��
} SqStack;					//����˳��ջ����
typedef struct 
{
	int CarNo[M];			//���ƺ�
	int front,rear;			//���׺Ͷ�βָ��
} SqQueue;					//����ѭ��������

//����Ϊ˳��ջ�Ļ��������㷨
void InitStack(SqStack *&s)
{
	s=(SqStack *)malloc(sizeof(SqStack));
	s->top=-1;
}
int StackEmpty(SqStack *s)
{
	return(s->top==-1);
}
int StackFull(SqStack *s)
{
	return(s->top==N-1);
}
int Push(SqStack *&s,int e1,int e2)
{
	if (s->top==N-1)
		return 0;
	s->top++;
	s->CarNo[s->top]=e1;
	s->CarTime[s->top]=e2;
	return 1;
}
int Pop(SqStack *&s,int &e1,int &e2)
{
	if (s->top==-1)
		return 0;
	e1=s->CarNo[s->top];
	e2=s->CarTime[s->top];
	s->top--;
	return 1;
}
void DispStack(SqStack *s)
{
	int i;
	for (i=s->top;i>=0;i--)
		printf("%d ",s->CarNo[i]);
	printf("\n");
}

//����Ϊѭ�����еĻ��������㷨
void InitQueue(SqQueue *&q)
{
	q=(SqQueue *)malloc (sizeof(SqQueue));
	q->front=q->rear=0;
}
int QueueEmpty(SqQueue *q)
{
	return(q->front==q->rear);
}
int QueueFull(SqQueue *q)		//�ж϶���
{
	return ((q->rear+1)%M==q->front);
}
int enQueue(SqQueue *&q,int e)		//����
{
	if ((q->rear+1)%M==q->front)	//����
		return 0;
	q->rear=(q->rear+1)%M;
	q->CarNo[q->rear]=e;
	return 1;
}
int deQueue(SqQueue *&q,int &e)		//����
{
	if (q->front==q->rear)			//�ӿյ����
		return 0;
	q->front=(q->front+1)%M;
	e=q->CarNo[q->front];
	return 1;
}
void DispQueue(SqQueue *q)		//�������Ԫ��
{
	int i;
	i=(q->front+1)%M;
	printf("%d ",q->CarNo[i]);
	while ((q->rear-i+M)%M>0) 
	{
		i=(i+1)%M;
		printf("%d ",q->CarNo[i]);
	} 
	printf("\n");
}
void main()
{
	int comm;
	int no,e1,time,e2;
	int i,j;
	SqStack *St,*St1;
	SqQueue *Qu;
	InitStack(St);
	InitStack(St1);
	InitQueue(Qu);
	do
	{
		printf("����ָ��(1:���� 2:���� 3:ͣ���� 4:�򳵳� 0:�˳�):");
		scanf("%d%d%d",&comm,&no,&time);
		switch(comm)
		{
		case 1:		//��������
			if (!StackFull(St))			//ͣ��������
			{
				Push(St,no,time);
				printf("  >>ͣ����λ��:%d\n",St->top+1);
			}
			else						//ͣ������
			{
				if (!QueueFull(Qu))		//�򳵳�����
				{
					enQueue(Qu,no);
					printf("  >>�򳵳�λ��:%d\n",Qu->rear);
				}
				else
					printf("  >>�򳵳�����,����ͣ��\n");
			}
			break;
		case 2:		//��������
			for (i=0;i<=St->top && St->CarNo[i]!=no;i++);
			if (i>St->top)
				printf("  >>δ�ҵ��ñ�ŵ�����\n");
			else
			{
				for (j=i;j<=St->top;j++)
				{
					Pop(St,e1,e2);
					Push(St1,e1,e2);		//��������ʱջSt1��
				}
				Pop(St,e1,e2);				//�������뿪
				printf("  >>%d����ͣ������:%d\n",no,(time-e2)*Price);
				while (!StackEmpty(St1))	//����ʱջSt1���»ص�St��
				{
					Pop(St1,e1,e2);
					Push(St,e1,e2);
				}
				if (!QueueEmpty(Qu))		//�Ӳ���ʱ,����ͷ��ջSt
				{
					deQueue(Qu,e1);
					Push(St,e1,time);		//�Ե�ǰʱ�俪ʼ�Ʒ�
				}
			}
			break;
		case 3:		//��ʾͣ�������
			if (!StackEmpty(St))
			{
				printf("  >>ͣ�����еĳ���:");	//���ͣ�����еĳ���
				DispStack(St);
			}
			else
				printf("  >>ͣ�������޳���\n");	
			break;
		case 4:		//��ʾ�򳵳����
			if (!QueueEmpty(Qu))
			{
				printf("  >>�򳵳��еĳ���:");	//����򳵳��еĳ���
				DispQueue(Qu);
			}
			else
				printf("  >>�򳵳����޳���\n");	
			break;
		case 0:		//����
			if (!StackEmpty(St))
			{
				printf("  >>ͣ�����еĳ���:");	//���ͣ�����еĳ���
				DispStack(St);
			}
			if (!QueueEmpty(Qu))
			{
				printf("  >>�򳵳��еĳ���:");	//����򳵳��еĳ���
				DispQueue(Qu);
			}
			break;
		default:	//�������
			printf("  >>������������\n");
			break;
		} 
	} while(comm!=0);
}
