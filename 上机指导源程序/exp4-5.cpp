//�ļ���:exp4-5.cpp
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#define MaxSize 100
typedef struct
{	
	char data[MaxSize];
	int length;			//����
} SqString;
extern void StrAssign(SqString &,char []); //��algo4-1.cpp�ļ���
extern void DispStr(SqString);
SqString *MaxSubstr(SqString s)
{
	SqString *sp;	
	int index=0,length=0,length1,i=0,j,k;
	while (i<s.length) 
	{
		j=i+1;
		while (j<s.length) 
		{
			if (s.data[i]==s.data[j]) //��һ�Ӵ�,�����Ϊi,����Ϊlength1
			{
				length1=1;
				for(k=1;s.data[i+k]==s.data[j+k];k++)
					length1++;
				if (length1>length)    //���ϴ󳤶��߸���index��length
				{
					index=i;
					length=length1;
				}
				j+=length1;
			}
			else
				j++;
		}
		i++;                                 //����ɨ���i�ַ�֮����ַ�
	}
	sp=(SqString *)malloc(sizeof(SqString));
	sp->length=length;
	for (i=0;i<length;i++)
		sp->data[i]=s.data[index+i];
	return sp;
}
void main()
{
	char str[MaxSize];
	SqString s,*sp;
	printf("���봮:");
	gets(str);
	StrAssign(s,str);			//������s
	sp=MaxSubstr(s);
	printf("����ظ��Ӵ�:\n");
	printf("  ԭ��:        ");
	DispStr(s);
	printf("  ��ظ��Ӵ�:");	//�����ظ��Ӵ�
	DispStr(*sp);
}
