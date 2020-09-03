//�ļ���:exp9-3.cpp
#include <stdio.h>
#define MAXL 100					//�����������¼����
#define MAXI 20						//�������������󳤶�
typedef int KeyType;
typedef char InfoType[10];
typedef struct 
{	
	KeyType key;                	//KeyTypeΪ�ؼ��ֵ���������
    InfoType data;              	//��������
} NodeType;
typedef NodeType SeqList[MAXL];		//˳�������
typedef struct 
{	
	KeyType key;					//KeyTypeΪ�ؼ��ֵ�����
	int link;						//ָ��ֿ����ʼ�±�
} IdxType;
typedef IdxType IDX[MAXI];			//����������

int IdxSearch(IDX I,int m,SeqList R,int n,KeyType k)	//�ֿ�����㷨
{
	int low=0,high=m-1,mid,i,count1=0,count2=0;
	int b=n/m;            	//bΪÿ��ļ�¼����
	printf("���ֲ���\n");
	while (low<=high)    	//���������н��ж��ֲ���,�ҵ���λ�ô����low��
	{	
		mid=(low+high)/2;
		printf("    ��%d�β���:��[%d,%d]�в��ҵ�Ԫ��R[%d]:%d\n",count1+1,low,high,mid,R[mid].key);
	    if (I[mid].key>=k)	
			high=mid-1;
	    else 
			low=mid+1;
		count1++;			//�ۼ����������еıȽϴ���
	}
	if (low<m)             	//���������в��ҳɹ���,�������Ա��н���˳�����
	{	
		printf("�Ƚ�%d��,�ڵ�%d���в���Ԫ��%d\n",count1,low,k);
		i=I[low].link;
		printf("˳�����:\n    ");
		while (i<=I[low].link+b-1 && R[i].key!=k)
		{ 
			i++;count2++; 
			printf("%d ",R[i].key);
		}			//count2�ۼ���˳����Ӧ���еıȽϴ���
	    printf("\n");
		printf("�Ƚ�%d��,��˳����в���Ԫ��%d\n",count2,k);
		if (i<=I[low].link+b-1) 
			return i;
	    else 
			return -1;
	}
	return -1;
}
void main()
{
	SeqList R;
	KeyType k=46;
	IDX I;
	int a[]={8,14,6,9,10,22,34,18,19,31,40,38,54,66,46,71,78,68,80,85,100,94,88,96,87},i;
	for (i=0;i<25;i++)				//����˳���
		R[i].key=a[i];
	I[0].key=14;I[0].link=0;
	I[1].key=34;I[1].link=4;
	I[2].key=66;I[2].link=10;
	I[3].key=85;I[3].link=15;
	I[4].key=100;I[4].link=20;
	printf("\n");
	if ((i=IdxSearch(I,5,R,25,k))!=-1)
		printf("Ԫ��%d��λ����%d\n",k,i);
	else
		printf("Ԫ��%d���ڱ���\n",k);
	printf("\n");
}
