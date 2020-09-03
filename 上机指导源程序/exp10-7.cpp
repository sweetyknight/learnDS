//�ļ���:exp10-7.cpp
#include <stdio.h>
#include <malloc.h>
#define MAXE 20			//���Ա������Ԫ�ظ���
typedef int KeyType;
typedef char InfoType[10];
typedef struct       	//��¼����
{	
	KeyType key;   		//�ؼ�����
    InfoType data; 		//����������,����ΪInfoType
} RecType;
void Merge(RecType R[],int low,int mid,int high) 
//�����������R[low..mid]��R[mid+1..high]�鲢Ϊһ�������R[low..high]��
{
	RecType *R1;
	int i=low,j=mid+1,k=0; //k��R1���±�,i��j�ֱ�Ϊ��1��2�ε��±�
	R1=(RecType *)malloc((high-low+1)*sizeof(RecType));  //��̬����ռ�
	while (i<=mid && j<=high)     	//�ڵ�1�κ͵�2�ξ�δɨ����ʱѭ��
		if (R[i].key<=R[j].key)    	//����1���еļ�¼����R1��
		{	
			R1[k]=R[i];
			i++;k++; 
		}
        else                       	//����2���еļ�¼����R1��
		{	
			R1[k]=R[j];
			j++;k++; 
		}
    while (i<=mid)          	   	//����1�����²��ָ��Ƶ�R1
	{   	
		R1[k]=R[i];
		i++;k++; 
	}
    while (j<=high)                	//����2�����²��ָ��Ƶ�R1
	{	
		R1[k]=R[j];
		j++;k++;  
	}
    for (k=0,i=low;i<=high;k++,i++) //��R1���ƻ�R��
	    R[i]=R1[k];
} 
void MergePass(RecType R[],int length,int n)	//ʵ��һ�˹鲢
{
	int i;
	for (i=0;i+2*length-1<n;i=i+2*length) 	//�鲢length�����������ӱ�
		Merge(R,i,i+length-1,i+2*length-1);
    if (i+length-1<n)                		//���������ӱ�,���߳���С��length
		Merge(R,i,i+length-1,n-1);  		//�鲢�������ӱ�
}
void MergeSort(RecType R[],int n)  //��·�鲢�����㷨
{
	int length,k,i=1;						//i�����ۼƹ鲢������
	for (length=1;length<n;length=2*length)
	{
		MergePass(R,length,n);
		printf("   ��%d�˹鲢  ",i++);		//���ÿһ�˵�������
		for (k=0;k<n;k++)
			printf("%4d",R[k].key);
		printf("\n");
	}
}
void main()
{
	int i,k,n=8;
	KeyType a[]={18,2,20,34,12,32,6,16};
	RecType R[MAXE];
	for (i=0;i<n;i++)
		R[i].key=a[i];
	printf("\n");
	printf("  ��ʼ�ؼ���  ");			//�����ʼ�ؼ�������
	for (k=0;k<n;k++)
		printf("%4d",R[k].key);
	printf("\n");
	MergeSort(R,n);
	printf("  �����    ");			//�����ʼ�ؼ�������
	for (k=0;k<n;k++)
		printf("%4d",R[k].key);
	printf("\n\n");
}
