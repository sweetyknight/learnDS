//�ļ���:exp3-1.cpp
#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
typedef char ElemType;
typedef struct 
{
	ElemType data[MaxSize];
	int top;		//ջ��ָ��
} SqStack;
extern void InitStack(SqStack *&s);
extern void ClearStack(SqStack *&s);
extern int StackLength(SqStack *s);
extern int StackEmpty(SqStack *s);
extern int Push(SqStack *&s,ElemType e);
extern int Pop(SqStack *&s,ElemType &e);
extern int GetTop(SqStack *s,ElemType &e);
extern void DispStack(SqStack *s);
void main()
{
	ElemType e;
	SqStack *s;
	printf("(1)��ʼ��ջs\n");
	InitStack(s);
	printf("(2)ջΪ%s\n",(StackEmpty(s)?"��":"�ǿ�"));
	printf("(3)���ν�ջԪ��a,b,c,d,e\n");
	Push(s,'a');
	Push(s,'b');
	Push(s,'c');
	Push(s,'d');
	Push(s,'e');
	printf("(4)ջΪ%s\n",(StackEmpty(s)?"��":"�ǿ�"));
	printf("(5)ջ����:%d\n",StackLength(s));
	printf("(6)��ջ����ջ��Ԫ��:");DispStack(s);
	printf("(7)��ջ����:");
	while (!StackEmpty(s))
	{
		Pop(s,e);
		printf("%c ",e);
	}
	printf("\n");
	printf("(8)ջΪ%s\n",(StackEmpty(s)?"��":"�ǿ�"));
	printf("(9)�ͷ�ջ\n");
	ClearStack(s);
}
