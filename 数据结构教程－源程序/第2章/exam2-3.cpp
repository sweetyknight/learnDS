#include "sqlist.cpp"
void delelem(SqList *&L,ElemType x,ElemType y)
{
	int i=0,j=0;	//iɨ��˳���,j�ۼƲ�����������Ԫ��
	while (i<L->length)
	{
		if (!(L->data[i]>=x && L->data[i]<=y))
		{
			L->data[j]=L->data[i];
			j++;
		}
		i++;
	}
	L->length=j;
}
void main()
{
	ElemType a[]={'1','2','2','1','0','2','4','2','3','1'};
	ElemType x='1',y='3';
	SqList *L;
	InitList(L);
	CreateList(L,a,10);
	printf("L:");DispList(L);
	printf("ɾ����%c��%c��Ԫ��\n",x,y);
	delelem(L,x,y);
	printf("L:");DispList(L);
}