//�ļ���:exp10-9.cpp
#include <stdio.h>
#include <string.h>
#define MaxL 50
typedef struct node 
{
	int start,length;
} RecType;
int StringComp(char S[],RecType A[],int s1,RecType temp)
{
	char str1[MaxL],str2[MaxL];		//MaxL��һ������,ָ�������ַ�������
    int i,j;
	for (j=0,i=A[s1].start;i<A[s1].start+A[s1].length;i++,j++)
		str1[j]=S[i];				//����s1���ַ������Ƶ�str1��
    str1[j]='\0';					//�ַ���ĩβ��'\0'
	for (j=0,i=temp.start;i<temp.start+temp.length;i++,j++)
		str2[j]=S[i];				//��temp��ָ���ַ������Ƶ�str2��
    str2[j]='\0';					//�ַ���ĩβ��'\0'
	return strcmp(str1,str2);		//���ñ�׼�ַ����ȽϺ������ؽ��
}
void QuickSort(char S[],RecType A[],int low,int high)
{
	int i,j;
	RecType temp;
	i=low;j=high;
	if (low<high) 
	{
		temp=A[low];
		while (i!=j)
		{
			while (j>i && StringComp(S,A,j,temp)>0) j--;
			if (i<j) 
			{
				A[i]=A[j];i++;
			}
			while (i<j && StringComp(S,A,i,temp)<0) i++;
			if (i<j) 
			{
				A[j]=A[i];j--;
			}
		}
		A[i]=temp;
		QuickSort(S,A,low,i-1);
		QuickSort(S,A,i+1,high);
	}
}
void main()
{
	int i,j,n=6;
	char S[]={"whileifif-elsedo-whileforcase"};
	RecType A[]={{0,5},{5,2},{7,7},{14,8},{22,3},{25,4}};
	printf("����ǰ���ַ���:\n");
	for (i=0;i<n;i++)
	{
		printf("  ");
		for (j=A[i].start;j<A[i].start+A[i].length;j++)
			printf("%c",S[j]);
		printf("\n");
	}
	printf("\n");
	QuickSort(S,A,0,n-1);
	printf("�������ַ���:\n");
	for (i=0;i<n;i++)
	{
		printf("  ");
		for (j=A[i].start;j<A[i].start+A[i].length;j++)
			printf("%c",S[j]);
		printf("\n");
	}
}
