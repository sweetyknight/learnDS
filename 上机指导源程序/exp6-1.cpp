//�ļ���:exp6-1.cpp
#include <stdio.h>
#include <stdlib.h>
const int N=20;      	//���ʺ����
int q[N];            	//��Ÿ��ʺ����ڵ��к�
int cont=0;          	//��Ž����
void print(int n)    	//���һ����
{
	cont++;
	int i;
	printf("  ��%d���⣺",cont);
	for (i=1;i<=n;i++)
		printf("%d ",q[i]);
	printf("\n");
}
int find(int i,int k) 	//���Ե�k�е�i�����ܷ�ڷŻʺ�
{
	int j;
	j=1;
	while (j<k)       	//j=1��k-1���ѷ����˻ʺ����
	{
	    if ((q[j]==i) || (abs(q[j]-i)==abs(j-k)))
            //��j�лʺ��Ƿ���i�л�(q[j],j)��(i,k)�Ƿ�ͬ�Խ���
		    return 0;
	    j++;
	}
	return 1;
}
void place(int k,int n) //��k���ʺ�ŵ���k����
{
	if (k>n) 
		print(n);         		//���лʺ���ý���
	else
		for (int i=1;i<=n;i++) 	//�ڵ�k�������ÿһ��λ��
		    if (find(i,k))  
			{
				q[k]=i;place(k+1,n);
     		}
}
void main()
{
	int n;     					//n���ʵ�ʻʺ����
	printf(" �ʺ�����(n<20) n=");
	scanf("%d",&n);
	if (n>20)
		printf("nֵ̫��,�������\n");
	else
	{
		printf(" %d�ʺ�����������£�\n",n);
		place(1,n);
		printf("\n");
    }
}
