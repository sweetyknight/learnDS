//�ļ�����exp1-2.cpp
#include <stdio.h>
int func(int num)
{
	int s=0;
   	do
   	{   	
		s+=num%10;
		num/=10;
   	} while(num);
   	return(s);
}
void main()
{
	int n;
	printf("\n");
   	printf("����һ������:");
   	scanf("%d",&n);
   	printf("��λ����֮��:%d\n",func(n));
	printf("\n");
}
