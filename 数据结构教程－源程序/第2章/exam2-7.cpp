#include "dlinklist.cpp"
void reverse(DLinkList *&L)	//˫����Ԫ������
{
	DLinkList *p=L->next,*q;
	L->next=NULL;					
	while (p!=NULL)
	{
		q=p->next;			//qָ��*p�ĺ������
		p->next=L->next;	//����ͷ�巨��*p�����뵽˫������
		if (L->next!=NULL) L->next->prior=p;
		L->next=p;
		p->prior=L;
		p=q;
	}
}
void main()
{
	ElemType a[]={'1','8','0','4','9','7','5','2','3','6'};
	DLinkList *L;
	InitList(L);
	CreateListR(L,a,10);
	printf("L:");DispList(L);
	printf("����\n");
	reverse(L);
	printf("L:");DispList(L);
}
