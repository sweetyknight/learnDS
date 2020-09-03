//�ļ���:algo2-4.cpp
#include <stdio.h>
#include <malloc.h>
typedef char ElemType;
typedef struct LNode		//���嵥����������
{
	ElemType data;
    struct LNode *next;
} LinkList;
void InitList(LinkList *&L)
{
	L=(LinkList *)malloc(sizeof(LinkList));	//����ͷ���
	L->next=L;
}
void DestroyList(LinkList *&L)
{
	LinkList *p=L,*q=p->next;
	while (q!=L)
	{
		free(p);
		p=q;
		q=p->next;
	}
	free(p);
}
int ListEmpty(LinkList *L)
{
	return(L->next==L);
}
int ListLength(LinkList *L)
{
	LinkList *p=L;int i=0;
	while (p->next!=L)
	{
		i++;
		p=p->next;
	}
	return(i);
}
void DispList(LinkList *L)
{
	LinkList *p=L->next;
	while (p!=L)
	{
		printf("%c",p->data);
		p=p->next;
	}
	printf("\n");
}
int GetElem(LinkList *L,int i,ElemType &e)
{
	int j=0;
	LinkList *p;
	if (L->next!=L)		//������Ϊ�ձ�ʱ
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
	else				//������Ϊ�ձ�ʱ
		return 0;
}
int LocateElem(LinkList *L,ElemType e)
{
	LinkList *p=L->next;
	int n=1;
	while (p!=L && p->data!=e)
	{
		p=p->next;
		n++;
	}
	if (p==L)
		return(0);
	else
		return(n);
}
int ListInsert(LinkList *&L,int i,ElemType e)
{
	int j=0;
	LinkList *p=L,*s;
	if (p->next==L || i==1)		//ԭ������Ϊ�ձ��i==1ʱ
	{
		s=(LinkList *)malloc(sizeof(LinkList));	//�����½��*s
		s->data=e;								
		s->next=p->next;		//��*s���뵽*p֮��
		p->next=s;
		return 1;
	}
	else
	{
		p=L->next;
		while (j<i-2 && p!=L)
		{
			j++;
			p=p->next;
		}
		if (p==L)				//δ�ҵ���i-1�����
			return 0;
		else					//�ҵ���i-1�����*p
		{
			s=(LinkList *)malloc(sizeof(LinkList));	//�����½��*s
			s->data=e;								
			s->next=p->next;						//��*s���뵽*p֮��
			p->next=s;
			return 1;
		}
	}
}
int ListDelete(LinkList *&L,int i,ElemType &e)
{
	int j=0;
	LinkList *p=L,*q;
	if (p->next!=L)					//ԭ������Ϊ�ձ�ʱ
	{
		if (i==1)					//i==1ʱ
		{
			q=L->next;				//ɾ����1�����
			e=q->data;
			L->next=q->next;
			free(q);
			return 1;
		}
		else						//i��Ϊ1ʱ
		{
			p=L->next;
			while (j<i-2 && p!=L)
			{
				j++;
				p=p->next;
			}
			if (p==L)				//δ�ҵ���i-1�����
				return 0;
			else					//�ҵ���i-1�����*p
			{
				q=p->next;			//qָ��Ҫɾ���Ľ��
				e=q->data;
				p->next=q->next;	//�ӵ�������ɾ��*q���
				free(q);			//�ͷ�*q���
				return 1;
			}
		}
	}
	else return 0;
}
