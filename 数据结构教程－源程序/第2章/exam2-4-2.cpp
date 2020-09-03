#include "sqlist.cpp"   //���ｫ�������ַ��ͱ�ʾ
void move2(SqList *&L)
{
	int i=0,j=L->length-1;
	ElemType pivot=L->data[0];	//��data[0]Ϊ��׼
	while (i!=j)  				//��˳������˽������м�ɨ��,ֱ��i=jΪֹ
	{	
		while (j>i && L->data[j]>pivot) 
			j--;  				//��������ɨ��,��һ���ؼ���С��pivot��data[j]
		L->data[i]=L->data[j];//�ҵ�������data[j],����data[i]��
		while (i<j && L->data[i]<pivot) 
			i++;				//��������ɨ��,��һ���ؼ��ִ���pivot�ļ�¼data[i]
		L->data[j]=L->data[i];//�ҵ�������data[i],����data[j]��
	}
	L->data[i]=pivot;
}
void main()
{
	SqList *L;
	InitList(L);
	//����L={'3','5','6',1','4','2','7','9','8','0'}
	ListInsert(L,1,'3');
	ListInsert(L,2,'5');
	ListInsert(L,3,'6');
	ListInsert(L,4,'1');
	ListInsert(L,5,'4');
	ListInsert(L,6,'2');
	ListInsert(L,7,'7');
	ListInsert(L,8,'9');
	ListInsert(L,9,'8');
	ListInsert(L,10,'0');
	printf("L:");DispList(L);
	printf("ִ���ƶ�����\n");
	move2(L);
	printf("L:");DispList(L);
	DestroyList(L);
}
