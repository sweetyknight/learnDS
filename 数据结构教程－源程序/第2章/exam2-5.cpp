#include "linklist.cpp"
void split(LinkList *&L,LinkList *&L1,LinkList *&L2)
{
	LinkList *p=L->next,*q,*r1;
	L1=L;					//L1����ԭ��L��ͷ���
	L=NULL;					//L��Ϊ��
	r1=L1;					//r1ʼ��ָ��L1��β���
	L2=(LinkList *)malloc(sizeof(LinkList)); //����L2��ͷ���
	L2->next=NULL;
	while (p!=NULL)
	{
		q=p->next;			//qָ��*p�ĺ������
		r1->next=p;
		r1=p;				//����β�巨��*p����L1��
		p=q->next;
		q->next=L2->next;	
		L2->next=q;			//����ͷ�巨��*p����L2��
	}
	r1->next=NULL;			//β���next�ÿ�
}
void main()
{
	LinkList *L,*L1,*L2;
	int n=10;
	char a[]={'a','b','c','d','e','f','g','h','i','j'};
	InitList(L);
	InitList(L1);
	InitList(L2);
	CreateListR(L,a,n);
	printf("L:");DispList(L);
	printf("L->L1,L2\n");
	split(L,L1,L2);
	printf("L1:");DispList(L1);
	printf("L2:");DispList(L2);
	DestroyList(L1);
	DestroyList(L2);
}
