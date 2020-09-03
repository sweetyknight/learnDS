//�ļ���:algo3-1.cpp
#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
typedef char ElemType;
typedef struct 
{
	ElemType data[MaxSize];
	int top;		//ջ��ָ��
} SqStack;
void InitStack(SqStack *&s)
{
	s=(SqStack *)malloc(sizeof(SqStack));
	s->top=-1;
}
void ClearStack(SqStack *&s)
{
	free(s);
}
int StackLength(SqStack *s)
{
	return(s->top+1);
}
int StackEmpty(SqStack *s)
{
	return(s->top==-1);
}
int Push(SqStack *&s,ElemType e)
{
	if (s->top==MaxSize-1)
		return 0;
	s->top++;
	s->data[s->top]=e;
	return 1;
}
int Pop(SqStack *&s,ElemType &e)
{
	if (s->top==-1)
		return 0;
	e=s->data[s->top];
	s->top--;
	return 1;
}
int GetTop(SqStack *s,ElemType &e)
{
	if (s->top==-1)
		return 0;
	e=s->data[s->top];
	return 1;
}
void DispStack(SqStack *s)
{
	int i;
	for (i=s->top;i>=0;i--)
		printf("%c ",s->data[i]);
	printf("\n");
}
