#include "dlinklist.cpp"
void sort(DLinkList *&L)	//˫����Ԫ������
{
	DLinkList *p=L->next,*q,*r;
	if (p!=NULL)					//��ԭ˫��������һ�������ϵ����ݽ��
	{
		r=p->next;					//r����*p����̽���ָ��
		p->next=NULL;				//����ֻ��һ�����ݽ��������
		p=r;
		while (p!=NULL)
		{	r=p->next;				//r����*p����̽���ָ��
			q=L;
			while (q->next!=NULL && q->next->data<p->data)	
				q=q->next;			//����������Ҳ���*p��ǰ�����*q
			p->next=q->next;		//��*p���뵽*q֮��
			if (q->next!=NULL) q->next->prior=p;
			q->next=p;
			p->prior=q;
			p=r;
		}
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
	sort(L);
	printf("L:");DispList(L);
}
