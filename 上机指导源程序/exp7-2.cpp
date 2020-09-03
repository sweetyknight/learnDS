//�ļ���:exp7-2.cpp
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
extern void CreateBTNode(BTNode *&b,char *str);
extern void DispBTNode(BTNode *b);
void PreOrder(BTNode *b)  		//��������ĵݹ��㷨
{
	if (b!=NULL)  
	{	
		printf("%c ",b->data);	//���ʸ����
		PreOrder(b->lchild);	//�ݹ����������
		PreOrder(b->rchild);	//�ݹ����������
	}
}
void PreOrder1(BTNode *b)
{
	BTNode *St[MaxSize],*p;
    int top=-1;
    if (b!=NULL) 
    {
        top++;						//�������ջ
        St[top]=b;
        while (top>-1)				//ջ��Ϊ��ʱѭ��
        {
            p=St[top];				//��ջ�����ʸý��
            top--;
            printf("%c ",p->data);
            if (p->rchild!=NULL)	//�Һ�����ջ
			{
               top++;
               St[top]=p->rchild;
			}
            if (p->lchild!=NULL)	//������ջ
			{
               top++;
               St[top]=p->lchild;
			}
		}
		printf("\n");
	}
}
void InOrder(BTNode *b)   		//��������ĵݹ��㷨
{
	if (b!=NULL)  
	{	
		InOrder(b->lchild);		//�ݹ����������
		printf("%c ",b->data);	//���ʸ����
		InOrder(b->rchild);		//�ݹ����������
	}
}
void InOrder1(BTNode *b)
{
	BTNode *St[MaxSize],*p;
	int top=-1;
	if (b!=NULL)
	{
		p=b;
		while (top>-1 || p!=NULL)
		{
			while (p!=NULL)
			{
				top++;
				St[top]=p;
				p=p->lchild;
			}
			if (top>-1)
			{
				p=St[top];
				top--;
				printf("%c ",p->data);
				p=p->rchild;
			}
		}
		printf("\n");
	}
}
void PostOrder(BTNode *b) 		//��������ĵݹ��㷨
{
	if (b!=NULL)  
	{	
		PostOrder(b->lchild);	//�ݹ����������
		PostOrder(b->rchild);	//�ݹ����������
		printf("%c ",b->data);	//���ʸ����
	}
}
void PostOrder1(BTNode *b)
{
	BTNode *St[MaxSize];
	BTNode *p;
	int flag,top=-1;						//ջָ���ó�ֵ
	if (b!=NULL)
	{
		do
		{
			while (b!=NULL)					//��t������������ջ
			{
				top++;
				St[top]=b;
				b=b->lchild;
			}
			p=NULL;							//pָ��ǰ����ǰһ���ѷ��ʵĽ��
			flag=1;	
			while (top!=-1 && flag)
			{
				b=St[top];					//ȡ����ǰ��ջ��Ԫ��
				if (b->rchild==p)			//�����������ڻ��ѱ�����,����֮
				{
					printf("%c ",b->data);	//����*b���
					top--;
					p=b;					//pָ���򱻷��ʵĽ��
				}
				else
				{
					b=b->rchild;			//tָ��������
					flag=0;	
				}
			}
		} while (top!=-1);
		printf("\n");
	} 
}
void TravLevel(BTNode *b)
{
	BTNode *Qu[MaxSize];				//����ѭ������
	int front,rear;						//������׺Ͷ�βָ��
	front=rear=0;						//�ö���Ϊ�ն���
    if (b!=NULL) 
		printf("%c ",b->data);
    rear++;								//���ָ��������
	Qu[rear]=b;
    while (rear!=front)					//���в�Ϊ��
    {
		front=(front+1)%MaxSize;
		b=Qu[front];					//��ͷ������
		if (b->lchild!=NULL)			//�������,�������
		{
			printf("%c ",b->lchild->data);
			rear=(rear+1)%MaxSize;
			Qu[rear]=b->lchild;
		}
		if (b->rchild!=NULL)			//����Һ���,�������
		{
			printf("%c ",b->rchild->data);
			rear=(rear+1)%MaxSize;
			Qu[rear]=b->rchild;
		}
	} 
	printf("\n");
}
void main()
{
	BTNode *b;
	CreateBTNode(b,"A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))"); 
	printf(" ������b:");DispBTNode(b);printf("\n\n");
	printf(" ��α�������:");
	TravLevel(b);
	printf("\n");
	printf(" �����������:\n");
	printf("     �ݹ��㷨:");PreOrder(b);printf("\n");
	printf("   �ǵݹ��㷨:");PreOrder1(b);printf("\n");
	printf(" �����������:\n");
	printf("     �ݹ��㷨:");InOrder(b);printf("\n");
	printf("   �ǵݹ��㷨:");InOrder1(b);printf("\n");
	printf(" �����������:\n");
	printf("     �ݹ��㷨:");PostOrder(b);printf("\n");
	printf("   �ǵݹ��㷨:");PostOrder1(b);printf("\n");
}
 