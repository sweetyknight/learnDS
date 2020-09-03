//�ļ���:exp3-2.cpp
#include <stdio.h>
#include <malloc.h>
typedef char ElemType;
typedef struct linknode
{
	ElemType data;				//������
	struct linknode *next;		//ָ����
} LiStack;
extern void InitStack(LiStack *&s);
extern void ClearStack(LiStack *&s);
extern int StackLength(LiStack *s);
extern int StackEmpty(LiStack *s);
extern void Push(LiStack *&s,ElemType e);
extern int Pop(LiStack *&s,ElemType &e);
extern int GetTop(LiStack *s,ElemType &e);
extern void DispStack(LiStack *s);
void main()
{
	ElemType e;
	LiStack *s;
	printf("(1)��ʼ����ջs\n");
	InitStack(s);
	printf("(2)��ջΪ%s\n",(StackEmpty(s)?"��":"�ǿ�"));
	printf("(3)���ν���ջԪ��a,b,c,d,e\n");
	Push(s,'a');
	Push(s,'b');
	Push(s,'c');
	Push(s,'d');
	Push(s,'e');
	printf("(4)��ջΪ%s\n",(StackEmpty(s)?"��":"�ǿ�"));
	printf("(5)��ջ����:%d\n",StackLength(s));
	printf("(6)����ջ������ջ��Ԫ��:");DispStack(s);
	printf("(7)����ջ����:");
	while (!StackEmpty(s))
	{	Pop(s,e);
		printf("%c ",e);
	}
	printf("\n");
	printf("(8)��ջΪ%s\n",(StackEmpty(s)?"��":"�ǿ�"));
	printf("(9)�ͷ���ջ\n");
	ClearStack(s);
}
