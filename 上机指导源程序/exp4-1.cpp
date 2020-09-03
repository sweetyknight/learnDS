//�ļ���:exp4-1.cpp
#include <stdio.h>
#define MaxSize 100 
typedef struct
{   char data[MaxSize]; 
    int length;
} SqString;
extern void StrAssign(SqString &str,char cstr[]);
extern void StrCopy(SqString &s,SqString t);
extern int StrEqual(SqString s,SqString t);
extern int StrLength(SqString s);
extern SqString Concat(SqString s,SqString t);
extern SqString SubStr(SqString s,int i,int j);
extern SqString InsStr(SqString s1,int i,SqString s2);
extern SqString DelStr(SqString s,int i,int j);
extern SqString RepStr(SqString s,int i,int j,SqString t);
extern void DispStr(SqString str);
void main()
{
	SqString s,s1,s2,s3,s4;
	printf("(1)������s�ʹ�s1\n");
	StrAssign(s,"abcdefghefghijklmn");
	StrAssign(s1,"xyz");
	printf("(2)�����s:");DispStr(s);
	printf("(3)��s�ĳ���:%d\n",StrLength(s));
	printf("(4)�ڴ�s�ĵ�9���ַ�λ�ò��봮s1��������s2\n");
	s2=InsStr(s,9,s1);
	printf("(5)�����s2:");DispStr(s2);
	printf("(6)ɾ����s��2���ַ���ʼ��5���ַ���������s2\n");
	s2=DelStr(s,2,3);
	printf("(7)�����s2:");DispStr(s2);
	printf("(8)����s��2���ַ���ʼ��5���ַ��滻�ɴ�s1��������s2\n");
	s2=RepStr(s,2,5,s1);
	printf("(9)�����s2:");DispStr(s2);
	printf("(10)��ȡ��s�ĵ�2���ַ���ʼ��10���ַ���������s3\n");
	s3=SubStr(s,2,10);
	printf("(11)�����s3:");DispStr(s3);
	printf("(12)����s1�ʹ�s2����������������s4\n");
	s4=Concat(s1,s2);
	printf("(13)�����s4:");DispStr(s4);
}