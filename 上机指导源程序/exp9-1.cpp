//�ļ���:exp9-1.cpp
#include <stdio.h>
#define MAXL 100					//�����������¼����
typedef int KeyType;
typedef char InfoType[10];
typedef struct 
{	
	KeyType key;                		//KeyTypeΪ�ؼ��ֵ���������
    InfoType data;              		//��������
} NodeType;
typedef NodeType SeqList[MAXL];			 //˳�������
int SeqSearch(SeqList R,int n,KeyType k) //˳������㷨

{
    int i=0;
    while (i<n && R[i].key!=k) 
	{
		printf("%d ",R[i].key);
		i++;					//�ӱ�ͷ������
	}
    if (i>=n) 
		return -1;
    else 
	{
		printf("%d",R[i].key);
		return i;
	}
}
void main()
{
	SeqList R;
	int n=10;
	KeyType k=5;
	int a[]={3,6,2,10,1,8,5,7,4,9},i;
	for (i=0;i<n;i++)				//����˳���
		R[i].key=a[i];
	printf("\n");
	if ((i=SeqSearch(R,n,k))!=-1)
		printf("\nԪ��%d��λ����%d\n",k,i);
	else
		printf("\nԪ��%d���ڱ���\n",k);
	printf("\n");
}
