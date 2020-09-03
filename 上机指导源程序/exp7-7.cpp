//�ļ���:exp7-7.cpp
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#define MaxSize 100
typedef char ElemType;
typedef struct node
{
	ElemType data;				//����Ԫ��
	struct node *lchild;		//ָ������
	struct node *rchild;		//ָ���Һ���
} BTNode;
extern void DispBTNode(BTNode *b);	 //��algo7-1.cpp�ļ���
BTNode *CRTree(char s[],int i,int j)
{
	BTNode *p;
	int k,plus=0,posi;
	if (i==j)
	{
		p=(BTNode *)malloc(sizeof(BTNode));
		p->data=s[i];
		p->lchild=NULL;
		p->rchild=NULL;
		return p;
	}
	//����Ϊi!=j�����
	for (k=i;k<=j;k++)
		if (s[k]=='+' || s[k]=='-')
		{
			plus++;
			posi=k;              //���һ��+��-��λ��
		}
	if (plus==0)                 //û��+��-�����
		for (k=i;k<=j;k++)
			if (s[k]=='*' || s[k]=='/')
			{
				plus++;
				posi=k;
			}
   if (plus!=0)
   {
		p=(BTNode *)malloc(sizeof(BTNode));
		p->data=s[posi];
		p->lchild=CRTree(s,i,posi-1);
		p->rchild=CRTree(s,posi+1,j);
		return p;
	}
   else       //��û���κ������������NULL
	   return NULL;
}
double Comp(BTNode *b)
{
	double v1,v2;
	if (b==NULL) return 0;
	if (b->lchild==NULL && b->rchild==NULL)
		return b->data-'0';    //Ҷ�ӽ��ֱ�ӷ��ؽ��ֵ
	v1=Comp(b->lchild);
	v2=Comp(b->rchild);
	switch(b->data)
	{
	case '+':
		return v1+v2;
	case '-':
		return v1-v2;
	case '*':
		return v1*v2;
	case '/':
		if (v2!=0)
			return v1/v2;
		else
			abort();

	}
}
void main()
{
	BTNode *b;
	char s[MaxSize]="1+2*3-4/5";
	printf("\n");
    printf(" �������ʽ%s\n",s);
	b=CRTree(s,0,strlen(s)-1);
	printf(" ��Ӧ������:");
	DispBTNode(b);
	printf("\n ���ʽ��ֵ:%g\n",Comp(b));
}
