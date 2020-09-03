#include "sqstack.cpp"
#include <string.h>
int Match(char exp[],int n)
{
	int i=0;
	char e;
	SqStack *st;
	InitStack(st);
	while (i<n)
	{
		if (exp[i]=='(')		//��ǰ�ַ�Ϊ������,�����ջ
			Push(st,exp[i]);
		else if (exp[i]==')')	//��ǰ�ַ�Ϊ������
		{
			if (GetTop(st,e)==1)
			{
				if (e!='(') return(0);	//���Ų�ƥ��ʱ����0
				else Pop(st,e);			//��ջ��Ԫ�س�ջ
			}
			else return(0);	//ȡջԪ�������ʱ����0
		}
		i++;	//�������������ַ�
	}
	if (StackEmpty(st)==1) return(1);
	else return(0);
}
void main()
{
	char exp[]="(1+2*(5+3)/2)";
	if (Match(exp,strlen(exp))==1)
		printf("���ʽ%s�������\n",exp);
	else
		printf("���ʽ%s���Ų����\n",exp);
}