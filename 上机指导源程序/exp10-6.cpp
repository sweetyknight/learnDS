//�ļ���:exp10-6.cpp
#include <stdio.h>
#define MAXE 20			//���Ա������Ԫ�ظ���
typedef int KeyType;
typedef char InfoType[10];
typedef struct       	//��¼����
{	
	KeyType key;   		//�ؼ�����
    InfoType data; 		//����������,����ΪInfoType
} RecType;
void DispHeap(RecType R[],int i,int n)	//�����ű�ʾ����������Ķ�
{
	if (i<=n)
		printf("%d",R[i].key);			//��������
	if (2*i<=n || 2*i+1<n)
	{
		printf("(");
		if (2*i<=n)
			DispHeap(R,2*i,n);			//�ݹ�������������
		printf(",");
		if (2*i+1<=n)
			DispHeap(R,2*i+1,n);		//�ݹ�������������
		printf(")");
	}
}
void Sift(RecType R[],int low,int high)	//������
{
	int i=low,j=2*i;     					//R[j]��R[i]������
	RecType temp=R[i];
	while (j<=high) 
	{	
		if (j<high && R[j].key<R[j+1].key) 	//���Һ��ӽϴ�,��jָ���Һ���
			j++;    						//��Ϊ2i+1
	    if (temp.key<R[j].key) 
		{	
			R[i]=R[j];              		//��R[j]������˫�׽��λ����
		    i=j;                    		//�޸�i��jֵ,�Ա��������ɸѡ
		    j=2*i;
		}
	    else break;                 		//ɸѡ����
	}
    R[i]=temp;                      		//��ɸѡ����ֵ��������λ��
}
void HeapSort(RecType R[],int n)	//��R[1]��R[n]Ԫ��ʵ�ֶ�����
{
	int i;
	RecType temp;
	for (i=n/2;i>=1;i--)  	//ѭ��������ʼ��
		Sift(R,i,n); 
	printf("  ��ʼ��:");DispHeap(R,1,n);printf("\n");		//�����ʼ��
	for (i=n;i>=2;i--)   	//����n-1��ѭ��,���������
	{  	
		printf("  ����%d��%d,���%d\n",R[i].key,R[1].key,R[1].key);
		temp=R[1];        	//����һ��Ԫ��ͬ��ǰ������R[1]�Ի�
        R[1]=R[i];
        R[i]=temp;
        Sift(R,1,i-1);     	//ɸѡR[1]���,�õ�i-1�����Ķ�
		printf("  ɸѡ�����õ���:");DispHeap(R,1,i-1);printf("\n");	//���ÿһ�˵�������
	}
}
void main()
{
	int i,k,n=10;
	KeyType a[]={6,8,7,9,0,1,3,2,4,5};
	RecType R[MAXE];
	for (i=1;i<=n;i++)
		R[i].key=a[i-1];
	printf("\n");
	printf("  ��ʼ�ؼ���  ");
	for (k=1;k<=n;k++)
		printf("%2d",R[k].key);
	printf("\n");
	for (i=n/2;i>=1;i--)  		//ѭ��������ʼ��
		Sift(R,i,n); 
	HeapSort(R,n);
	printf("  ���ս��    ");	//������ս��
	for (k=1;k<=n;k++)
		printf("%d ",R[k].key);
	printf("\n\n");
}
