#include "btree.cpp"
int Like(BTNode *b1,BTNode *b2)
//t1��t2���ö���������ʱ����1�����򷵻�0
{
    int like1,like2;
    if (b1==NULL && b2==NULL) 
		return 1;
    else if (b1==NULL || b2==NULL) 
		return 0;
    else
    {	like1=Like(b1->lchild,b2->lchild);
        	like2=Like(b1->rchild,b2->rchild);
        	return (like1 & like2);		//����like1��like2����
    }
}
void main()
{
	int l;
	BTNode *b1,*b2;
	CreateBTNode(b1,"A(B(D(,G)),C(E,F))");
	printf("b1:");DispBTNode(b1);printf("\n");
	CreateBTNode(b2,"a(b(d(,g)),c(e,f))");
	printf("b2:");DispBTNode(b2);printf("\n");
	l=Like(b1,b2);
	if (l==1)
		printf("b1��b2����\n");
	else
		printf("b1��b2������\n");
}
