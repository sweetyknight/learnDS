//�ļ���:algo2-5.cpp
#include <stdio.h>
#include <malloc.h>
typedef char ElemType;
typedef struct DNode		//����˫����������
{
	ElemType data;
	struct DNode *prior;	//ָ��ǰ�����
	struct DNode *next;		//ָ���̽��
} DLinkList;
void InitList(DLinkList *&L)
{
	L=(DLinkList *)malloc(sizeof(DLinkList));  	//����ͷ���
	L->prior=L->next=L;
}
void DestroyList(DLinkList *&L)
{
	DLinkList *p=L,*q=p->next;
	while (q!=L)
	{
		free(p);
		p=q;
		q=p->next;
	}
	free(p);
}
int ListEmpty(DLinkList *L)
{
	return(L->next==L);
}
int ListLength(DLinkList *L)
{
	DLinkList *p=L;int i=0;
	while (p->next!=L)
	{
		i++;
		p=p->next;
	}
	return(i);
}
void DispList(DLinkList *L)
{
	DLinkList *p=L->next;
	while (p!=L)
	{
		printf("%c",p->data);
		p=p->next;
	}
	printf("\n");
}
int GetElem(DLinkList *L,int i,ElemType &e)
{
	int j=0;
	DLinkList *p;
	if (L->next!=L)		//˫����Ϊ�ձ�ʱ
	{
		if (i==1)
		{
			e=L->next->data;
			return 1;
		}
		else			//i��Ϊ1ʱ
		{
			p=L->next;
			while (j<i-1 && p!=L)
			{
				j++;
				p=p->next;
			}
			if (p==L)
				return 0;
			else
			{
				e=p->data;
				return 1;
			}
		}
	}
	else				//˫����Ϊ�ձ�ʱ
		return 0;
}
int LocateElem(DLinkList *L,ElemType e)
{
	int n=1;
	DLinkList *p=L->next;
	while (p!=NULL && p->data!=e)
	{
		n++;
		p=p->next;
	}
	if (p==NULL)
		return(0);
	else
		return(n);
}
int ListInsert(DLinkList *&L,int i,ElemType e)
{
	int j=0;
	DLinkList *p=L,*s;
	if (p->next==L)					//ԭ˫����Ϊ�ձ�ʱ
	{	
		s=(DLinkList *)malloc(sizeof(DLinkList));	//�����½��*s
		s->data=e;
		p->next=s;s->next=p;
		p->prior=s;s->prior=p;
		return 1;
	}
	else if (i==1)					//ԭ˫����Ϊ�ձ�i=1ʱ
	{
		s=(DLinkList *)malloc(sizeof(DLinkList));	//�����½��*s
		s->data=e;
		s->next=p->next;p->next=s;	//��*s���뵽*p֮��
		s->next->prior=s;s->prior=p;
		return 1;
	}
	else
	{	
		p=L->next;
		while (j<i-2 && p!=L)
		{	j++;
			p=p->next;
		}
		if (p==L)				//δ�ҵ���i-1�����
			return 0;
		else					//�ҵ���i-1�����*p
		{
			s=(DLinkList *)malloc(sizeof(DLinkList));	//�����½��*s
			s->data=e;	
			s->next=p->next;	//��*s���뵽*p֮��
			if (p->next!=NULL) p->next->prior=s;
			s->prior=p;
			p->next=s;
			return 1;
		}
	}
}
int ListDelete(DLinkList *&L,int i,ElemType &e)
{
	int j=0;
	DLinkList *p=L,*q;
	if (p->next!=L)					//ԭ˫����Ϊ�ձ�ʱ
	{	
		if (i==1)					//i==1ʱ
		{	
			q=L->next;				//ɾ����1�����
			e=q->data;
			L->next=q->next;
			q->next->prior=L;
			free(q);
			return 1;
		}
		else						//i��Ϊ1ʱ
		{	
			p=L->next;
			while (j<i-2 && p!=NULL)		
			{
				j++;
				p=p->next;
			}
			if (p==NULL)				//δ�ҵ���i-1�����
				return 0;
			else						//�ҵ���i-1�����*p
			{
				q=p->next;				//qָ��Ҫɾ���Ľ��
				if (q==NULL) return 0;	//�����ڵ�i�����
				e=q->data;
				p->next=q->next;		//�ӵ�������ɾ��*q���
				if (p->next!=NULL) p->next->prior=p;
				free(q);				//�ͷ�*q���
				return 1;
			}
		}
	}
	else return 0;	//ԭ˫����Ϊ�ձ�ʱ
}
