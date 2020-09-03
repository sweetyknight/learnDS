//�ļ���:exp5-5.cpp
#include <stdio.h>
#include <malloc.h>
typedef char ElemType;
typedef struct lnode  
{	int tag;				//������ͱ�ʶ
   	union 
	{	
		ElemType data;
        struct lnode *sublist;
	}val;
    struct lnode *link;		//ָ����һ��Ԫ��
} GLNode;
GLNode *CreatGL(char *&s)	//�ɴ�s����һ�������
{	
	GLNode *h;
	char ch;
	ch=*s++;                               	//ȡһ��ɨ���ַ�
	if (ch!='\0')                       	//��δ�����ж�
	{	
		h=(GLNode *)malloc(sizeof(GLNode));	//����һ���½��
        if (ch=='(')                   		//��ǰ�ַ�Ϊ������ʱ
		{	
			h->tag=1;                   	//�½����Ϊ��ͷ���
            h->val.sublist=CreatGL(s);   	//�ݹ鹹���ӱ�������ͷ���
		}
       	else if (ch==')') 
			h=NULL;           				//����')'�ַ�,�ӱ�Ϊ��
       	else
		{	
			h->tag=0;                   	//�½����Ϊԭ�ӽ��
            h->val.data=ch;
		}
	}
    else h=NULL;                          	//������,�ӱ�Ϊ��
    ch=*s++;                             	//ȡ��һ��ɨ���ַ�
    if (h!=NULL)                         	//��δ�����ж�
       	if (ch==',')                     	//��ǰ�ַ�Ϊ','
           	h->link=CreatGL(s);         	//�ݹ鹹������ӱ�
       	else                               	//������
           	h->link=NULL;                	//���������һ��Ԫ��
    return h;                              	//���ع����ָ��
}
int GLLength(GLNode *g)    	//������g�ĳ���
{
	int n=0;
	g=g->val.sublist;		//gָ������ĵ�һ��Ԫ��
    while (g!=NULL) 
	{	
		n++;
        g=g->link;
	}
    return n;
}
int GLDepth(GLNode *g) 		//���ͷ���Ĺ����g�����
{
   	int max=0,dep;
	if (g->tag==0)
		return 0;
	g=g->val.sublist;				//gָ���һ��Ԫ��
	if  (g==NULL)					//Ϊ�ձ�ʱ����1
		return 1;
	while (g!=NULL)     			//�������е�ÿһ��Ԫ��
	{	
		if (g->tag==1)   			//Ԫ��Ϊ�ӱ�����
		{	
			dep=GLDepth(g);			//�ݹ��������ӱ�����
            if (dep>max) max=dep;	//maxΪͬһ����������ӱ�����ȵ����ֵ
		}
        g=g->link;  				//ʹgָ����һ��Ԫ��
	}
    return(max+1);    				//���ر�����
}
void DispGL(GLNode *g)  //��������g
{
	if (g!=NULL)                       				//��Ϊ���ж�
	{	
		if (g->tag==1)               				//Ϊ����ʱ
		{
			printf("(");                 			//���'('
            if (g->val.sublist==NULL) printf("");  	//������ӱ�
            else DispGL(g->val.sublist);  			//�ݹ�����ӱ�
		}
        else printf("%c", g->val.data);      		//Ϊԭ��ʱ���Ԫ��ֵ
        if (g->tag==1) printf(")");               	//Ϊ����ʱ���')'
        if (g->link!=NULL) 
		{	
			printf(",");
            DispGL(g->link);             			//�ݹ���������������
		}
	}
}
void main()
{
	GLNode *g;
	char *str="(b,(b,a,a),((a,b),c))";
	g=CreatGL(str);
	printf(" �����g:");DispGL(g);printf("\n");
	printf(" �����g�ĳ���:%d\n",GLLength(g));
	printf(" �����g�����:%d\n",GLDepth(g));
	printf("\n");
}

