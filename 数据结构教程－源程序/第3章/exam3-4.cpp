#include "sqstack.cpp"
int symmetry(ElemType str[])
{
	int i;
	ElemType e;
	SqStack *st;
	InitStack(st);
	for (i=0;str[i]!='\0';i++)	//��������Ԫ�ؽ�ջ
		Push(st,str[i]);
	for (i=0;str[i]!='\0';i++)
	{
		Pop(st,e);			//��ջԪ��e
		if (str[i]!=e)		//��e�뵱ǰ��Ԫ�ز�ͬ���ǶԳƴ�
			return(0);
	}
	return(1);
}
void main()
{
	ElemType str[]="1234321";
	if (symmetry(str)==1)
		printf("%s�ǶԳƴ�\n",str);
	else
		printf("%s���ǶԳƴ�\n",str);
}