//�ļ���:algo2-2.cpp
#include <stdio.h>
#include <malloc.h>
typedef char ElemType;
typedef struct LNode	//���嵥����������
{
	ElemType data;
    struct LNode *next;
} LinkList;
void InitList(LinkList *&L)
{
	L=(LinkList *)malloc(sizeof(LinkList));  	//����ͷ���
	L->next=NULL;
}
void DestroyList(LinkList *&L)
{
	LinkList *p=L,*q=p->next;
	while (q!=NULL)
	{
		free(p);
		p=q;
		q=p->next;
	}
	free(p);
}
int ListEmpty(LinkList *L)
{
	return(L->next==NULL);
}
int ListLength(LinkList *L)
{
	LinkList *p=L;int i=0;
	while (p->next!=NULL)
	{
		i++;
		p=p->next;
	}
	return(i);
}
void DispList(LinkList *L)
{
	LinkList *p=L->next;
	while (p!=NULL)
	{
		printf("%c",p->data);
		p=p->next;
	}
	printf("\n");
}
int GetElem(LinkList *L,int i,ElemType &e)
{
	int j=0;
	LinkList *p=L;
	while (j<i && p!=NULL)
	{
		j++;
		p=p->next;
	}
	if (p==NULL)
		return 0;
	else
	{
		e=p->data;
		return 1;
	}
}
int LocateElem(LinkList *L,ElemType e)
{
	LinkList *p=L->next;
	int n=1;
	while (p!=NULL && p->data!=e)
	{
		p=p->next;
		n++;
	}
	if (p==NULL)
		return(0);
	else
		return(n);
}
int ListInsert(LinkList *&L,int i,ElemType e)
{
	int j=0;
	LinkList *p=L,*s;
	while (j<i-1 && p!=NULL)
	{
		j++;
		p=p->next;
	}
	if (p==NULL)	//δ�ҵ���i-1�����
		return 0;
	else			//�ҵ���i-1�����*p
	{
		s=(LinkList *)malloc(sizeof(LinkList));	//�����½��*s
		s->data=e;								
		s->next=p->next;						//��*s���뵽*p֮��
		p->next=s;
		return 1;
	}
}
int ListDelete(LinkList *&L,int i,ElemType &e)
{
	int j=0;
	LinkList *p=L,*q;
	while (j<i-1 && p!=NULL)
	{
		j++;
		p=p->next;
	}
	if (p==NULL)				//δ�ҵ���i-1�����
		return 0;
	else						//�ҵ���i-1�����*p
	{
		q=p->next;				//qָ��Ҫɾ���Ľ��
		if (q==NULL) return 0;
		e=q->data;
		p->next=q->next;		//�ӵ�������ɾ��*q���
		free(q);				//�ͷ�*q���
		return 1;
	}
}
