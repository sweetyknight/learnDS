//�ļ���:exp9-4.cpp
#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
typedef int KeyType;					//����ؼ�������
typedef char InfoType;
typedef struct node               		//��¼����
{	
	KeyType key;                  		//�ؼ�����
    InfoType data;               		//����������
    struct node *lchild,*rchild;		//���Һ���ָ��
} BSTNode;
int path[MaxSize];						//ȫ�ֱ���,���ڴ��·��
void DispBST(BSTNode *b);				//����˵��
int InsertBST(BSTNode *&p,KeyType k)	//����*pΪ������BST�в���һ���ؼ���Ϊk�Ľ��
{
   	if (p==NULL)						//ԭ��Ϊ��, �²���ļ�¼Ϊ�����
	{
		p=(BSTNode *)malloc(sizeof(BSTNode));
		p->key=k;p->lchild=p->rchild=NULL;
		return 1;
	}
	else if (k==p->key) 
		return 0;
	else if (k<p->key) 
		return InsertBST(p->lchild,k);	//���뵽*p����������
	else  
		return InsertBST(p->rchild,k);  //���뵽*p����������
}
BSTNode *CreatBST(KeyType A[],int n)				
//������A�еĹؼ��ֽ���һ�ö���������
{
  	BSTNode *bt=NULL;         			//��ʼʱbtΪ����
   	int i=0;
   	while (i<n) 
		if (InsertBST(bt,A[i])==1)		//��A[i]�������������T��
		{
			printf("    ��%d��,����%d:",i+1,A[i]);
			DispBST(bt);printf("\n");
			i++;
		}
    return bt;               			//���ؽ����Ķ����������ĸ�ָ��
}
void Delete1(BSTNode *p,BSTNode *&r)
//����ɾ*p�������������ʱ��ɾ������
{
	BSTNode *q;
	if (r->rchild!=NULL)
		Delete1(p,r->rchild);	//�ݹ��������½��
	else						//�ҵ��������½��*r
	{
		p->key=r->key;			//��*r�Ĺؼ���ֵ����*p
		q=r;					
		r=r->lchild;			//��*r��˫�׽����Һ��ӽ���Ϊ*r�����ӽ��
		free(q);				//�ͷ�ԭ*r�Ŀռ�
	}
}
void Delete(BSTNode *&p)
//�Ӷ�����������ɾ��*p���
{
	BSTNode *q;
	if (p->rchild==NULL)		//*p���û�������������
	{
		q=p;p=p->lchild;free(q);
	}
	else if (p->lchild==NULL)	//*p���û�������������
	{
		q=p;p=p->rchild;free(q);
	}
	else Delete1(p,p->lchild);	//*p���������������������������
}
int DeleteBST(BSTNode *&bt,KeyType k)	
//��bt��ɾ���ؼ���Ϊk�Ľ��
{
	if (bt==NULL) return 0;		//����ɾ��ʧ��
	else 
	{
		if (k<bt->key) 
			return DeleteBST(bt->lchild,k);		//�ݹ�����������ɾ���ؼ���Ϊk�Ľ��
		else if (k>bt->key) 
			return DeleteBST(bt->rchild,k);		//�ݹ�����������ɾ���ؼ���Ϊk�Ľ��
		else									//k=bt->key�����
		{
			Delete(bt);		//����Delete(bt)����ɾ��*bt���
			return 1;
		}
	}
}
void SearchBST1(BSTNode *bt,KeyType k,KeyType path[],int i)	
//�Էǵݹ鷽ʽ����Ӹ���㵽���ҵ��Ľ���·��
{ 
	int j;
	if (bt==NULL)
		return;
	else if (k==bt->key)	//�ҵ��˽��
	{
		path[i+1]=bt->key;	//�����·��
		for (j=0;j<=i+1;j++)
			printf("%3d",path[j]);
		printf("\n");
	}
	else
	{
		path[i+1]=bt->key;
		if (k<bt->key)
			SearchBST1(bt->lchild,k,path,i+1);  //���������еݹ����
		else
			SearchBST1(bt->rchild,k,path,i+1);  //���������еݹ����
	}
}
int SearchBST2(BSTNode *bt,KeyType k)	
//�Եݹ鷽ʽ����Ӹ���㵽���ҵ��Ľ���·��
{ 
	if (bt==NULL)
		return 0;
	else if (k==bt->key)
	{
		printf("%3d",bt->key);
		return 1;
	}
	else if (k<bt->key)
		SearchBST2(bt->lchild,k);  //���������еݹ����
	else
		SearchBST2(bt->rchild,k);  //���������еݹ����
	printf("%3d",bt->key);
}

void DispBST(BSTNode *bt)	
//�����ű�ʾ���������������bt
{
	if (bt!=NULL)
	{
		printf("%d",bt->key);
		if (bt->lchild!=NULL || bt->rchild!=NULL)
		{
			printf("(");
			DispBST(bt->lchild);
			if (bt->rchild!=NULL) printf(",");
			DispBST(bt->rchild);
			printf(")");
		}
	}
}
KeyType predt=-32767; //predtΪȫ�ֱ���,���浱ǰ�������ǰ����ֵ,��ֵΪ-��
int JudgeBST(BSTNode *bt)	//�ж�bt�Ƿ�ΪBST
{
	int b1,b2;
	if (bt==NULL)
		return 1;
	else 
	{
		b1=JudgeBST(bt->lchild);
		if (b1==0 || predt>=bt->key)
			return 0;
		predt=bt->key;
		b2=JudgeBST(bt->rchild);
		return b2;
	}
}
void main()
{
	BSTNode *bt;
	KeyType k=6;
	int a[]={4,9,0,1,8,6,3,5,2,7},n=10;
	printf(" ����һ��BST��:");
	printf("\n");
	bt=CreatBST(a,n);
	printf(" BST:");DispBST(bt);printf("\n");
	printf(" bt%s\n",(JudgeBST(bt)?"��һ��BST":"����һ��BST"));
	printf("\n");
	printf(" ����%d�ؼ���(�ݹ�):",k);SearchBST1(bt,k,path,-1);
	printf(" ����%d�ؼ���(�ǵݹ�):",k);SearchBST2(bt,k);
	printf("\n ɾ������:\n");
	printf("   ԭBST:");DispBST(bt);printf("\n");
	printf("   ɾ�����4:");
	DeleteBST(bt,4);
	DispBST(bt);printf("\n");
	printf("   ɾ�����5:");
	DeleteBST(bt,5);
	DispBST(bt);
	printf("\n\n");
}
