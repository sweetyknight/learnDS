//�ļ���:excise2.cpp
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define MAXNAME 7			//��ʶ���е�����ַ�����
#define MAXPRIORITY 6		//������������ȼ�
#define MAXTOKEN 100		//���ı�ʶ������
#define MAXSTACK 100		//ջ��С
#define MAXSTRING 101		//���ʽ�������ַ�����
#define HASHSIZE 101		//��ϣ��Ĵ�С
#define LASTOPERAND 17		//���һ�����������±�
typedef double Value_type;
typedef enum kind_tag {UNARYOP,BINARYOP,OPERAND,LEFTPAREN,RIGHTPAREN,ENDEXPR} Kind_type;
typedef struct
{
	char name[MAXNAME];		//��ʶ����
	Kind_type kind;			//��ʶ������
	union 
	{	
		int pri;			//���ȼ�
		Value_type val;		//ֵ
	} info;
} Token_type;
Token_type lexicon[MAXTOKEN]={	//��ʶ����
	{"#",ENDEXPR},			//0:������
	{"(",LEFTPAREN},		//1:������
	{")",RIGHTPAREN},		//2:������
	{"~",UNARYOP,6},		//3:����
	{"abs",UNARYOP,6},		//4:�����ֵ
	{"sqrt",UNARYOP,6},		//5:��ƽ����
	{"exp",UNARYOP,6},		//6:��ex
	{"ln",UNARYOP,6},		//7:��log2
	{"log10",UNARYOP,6},	//8:��log10
	{"sin",UNARYOP,6},		//9:��sin
	{"cos",UNARYOP,6},		//10:��cos
	{"tanh",UNARYOP,6},		//11:��tanh
	{"+",BINARYOP,4},		//12:��Ԫ"+"
	{"-",BINARYOP,4},		//13:��Ԫ"-"
	{"*",BINARYOP,5},		//14:��Ԫ"*"
	{"/",BINARYOP,5},		//15:��Ԫ"/"
	{"%",BINARYOP,5},		//16:��Ԫ"%"
	{"^",BINARYOP,6}};		//17:��Ԫ"^"
int hashtable[MAXTOKEN];	//��ϣ��
int infix[MAXTOKEN];		//�����׺���ʽ
int postfix[MAXTOKEN];		//��ź�׺���ʽ
int inlength;				//ɨ��infix���ʽ��ָ��
int postlength;				//ɨ��postfix���ʽ��ָ��
int parencount;				//���ʽ�����Ÿ���
int tokencount;				//lexicon[]�еı�ʶ������
int Hash(char *name)		//�ڹ�ϣ���в���name���±�
{
	int h=name[0] % HASHSIZE;
	while (1)
	{
		if (hashtable[h]==-1)
			break;
		else if (strcmp(lexicon[hashtable[h]].name,name)==0)
			break;		//name�ڹ�ϣ����
		else
		{
			if (name[1]=='\0')
				h+=31;
			else
				h+=name[1];
			h%=HASHSIZE;	//����һ��λ��
		}
	}
	return abs(h);
}
void MakeHashTable()	//�����ϣ��
{
	int i;
	for (i=0;i<HASHSIZE;i++)		//�ó�ֵ
		hashtable[i]=-1;
	for (i=1;i<=LASTOPERAND;i++)
		hashtable[Hash(lexicon[i].name)]=i;
}
Kind_type Kind(int h)	//����lexicon[h]������
{
	return(lexicon[h].kind);
}
int Priority(int h)		//����lexicon[h]�����ȼ�
{
	return(lexicon[h].info.pri);
}
int Leading()	//�ж��Ƿ�Ϊ��ͷλ��
{
	int k;
	if (inlength<=-1)
		return 1;
	else
		return (k=Kind(infix[inlength]))==LEFTPAREN || k==UNARYOP || k==BINARYOP;
}
void PutToken(int h)	//��lexicon�е��±�h��ӵ�infix��
{
	inlength++;
	infix[inlength]=h;
}
void PutToken1(int h)	//��lexicon�е��±�h��ӵ�postfix��
{
	postlength++;
	postfix[postlength]=h;
}
int ExtractWord(char str[],int pos,char *word)	//��str[]��pos����ȡһ������
{
	int i;
	char *pw=word;
	for (i=pos;isalpha(str[i]) || isdigit(str[i]);i++) //��ǰ�ַ�Ϊ��ĸ������ʱ
		*pw++=tolower(str[i]);		//ת��ΪСд��ĸ����ӵ�word��
	*pw='\0';
	return i;
}
int FindWord(char str[],int pos)	//�ҵ�һ������,������Ӧ�Ĵ���
{
	int h;
	char word[MAXTOKEN];
	pos=ExtractWord(str,pos,word);
	h=hashtable[Hash(word)];
	if (h!=-1)	//�ڹ�ϣ�����ҵ�ʱ
	{
		if (Leading()==1)
		{
			if (Kind(h)==BINARYOP)
			{
				printf("��Ԫ�����λ�ò���ȷ\n");
				return -1;
			}
			else
				PutToken(h);
		}
		else
		{
			if (Kind(h)!=BINARYOP)
			{
				printf("ӦΪ��Ԫ�����\n");
				return -1;
			}
			else
				PutToken(h);
		}
		return pos;
	}
	else	//h==-1ʱ
	{
		printf("  >>����ȷ�ı�ʶ��\n");
		return -1;
	}
}
int FindNumber(char str[],int pos)	//�ҵ�һ��������,������Ӧ�Ĵ���
{
	if (Leading()==0)
	{
		printf("����λ�ò���ȷ\n");
		return -1;
	}
	else	//����ǰʶ��Ĳ�������ӵ�lexicon����
	{
		lexicon[++tokencount].kind=OPERAND;
		lexicon[tokencount].info.val=atof(&str[pos]);	//���ò�������ת������ֵ
		strcpy(lexicon[tokencount].name,"number");
		PutToken(tokencount);							//��lexicon�ж�Ӧ���±���ӵ�infix��
		for (;isdigit(str[pos]) || str[pos]=='.';pos++); //ɨ����ò�����
		return pos;
	}
}
int FindSymbol(char str[],int pos)	//�ҵ�һ�����Ż�����,������Ӧ�Ĵ���
{
	int h,k;
	char word[MAXTOKEN];
	word[0]=str[pos];
	word[1]='\0';
	pos++;
	if ((h=hashtable[Hash(word)])==-1)	//��lexicon���Ҳ����÷���
	{
		printf("���ʽ�д��ڲ���ʶ��ķ���\n");
		return -1;
	}
	else if (Leading()==1)				//��֮ǰ��"("��һԪ���Ԫ�����
	{
		if (Kind(h)==RIGHTPAREN)		//��ǰ����Ϊ")"
		{
			printf("��ӦΪ������\n");
			return -1;
		}
		else if (Kind(h)!=BINARYOP)		//��ǰ���Ų�Ϊ��Ԫ�����,������ӵ�infix��
			PutToken(h);
		else		//��ǰ����Ϊ��Ԫ�����
		{
			if (strcmp(word,"+")==0);		//Ϊ"+"ʱ,Ӧ��һԪ"+",�����κ��¼�
			else if (strcmp(word,"-")==0)	//Ϊ"-"ʱ,Ӧ��һԪ"-",��"~"��ӵ�infix��
				PutToken(hashtable[Hash("~")]);
			else		//������Ԫ�����Ϊ�Ƿ�
			{
				printf("  >>��Ԫ���������ȷ\n");
				return -1;
			}
		}
	}
	else	//Leading()=0ʱ
	{
		if (Kind(h)==BINARYOP || Kind(h)==RIGHTPAREN) //����Ԫ�������")"��ӵ�infix��
			PutToken(h);
		else
		{
			printf("��Ԫ���������ȷ\n");
			return -1;
		}
	}
	if ((k=Kind(h))==LEFTPAREN)
		parencount++;
	else if (k==RIGHTPAREN)
		if (--parencount<0)		//�������Ų�ƥ��
		{
			printf("̫���������\n");
			return -1;
		}
	return pos;
}
void GetToken(int &h)	//��infix��ȡһ����ʶ��
{
	inlength++;
	h=infix[inlength];
}
void GetToken1(int &h)	//��postfix��ȡһ����ʶ��
{
	postlength++;
	h=postfix[postlength];
}
void Translate()  //����׺���ʽinfixת���ɺ�׺���ʽpostfix
{
	int St[MAXSTACK];int top=-1;		//����ջ��ջָ��
	int h,h1;
	Kind_type type;
	postlength=-1;
	inlength=-1;
	int endright;	//ȡ1��0.1:��ʾһ��������������(�迼�����ȼ�)
	do
	{
		GetToken(h);
		switch(type=Kind(h))
		{
		case OPERAND:	//Ϊ�����,ֱ����ӵ�postfix��
			PutToken1(h);
			break;
		case LEFTPAREN:	//Ϊ"(",�����ջ
			top++;
			St[top]=h;
			break;
		case RIGHTPAREN:	//Ϊ")",��ջ�������ӵ�postfix��ֱ������"("
			h=St[top];top--;
			while (top>-1 && Kind(h)!=LEFTPAREN)
			{
				PutToken1(h);
				h=St[top];top--;
			}
			break;
		case UNARYOP:		//ΪһԪ���Ԫ�����
		case BINARYOP:
			endright=0;
			do
			{
				if (top==-1)	//ջ��
					endright=1;
				else if (Kind(St[top])==LEFTPAREN)
					endright=1;
				else if (Priority(St[top])<Priority(h))
					endright=1;
				else if (Priority(St[top])==Priority(h) && Priority(h)==MAXPRIORITY)
					endright=1;
				else
				{
					h1=h;		//����ǰh���ڵ�ǰ������������ĺ���
					endright=0;
					h=St[top];top--;
					PutToken1(h);
					h=h1;
				}
			} while (endright==0);
			top++;St[top]=h;
			break;
		case ENDEXPR:
			while (top>-1)
			{
				h=St[top];top--;
				PutToken1(h);
			}
			break;
		}
	} while (type!=ENDEXPR);
	PutToken1(0);	//��postfix�����ENDEXPR
}
int ProcessExpress(char *instring) //��ԭ���ʽ����Ԥ����
{
	int len,pos;
	inlength=-1;
	parencount=0;
	tokencount=LASTOPERAND;
	len=strlen(instring);
	instring[len]='\0';
	for (pos=0;pos<len;)
	{
		if (instring[pos]==' ')				//���Կո��ַ�
			pos++;
		else if (isalpha(instring[pos]))	//������ĸ
			pos=FindWord(instring,pos);
		else if (isdigit(instring[pos]) || instring[pos]=='.') //��������
			pos=FindNumber(instring,pos);
		else			//�������
			pos=FindSymbol(instring,pos);
		if (pos==-1)
			return 0;
	}
	if (parencount!=0)
		printf("�������Ų�ƥ��\n");
	PutToken(0);	//��infix�����ENDEXPR
	return 1;
}
void DispInfix()	//�����׺���ʽ
{
	int i;
	printf(" ��׺���ʽ(�任ǰ):");
	for (i=0;i<=inlength;i++)
	{
		if (strcmp(lexicon[infix[i]].name,"number")==0)
			printf("%g ",lexicon[infix[i]].info.val);
		else
			printf("%s ",lexicon[infix[i]].name);
	}
	printf("\n");
	printf(" ��׺���ʽ(�任��):");
	for (i=0;i<=inlength;i++)
		printf("%d ",infix[i]);
	printf("\n");
}
void DispPostfix()	//�����׺���ʽ
{
	int i;
	printf(" ��׺���ʽ(�任ǰ):");
	for (i=0;i<=postlength;i++)
	{
		if (strcmp(lexicon[postfix[i]].name,"number")==0)
			printf("%g ",lexicon[postfix[i]].info.val);
		else
			printf("%s ",lexicon[postfix[i]].name);
	}
	printf("\n");
	printf(" ��׺���ʽ(�任��):");
	for (i=0;i<=postlength;i++)
		printf("%d ",postfix[i]);
	printf("\n");
}
Value_type DoBinary(int h,Value_type x,Value_type y)  //���ж�Ԫ����
{
	switch(h)
	{
	case 12:	//��
		return(x+y);
	case 13:	//��
		return(x-y);
	case 14:	//��
		return(x*y);
	case 15:	//��
		if (y!=(Value_type)0)
			return(x/y);
		else
		{
			printf("  >>�������\n");
			break;
		}
	case 16:	//%
		if (y!=(Value_type)0)
			return(fmod(x,y));
		else
		{
			printf("  >>�������\n");
			break;
		}
	case 17:	//^
		return(pow(x,y));
	default:	//����
		printf("  >>%d����Ч�Ķ�Ԫ�����\n",h);
		break;
	}
}
Value_type DoUnary(int h,Value_type x) //����һԪ����
{
	switch(h)
	{
	case 3:	//-
		return(-x);
	case 4:
		return(abs(x));
	case 5:
		if (x>=0)
			return(sqrt(x));
		else
		{
			printf("  >>�������ܿ�ƽ��\n");
			break;
		}
	case 6:
		return(exp(x));
	case 7:
		if (x>0)
			return(log(x));
		else
		{
			printf("  >>����������ln\n");
			break;
		}
	case 8:
		if (x>0)
			return(log10(x));
		else
		{
			printf("  >>����������log10\n");
			break;
		}
	case 9:
		return(sin(x));
	case 10:
		return(cos(x));
	case 11:
		return(tanh(x));
	}
}
Value_type GetValue(int h)  //��lexicon[h]��ȡֵ
{
	if (Kind(h)!=OPERAND)
		printf("  >>����һ��������\n");
	else
		return(lexicon[h].info.val);
}
Value_type EvaluatePostfix()   //�����׺���ʽֵ
{
	Kind_type type;
	int h;
	Value_type x,y;
	double St[MAXSTACK];
	int top=-1;
	postlength=-1;
	do
	{
		GetToken1(h);
		switch(type=Kind(h))
		{
		case OPERAND:
			top++;
			St[top]=GetValue(h);
			break;
		case UNARYOP:
			x=St[top];
			top--;
			top++;
			St[top]=DoUnary(h,x);
			break;
		case BINARYOP:
			y=St[top];top--;
			x=St[top];top--;
			top++;
			St[top]=DoBinary(h,x,y);
			break;
		case ENDEXPR:
			x=St[top];top--;
			if (top>-1)  //ջ����,����
				printf("  >>����ȷ�ı��ʽ\n");
			break;
		}
	} while (type!=ENDEXPR);
	return(x);
}
void main()
{
	char instring[MAXSTRING];
	MakeHashTable();
	printf("\n");
	printf(" ����һ����׺���ʽ:");
	gets(instring);
	while (strlen(instring)!=0)
	{
		if (ProcessExpress(instring))
		{
			DispInfix();
			Translate();
			DispPostfix();
			printf(" ������:%g\n\n",EvaluatePostfix());
		}
		printf(" ����һ����׺���ʽ:");
		gets(instring);
	}
	printf("\n");
}
