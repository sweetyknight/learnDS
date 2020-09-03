//�ļ���:exp7-3.cpp
#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
typedef char ElemType;
typedef struct node
{
	ElemType data;				//����Ԫ��
	struct node *lchild;		//ָ������
	struct node *rchild;		//ָ���Һ���
} BTNode;
extern void CreateBTNode(BTNode *&b,char *str);  //��algo7-1.cpp�ļ���
extern void DispBTNode(BTNode *b);
void AllPath(BTNode *b)
{
	struct snode
	{
	   BTNode *node;			//��ŵ�ǰ���ָ��
	   int parent;				//���˫�׽���ڶ����е�λ��
	} Qu[MaxSize];				//����˳�����
	int front,rear,p;			//�����ͷ�Ͷ�βָ��
    front=rear=-1;				//�ö���Ϊ�ն���
	rear++;
    Qu[rear].node=b;			//�����ָ��������
	Qu[rear].parent=-1;			//�����û��˫�׽��
    while (front<rear)			//���в�Ϊ��
    {
		front++;
		b=Qu[front].node;		//��ͷ������
		if (b->lchild==NULL && b->rchild==NULL)	//*bΪҶ�ӽ��
		{
			printf("   %c�������·��:",b->data);
			p=front;
			while (Qu[p].parent!=-1)
			{
				printf("%c ",Qu[p].node->data);
				p=Qu[p].parent;
			}
			printf("%c\n",Qu[p].node->data);
		}
		if (b->lchild!=NULL)		//���������
		{
			rear++;
			Qu[rear].node=b->lchild;
			Qu[rear].parent=front;
		}
		if (b->rchild!=NULL)		//�Һ��������
		{
			rear++;
			Qu[rear].node=b->rchild;
			Qu[rear].parent=front;
		}
	} 
}
void AllPath1(BTNode *b,ElemType path[],int pathlen)
{
	int i;
	if (b!=NULL)
	{
		if (b->lchild==NULL && b->rchild==NULL)	//*bΪҶ�ӽ��
		{
			printf("   %c�������·��: %c ",b->data,b->data);
			for (i=pathlen-1;i>=0;i--)
				printf("%c ",path[i]);
			printf("\n");
		}
		else
		{
			path[pathlen]=b->data;				//����ǰ������·����
			pathlen++;							//·��������1
			AllPath1(b->lchild,path,pathlen);	//�ݹ�ɨ��������
			AllPath1(b->rchild,path,pathlen);	//�ݹ�ɨ��������
			pathlen--;							//�ָ�����
		}
	}
}
void LongPath(BTNode *b,ElemType path[],int pathlen,ElemType longpath[],int &longpathlen)
{
	int i;
	if (b==NULL)
	{
		if (pathlen>longpathlen)	//����ǰ·������,��·��������longpath��
		{
			for (i=pathlen-1;i>=0;i--)
				longpath[i]=path[i];
			longpathlen=pathlen;
		}
	}
	else	
	{
		path[pathlen]=b->data;					//����ǰ������·����
		pathlen++;								//·��������1
		LongPath(b->lchild,path,pathlen,longpath,longpathlen);	//�ݹ�ɨ��������
		LongPath(b->rchild,path,pathlen,longpath,longpathlen);	//�ݹ�ɨ��������
		pathlen--;								//�ָ�����
	}
}
void DispLeaf(BTNode *b)
{
    	if (b!=NULL) 
	{	if (b->lchild==NULL && b->rchild==NULL) 
			printf("%c ",b->data);
    	else
    	{	
			DispLeaf(b->lchild);
			DispLeaf(b->rchild);
		}
	}
}
void main()
{
	BTNode *b;
	ElemType path[MaxSize],longpath[MaxSize];
	int i,longpathlen=0;
	CreateBTNode(b,"A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))"); 
	printf("\n ������b:");DispBTNode(b);printf("\n\n");
	printf(" b��Ҷ�ӽ��:");DispLeaf(b);printf("\n\n");
	printf(" AllPath:\n");AllPath(b);printf("\n");
	printf(" AllPath1:\n");AllPath1(b,path,0);printf("\n");
	LongPath(b,path,0,longpath,longpathlen);
	printf(" ��һ���·������:%d\n",longpathlen);
	printf(" ��һ���·��:");
	for (i=longpathlen;i>=0;i--)
		printf("%c ",longpath[i]);
	printf("\n\n");
}