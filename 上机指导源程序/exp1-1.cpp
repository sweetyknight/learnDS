//�ļ�����exp1-1.cpp
#include <stdio.h>
#include <math.h>
int prime(int x)					//�ж�������x�Ƿ�Ϊ����
{
	int i;
	for (i=2;i<(int)sqrt(x);i++)
		if (x%i==0) return 0;		//��x��������,���˳�������0
	return 1;
}
void main()
{
	int n,i,j=0;					//j�����ۼ���������
	printf("n:");
	scanf("%d",&n);
	printf("С�ڵ���%d������:\n",n);
	if (n>2)
	{	printf("%4d",2);
		j++;
	}
	for (i=3;i<=n;i+=2)
		if (prime(i)==1)
		{	printf("%4d",i);
			if (j!=0 && ++j%10==0)	//ÿ�������ʾ10������
				printf("\n");
		}
	printf("\n");
}
