//�ļ���:exp4-4.cpp
#include <stdio.h>
#include <string.h>
#define MaxSize 100
typedef struct
{	char data[MaxSize];
	int length;			//����
} SqString;
extern void StrAssign(SqString &,char []);	//��algo4-1.cpp�ļ���
extern void DispStr(SqString);
SqString A,B;								//ȫ�ִ�
SqString EnCrypt(SqString p)
{
	int i=0,j;
	SqString q;
	while (i<p.length) 
	{
		for (j=0;p.data[i]!=A.data[j];j++);	
		if (j>=p.length)			//��A����δ�ҵ�p.data[i]��ĸ
			q.data[i]=p.data[i];
		else						//��A�����ҵ�p.data[i]��ĸ
			q.data[i]=B.data[j];
		i++;
	}
	q.length=p.length;
	return q;
}
SqString UnEncrypt(SqString q)
{
	int i=0,j;
	SqString p;
	while (i<q.length) 
	{	
		for (j=0;q.data[i]!=B.data[j];j++);
		if (j>=q.length)			//��B����δ�ҵ�q.data[i]��ĸ
			p.data[i]=q.data[i];
		else					//��B�����ҵ�q.data[i]��ĸ
			p.data[i]=A.data[j];
		i++;
	}
	p.length=q.length;
	return p;
}
void main()
{
	SqString p,q;
	int ok=1;
	StrAssign(A,"abcdefghijklmnopqrstuvwxyz");	//����A��
	StrAssign(B,"ngzqtcobmuhelkpdawxfyivrsj");	//����B��
	char str[MaxSize];
	printf("\n");
	printf("����ԭ�Ĵ�:");
	gets(str);									//��ȡ�û������ԭ�Ĵ�
	StrAssign(p,str);							//����p��
	printf("���ܽ�������:\n");
	printf("  ԭ�Ĵ�:");DispStr(p);
	q=EnCrypt(p);								//p�����ܲ���q��
	printf("  ���ܴ�:");DispStr(q);
    	p=UnEncrypt(q);							//q�����ܲ���p��
	printf("  ���ܴ�:");DispStr(p);
	printf("\n");
}
