//�ļ���:exp6-3.cpp
#include <stdio.h>
#define N 100
int limitw;  							//���Ƶ�������
int totv;  								//ȫ����Ʒ���ܼ�
int maxv;
int option[N],cop[N];
struct
{
	int weight; 
	int value;
} a[N];
int n;     								//��Ʒ������
void find(int i,int tw,int tv)
{
	int k;
	if (tw+a[i].weight<=limitw) 
	{
		cop[i]=1;
		if (i<n-1)
			find(i+1,tw+a[i].weight,tv);
		else 
		{
			for (k=0;k<n;k++)
				option[k]=cop[k];
			maxv=tv;
		}
		cop[i]=0;
	}
	if (tv-a[i].value>maxv)
		if (i<n-1)
			find(i+1,tw,tv-a[i].value);
		else 
		{
			for (k=0;k<n;k++)
				option[k]=cop[k];
			maxv=tv-a[i].value;
		}
}
void main()
{
	int k,w,v;
	printf("��Ʒ����:");
	scanf("%d",&n);
	for (totv=0,k=0;k<n;k++) 
	{
		printf("  ��%d����Ʒ(����,��ֵ):",k+1);
		scanf("%d,%d",&w,&v);
		a[k].weight=w;
		a[k].value=v;
		totv+=v;
	}
	printf("�������ܳ��ܵ�������:");
	scanf("%d",&limitw);
	maxv=0;
	for (k=0;k<n;k++)
		cop[k]=0;
	find(0,0,totv);
	printf("���װ�����:\n");
	for (k=0;k<n;k++)
		if (option[k])
			printf("  ��%d����Ʒ\n",k+1);
	printf("�ܼ�ֵ=%d\n",maxv);
}
