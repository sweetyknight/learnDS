#include "linklist.cpp"
void sort(LinkList *&L)
{
	LinkList *p=L->next,*q,*r;
	if (p!=NULL)				//��ԭ����������һ�������ϵ����ݽ��
	{	r=p->next;				//r����*p����̽���ָ��
		p->next=NULL;			//����ֻ��һ�����ݽ��������
		p=r;
		while (p!=NULL)
		{	r=p->next;			//r����*p����̽���ָ��
			q=L;
			while (q->next!=NULL && q->next->data<p->data)	
				q=q->next;		//����������Ҳ���*p��ǰ�����*q
			p->next=q->next;	//��*p���뵽*q֮��
			q->next=p;
			p=r;				//ɨ��ԭ���������µĽ��
		}
	}
}
void main()
{
	LinkList *L;
	int n=10;
	char a[]={'1','3','2','9','0','4','7','6','5','8'};
	InitList(L);
	CreateListR(L,a,n);
	printf("L:");DispList(L);
	printf("����\n");
	sort(L);
	printf("L:");DispList(L);
	DestroyList(L);
}

