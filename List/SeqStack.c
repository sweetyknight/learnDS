#include <stdio.h>
#include<stdlib.h>
#include <stdbool.h>

typedef int ElemType;
typedef struct 
{	
	ElemType *data;
    int maxSize;
	int top;			
} SqStack;

void InitStack(SqStack *s,int sz)
{
    s->maxSize=sz;
    s->top=-1;
	s->data=(ElemType *)malloc(sizeof(ElemType)*s->maxSize);
} 

void ClearStack(SqStack *s)
{
	free(s->data);
}

bool IsFull(SqStack *s)
{
	return(s->top==s->maxSize-1);
}

bool IsEmpty(SqStack *s)
{
	return (s->top==-1);
}

bool Push(SqStack *s,ElemType e)
{
	if (s->top==s->maxSize-1)
		return false;
	s->top++;
	s->data[s->top]=e;
	return true;
}

ElemType Pop(SqStack *s)
{
	if (s->top==-1)	{
        printf("stack is empty!\n");
        exit(1);
    }	
	return s->data[(s->top)--];
} 

bool GetTop(SqStack *s,ElemType *e)
{
	if (s->top==-1) 		
		return false;
	*e=s->data[s->top];
	return true;
}

void DispStack(SqStack *s)
{
	int i;
	for (i=s->top;i>=0;i--)
		printf("%d ",s->data[i]);
	printf("\n");
}

int main(){
    ElemType e;
    SqStack *s;
    InitStack(s,6);
    if(IsEmpty(s)){
        printf("stack is empty.\n");
    }
    Push(s,1);
    Push(s,2);
    Push(s,3);
    Push(s,4);
    Push(s,5);
    Push(s,6);
    if(IsFull(s)){
        printf("stack is full.\n");
    }
    DispStack(s);
    if(GetTop(s,&e)){
        printf("stack top is %d\n",e);
    }
    e=Pop(s);
    printf("pop elem of stack: %d\n",e);
    ClearStack(s);
    DispStack(s);
    printf("s->data = %d")
}