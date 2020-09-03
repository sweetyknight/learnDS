//�ļ���:exp9-2.cpp
#include <stdio.h>
#define MAXL 100					//�����������¼����
typedef int KeyType;
typedef char InfoType[10];
typedef struct 
{	
	KeyType key;                	//KeyTypeΪ�ؼ��ֵ���������
    InfoType data;              	//��������
} NodeType;
typedef NodeType SeqList[MAXL];				//˳�������
int BinSearch(SeqList R,int n,KeyType k)	//���ֲ����㷨
{
	int low=0,high=n-1,mid,count=0;
	while (low<=high) 
	{	
		mid=(low+high)/2;
		printf("��%d�β���:��[%d,%d]�в��ҵ�Ԫ��R[%d]:%d\n",++count,low,high,mid,R[mid].key);
		if (R[mid].key==k)   	//���ҳɹ�����
			return mid;
		if (R[mid].key>k)     	//������R[low..mid-1]�в���
			high=mid-1;
		else
			low=mid+1;       	//������R[mid+1..high]�в���
	}
	return -1;
}
void main()
{
	SeqList R;
	KeyType k=9;
	int a[]={1,2,3,4,5,6,7,8,9,10},i,n=10;
	for (i=0;i<n;i++)				//����˳���
		R[i].key=a[i];
	printf("\n");
	if ((i=BinSearch(R,n,k))!=-1)
		printf("Ԫ��%d��λ����%d\n",k,i);
	else
		printf("Ԫ��%d���ڱ���\n",k);
	printf("\n");
}
