#include "cdlinklist.cpp"
int delelem(DLinkList *&L,ElemType x)
{
	DLinkList *p=L->next; 
	while (p!=L && p->data!=x)
		p=p->next;
	if (p!=L)	//�ҵ���һ��Ԫ��ֵΪx�Ľ��
	{
		p->next->prior=p->prior;	//ɾ�����*p
		p->prior->next=p->next;
		free(p);
		return(1);
	}
	else return(0);
}
int delelem1(DLinkList *&L,ElemType x) //��2�ַ���
{
	DLinkList *pre=L,*p=pre->next; 
	while (p!=L && p->data!=x)
	{
		pre=p;
		p=p->next;
	}
	if (p!=L)	//�ҵ���һ��Ԫ��ֵΪx�Ľ��
	{
		p->next->prior=pre;	//ɾ�����*p
		pre->next=p->next;
		free(p);
		return(1);
	}
	else return(0);
}
void main()
{
	ElemType a[]={'1','2','2','4','2','3','5','2','1','4'};
	ElemType x='1';
	DLinkList *L;
	InitList(L);
	CreateListR(L,a,10);
	printf("L:");DispList(L);
	printf("ɾ����һ�����ֵΪ%c�Ľ��\n",x);
	if (delelem(L,x))
	{
		printf("L:");DispList(L);
	}
	else
		printf("ѭ��˫����L�в�����Ԫ��ֵΪ%c�Ľ��\n",x);
}
