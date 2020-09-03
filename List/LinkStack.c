#include <stdio.h>
#include<stdlib.h>
#include <stdbool.h>

typedef int ElemType;
typedef struct linknode
{	
	ElemType data;
	struct linknode *next;
} LinkStack;	

void InitStack(LinkStack *s)
{
	s->data=(ElemType *)malloc(sizeof(ElemType));
	s->next=NULL;
}

void ClearStack(LinkStack *s)
{
	LinkStack *p=s->next;
	while (p!=NULL)
	{	
		free(s);
		s=p;
		p=p->next;
	}
	free(s);	//sָ��β���,�ͷ���ռ�
}
int StackLength(LiStack *s)
{
	int i=0;
	LiStack *p;
	p=s->next;
	while (p!=NULL)
	{	
		i++;
		p=p->next;
	}
	return(i);
}
int StackEmpty(LiStack *s)
{
	return(s->next==NULL);
}
void Push(LiStack *&s,ElemType e)
{
	LiStack *p;
	p=(LiStack *)malloc(sizeof(LiStack));
	p->data=e;
	p->next=s->next;		//����*p�����Ϊ��һ�����ݽ��
	s->next=p;
}
int Pop(LiStack *&s,ElemType &e)
{
	LiStack *p;
	if (s->next==NULL)		//ջ�յ����
		return 0;
	p=s->next;				//pָ���һ�����ݽ��
	e=p->data;
	s->next=p->next;
	free(p);
	return 1;
}
int GetTop(LiStack *s,ElemType &e)
{
	if (s->next==NULL)		//ջ�յ����
		return 0;
	e=s->next->data;
	return 1;
}
void DispStack(LiStack *s)
{
	LiStack *p=s->next;
	while (p!=NULL)
	{	
		printf("%c ",p->data);
		p=p->next;
	}
	printf("\n");
}