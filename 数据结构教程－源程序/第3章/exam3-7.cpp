#include "sqqueue.cpp"
int deQueue1(SqQueue *&q,ElemType &e) //�Ӷ�βɾ��
{
	if (q->front==q->rear)		//�ӿ�
		return 0;
	e=q->data[q->rear];			//��ȡ��βԪ��
	q->rear=(q->rear-1+MaxSize)%MaxSize;  //�޸ĳ�βָ��
	return 1;
}
int enQueue1(SqQueue *&q,ElemType e)	//�Ӷ�ͷ����
{
	if ((q->rear+1)%MaxSize==q->front)  //����
		return 0;
	q->data[q->front]=e;				//eԪ�����
	q->front=(q->front-1+MaxSize)%MaxSize;	//�޸Ķ�ͷָ��
	return 1;
}
void main()
{
	ElemType e;
	int i;
	SqQueue *q;
	InitQueue(q);
	printf("�Ӷ�β����a,b,�Ӷ�ͷ����c,d,�Ӷ�β����e\n");
	enQueue(q,'a');		//�Ӷ�β����'a'
	enQueue(q,'b');		//�Ӷ�β����'b'
	enQueue1(q,'c');	//�Ӷ�ͷ����'c'
	enQueue1(q,'d');	//�Ӷ�ͷ����'d'
	enQueue(q,'e');		//�Ӷ�β����'e'
	printf("�Ӷ�ͷ��������Ԫ��:\n");
	for (i=1;i<=2;i++)
	{
		deQueue(q,e);		//�Ӷ�ͷɾ��
		printf("%c ",e);
	}
	printf("\n�Ӷ�β��������Ԫ��:\n");
	while (!QueueEmpty(q))
	{
		deQueue1(q,e);		//�Ӷ�βɾ��
		printf("%c ",e);
	}
	printf("\n");
}
