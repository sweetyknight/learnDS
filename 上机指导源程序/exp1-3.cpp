//�ļ�����exp1-3.cpp
#include <stdio.h>
#include <string.h>
#define MAX 100					//�ַ�������󳤶�
int func(char s[])
{
	int flag=1;
	int i,j,slen=strlen(s);		//slenΪ�ַ���s�ĳ���
	for (i=0,j=slen-1;i<j;i++,j--)
		if (s[i]!=s[j])
		{	
			flag=0;
			break;
		}
	return(flag);
}
void main()
{
	char s[MAX];
	printf("����һ�ַ���:");
	scanf("%s",s);
	if (func(s)==1)
		printf("%s�ַ����ǻ���\n",s);
	else
		printf("%s�ַ������ǻ���\n",s);
}
