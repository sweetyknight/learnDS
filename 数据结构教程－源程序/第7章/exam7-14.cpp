#include "btree.cpp"
#define MaxSize 100
typedef char Elemtype;
typedef struct
{	
	ElemType data[MaxSize];	//��Ŷ��������ֵ,���пս����'#'��ʾ
	int n;					//���data�е�Ԫ�ظ���
} SqBTree;
BTNode *trans(SqBTree a,int i)
{
	BTNode *b;
	if (i>a.n)
		return(NULL);
	if (a.data[i]=='#')
		return(NULL);
	b=(BTNode *)malloc(sizeof(BTNode));
	b->data=a.data[i];
	b->lchild=trans(a,2*i);
	b->rchild=trans(a,2*i+1);
	return(b);
}
void main()
{
	int i,n=10;
	BTNode *b;
	SqBTree a;
	ElemType s[]="0ABCD#EF##G";
	for (i=0;i<=n;i++)
		a.data[i]=s[i];
	a.n=n;
	b=trans(a,1);
	printf("b:");DispBTNode(b);printf("\n");
}
