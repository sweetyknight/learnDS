//�ļ���:exp4-2.cpp
#include <stdio.h>
#include <malloc.h>
typedef struct snode 
{
    char data;
    struct snode *next;
} LiString;
extern void StrAssign(LiString *&str,char cstr[]);
extern void StrCopy(LiString *&s,LiString *t);
extern int StrEqual(LiString *s,LiString *t);
extern int StrLength(LiString *s);
extern LiString *Concat(LiString *s,LiString *t);
extern LiString *SubStr(LiString *s,int i,int j);
extern LiString *InsStr(LiString *s1,int i,LiString *s2);
extern LiString *DelStr(LiString *s,int i,int j);
extern LiString *RepStr(LiString *s,int i,int j,LiString *t);
extern void DispStr(LiString *str);
void main()
{
	LiString *s,*s1,*s2,*s3,*s4;
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