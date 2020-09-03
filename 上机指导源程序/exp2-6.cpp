//�ļ���:exp2-6.cpp
#include <stdio.h>
#include <malloc.h>
typedef char ElemType;
typedef struct LNode	//���嵥����������
{
	ElemType data;
    struct LNode *next;
} LinkList;
extern void DispList(LinkList *L);
void CreateListR(LinkList *&L,ElemType a[],int n) //β�巨����
{
	LinkList *s,*r;int i;
	L=(LinkList *)malloc(sizeof(LinkList));	//����ͷ���
	L->next=NULL;
	r=L;						//rʼ��ָ���ն˽��,��ʼʱָ��ͷ���
	for (i=0;i<n;i++)
	{
		s=(LinkList *)malloc(sizeof(LinkList));//�����½��
		s->data=a[i];
		r->next=s;				//��*s����*r֮��
		r=s;
	}
	r->next=NULL;				//�ն˽��next����ΪNULL
}
void Sort(LinkList *&head)		//������Ԫ������
{
	LinkList *p=head->next,*q,*r;
	if (p!=NULL)				//��ԭ����������һ�������ϵ����ݽ��
	{
		r=p->next;				//r����*p����̽���ָ��
		p->next=NULL;			//����ֻ��һ�����ݽ��������
		p=r;
		while (p!=NULL)
		{
			r=p->next;			//r����*p����̽���ָ��
			q=head;
			while (q->next!=NULL && q->next->data<p->data)	//����������Ҳ���*p��ǰ�����*q
				q=q->next;
			p->next=q->next;	//��*p���뵽*q֮��
			q->next=p;
			p=r;
		}
	}
}
void Union(LinkList *ha,LinkList *hb,LinkList *&hc)  //�������򼯺ϵĲ�
{
	LinkList *pa=ha->next,*pb=hb->next,*s,*tc;
	hc=(LinkList *)malloc(sizeof(LinkList));	//����ͷ���
	tc=hc;
	while (pa!=NULL && pb!=NULL)
	{
		if (pa->data<pb->data)
		{
			s=(LinkList *)malloc(sizeof(LinkList));	//���ƽ��
			s->data=pa->data;
			tc->next=s;tc=s;
			pa=pa->next;
		}
		else if (pa->data>pb->data)
		{
			s=(LinkList *)malloc(sizeof(LinkList));	//���ƽ��
			s->data=pb->data;
			tc->next=s;tc=s;
			pb=pb->next;
		}
		else
		{
			s=(LinkList *)malloc(sizeof(LinkList));	//���ƽ��
			s->data=pa->data;
			tc->next=s;tc=s;
			pa=pa->next;	//�ظ���Ԫ��ֻ����һ��
			pb=pb->next;
		}
	}
	if (pb!=NULL) pa=pb;	//�������µĽ��
	while (pa!=NULL)
	{
		s=(LinkList *)malloc(sizeof(LinkList));	//���ƽ��
		s->data=pa->data;
		tc->next=s;tc=s;
		pa=pa->next;
	}
	tc->next=NULL;
}
void InterSect(LinkList *ha,LinkList *hb,LinkList *&hc)	//�������򼯺ϵĲ�
{
   LinkList *pa=ha->next,*pb,*s,*tc;
   hc=(LinkList *)malloc(sizeof(LinkList));
   tc=hc;
   while (pa!=NULL)
   {
	   pb=hb->next;
	   while (pb!=NULL && pb->data<pa->data)  
		   pb=pb->next; 
	   if (pb!=NULL && pb->data==pa->data)			//��pa���ֵ��B��
	   {
		   s=(LinkList *)malloc(sizeof(LinkList));	//���ƽ��
		   s->data=pa->data;
		   tc->next=s;tc=s;
	   }
	   pa=pa->next;
   }
   tc->next=NULL;
}
void Subs(LinkList *ha,LinkList *hb,LinkList *&hc)	//�������򼯺ϵĲ�
{
   LinkList *pa=ha->next,*pb,*s,*tc;
   hc=(LinkList *)malloc(sizeof(LinkList));
   tc=hc;
   while (pa!=NULL)
   {
	   pb=hb->next;
	   while (pb!=NULL && pb->data<pa->data)  
		   pb=pb->next; 
	   if (!(pb!=NULL && pb->data==pa->data))		//��pa���ֵ����B��
	   {
		   s=(LinkList *)malloc(sizeof(LinkList));	//���ƽ��
		   s->data=pa->data;
		   tc->next=s;tc=s;
	   }
	   pa=pa->next;
   }
   tc->next=NULL;
}
void main()
{
	LinkList *ha,*hb,*hc;
	ElemType a[]={'c','a','e','h'};
	ElemType b[]={'f','h','b','g','d','a'};
	CreateListR(ha,a,4);
	CreateListR(hb,b,6);
	printf("ԭ �� ��A:");DispList(ha);
	printf("ԭ �� ��B:");DispList(hb);
	Sort(ha);
	Sort(hb);
	printf("���򼯺�A:");DispList(ha);
	printf("���򼯺�B:");DispList(hb);
	Union(ha,hb,hc);
	printf("���ϵĲ�C:");DispList(hc);
	InterSect(ha,hb,hc);
	printf("���ϵĽ�C:");DispList(hc);
	Subs(ha,hb,hc);
	printf("���ϵĲ�C:");DispList(hc);
}

