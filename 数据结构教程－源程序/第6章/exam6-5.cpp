#include <stdio.h>
#include <math.h>
const int N=20;		//���ʺ����
int q[N];			//��Żʺ���ʺ����ڵ��к�
int cont=0;			//��Ž����
void print(int n)	//���һ����
{
	int i;
	cont++;
	printf("  ��%d����:",cont);
	for (i=1;i<=n;i++)
		printf("%d ",q[i]);
	printf("\n");
}
int find(int i,int k)  //���Ե�k�е�i�����ܷ�ڷŻʺ�
{
	int j;
	j=1;
	while (j<k)			//j=1��k-1���ѷ����˻ʺ����
	{	
		if ((q[j]==i)  	//��j�лʺ��Ƿ���i����
			|| (abs(q[j]-i)==abs(j-k)))	//λ��(q[j],j)��(i,k)�Ƿ�ͬ�Խ���
			return 0;
		j++;
	}
	return 1;
}
void place(int k,int n)			//��k���ʺ�ŵ���k����
{
	if (k>n) 					//���лʺ���ý���
		print(n);
	else
		for (int i=1;i<=n;i++)	//�ڵ�k�������ÿһ��λ��
			if (find(i,k))  
			{
				q[k]=i;place(k+1,n);
			}
}
void main()
{
	place(1,4);	//���4�ʺ�����
}