//�ļ���:excise3.cpp
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MaxWidth 40
#define MaxSize 30
#define NAMEWIDTH 10
typedef struct fnode
{
	char father[NAMEWIDTH];	//��
	char wife[NAMEWIDTH];	//ĸ
	char son[NAMEWIDTH];	//��
} FamType;
typedef struct tnode
{
	char name[NAMEWIDTH];
	struct tnode *lchild,*rchild;
} BTree;		//����������
BTree *CreatBTree(char *root,FamType fam[],int n)	//��fam(��n����¼)�ݹ鴴��һ�ö�����
{
	int i=0,j;
	BTree *bt,*p;
	bt=(BTree *)malloc(sizeof(BTree));	//�������׽��
	strcpy(bt->name,root);
	bt->lchild=bt->rchild=NULL;
	while (i<n && strcmp(fam[i].father,root)!=0) 
		i++;
	if (i<n)									//�ҵ��˸������ļ�¼
	{
		p=(BTree *)malloc(sizeof(BTree));		//����ĸ�׽��
		p->lchild=p->rchild=NULL;
		strcpy(p->name,fam[i].wife);
		bt->lchild=p;
		for (j=0;j<n;j++)						//�����ж���
			if (strcmp(fam[j].father,root)==0)	//�ҵ�һ������
			{
				p->rchild=CreatBTree(fam[j].son,fam,n);
				p=p->rchild;
			}
	}
	return(bt);
}
void DispTree1(BTree *b)	//�����ű�ʾ�����������
{
	if (b!=NULL)
	{
		printf("%s",b->name);
		if (b->lchild!=NULL || b->rchild!=NULL)
		{
			printf("(");
			DispTree1(b->lchild);
			if (b->rchild!=NULL) 
				printf(",");
			DispTree1(b->rchild);
			printf(")");
		}
	}
}
void DispTree2(BTree *bt)	//�԰����ʾ�����
{
	BTree *St[MaxSize],*p;
	int Level[MaxSize][2],top,n,i,width=4;
	if (bt!=NULL)
	{
		printf("  >>���װ����ʾ��:\n");
        top=1;
		St[top]=bt;				//�������ջ
		Level[top][0]=width;
		while (top>0)
        {
			p=St[top];			//��ջ��������ʾ�ý��ֵ
			n=Level[top][0];
			for (i=1;i<=n;i++)  //����nΪ��ʾ����,�ַ����Ҷ�����ʾ
				printf(" ");
			printf("%6s",p->name);
			for (i=n+1;i<=MaxWidth-6;i+=2)
				printf("--");
			printf("\n");
			top--;
			if (p->rchild!=NULL)
			{					//���������������ջ
				top++;
				St[top]=p->rchild;
				Level[top][0]=n+width;   //��ʾ������width
				Level[top][1]=2;
			}
			if (p->lchild!=NULL)
			{					//���������������ջ
				top++;
				St[top]=p->lchild;
				Level[top][0]=n+width;   //��ʾ������width
				Level[top][1]=1;
			}
        }
	}
}
BTree *FindNode(BTree *bt,char xm[]) //��������ݹ��㷨��nameΪxm�Ľ��
{
	BTree *p=bt;
	if (p==NULL) 
		return(NULL);
	else
	{
		if (strcmp(p->name,xm)==0)
			return(p);
		else
		{
			bt=FindNode(p->lchild,xm);
			if (bt!=NULL) 
				return(bt);
			else 
				return(FindNode(p->rchild,xm));
		}
	}
}
void FindSon(BTree *bt)	//���ĳ�˵����ж���
{
	char xm[NAMEWIDTH];
	BTree *p;
	printf("  >>��������:");
	scanf("%s",xm);
	p=FindNode(bt,xm);
	if (p==NULL)
		printf("  >>������%s�ĸ���!\n",xm);
	else
	{
		p=p->lchild;
		if (p==NULL)
			printf("  >>%sû������\n",xm);
		else
		{
			p=p->rchild;
			if (p==NULL)
				printf("  >>%sû�ж���!\n",xm);
			else
			{
				printf("  >>%s�Ķ���:",xm);
				while (p!=NULL)
				{
					printf("%10s",p->name);
					p=p->rchild;
				}
				printf("\n");
			}
		} 
	}
}
int Path(BTree *bt,BTree *s)	//���ú���ǵݹ������������Ӹ���㵽*s����·��
{
	BTree *St[MaxSize];
	BTree *p;
	int i,flag,top=-1;				//ջָ���ó�ֵ
	do
	{
		while (bt)                 	//��bt�����������ջ
		{	
			top++;
			St[top]=bt;
			bt=bt->lchild;
		}
		p=NULL;                   	//pָ��ǰ����ǰһ���ѷ��ʵĽ��
		flag=1;                   	//����bt�ķ��ʱ��Ϊ�ѷ��ʹ�
		while (top!=-1 && flag)
		{	
			bt=St[top];          	//ȡ����ǰ��ջ��Ԫ��
			if (bt->rchild==p)      //�����������ڻ��ѱ�����,����֮
			{	if (bt==s)          //��ǰ���ʵĽ��ΪҪ�ҵĽ��,���·��
				{	
					printf("  >>��������:");
					for (i=0;i<top;i++) 
					   	printf("%s ",St[i]->name);
					printf("\n");
				   	return 1;
				}
				else
				{	
					top--;
				   	p=bt;           //pָ���򱻷��ʵĽ�
				}
			}
			else
			{	
				bt=bt->rchild;      //btָ��������
				flag=0;            	//����δ�����ʵı��
			}
		}
	} while (top!=-1);				//ջ����ʱѭ��
	return 0;						//�������ʱ����0
}
void Ancestor(BTree *bt)	//���ĳ�˵���������
{
	BTree *p;
	char xm[NAMEWIDTH];
	printf("  >>��������:");
	scanf("%s",xm);
	p=FindNode(bt,xm);
	if (p!=NULL)
		Path(bt,p);
	else
		printf("  >>������%s\n",xm);
}
void DelAll(FamType fam[],int &n)	//��������ļ�ȫ����¼
{
	FILE *fp;
	if ((fp=fopen("fam.dat","wb"))==NULL) 
	{	
		printf("  >>���ܴ򿪼����ļ�\n");
		return;
	}
	n=0;
	fclose(fp);
}
void ReadFile(FamType fam[],int &n) //�������ļ�����fam������
{
	FILE *fp;
	long len;
	int i;
	if ((fp=fopen("fam.dat","rb"))==NULL) 
	{
		n=0;
		return;
	}
	fseek(fp,0,2);				//�����ļ�λ��ָ���Ƶ������ļ�β
	len=ftell(fp);    			//len��������ļ�����
	rewind(fp);					//�����ļ�λ��ָ���Ƶ������ļ���
	n=len/sizeof(FamType); 		//n��������ļ��еļ�¼����
	for (i=0;i<n;i++)
		fread(&fam[i],sizeof(FamType),1,fp);//�������ļ��е����ݶ���fam��
	fclose(fp);
}
void SaveFile(FamType fam[],int n) //��fam����������ݼ����ļ�
{
	int i;
	FILE *fp;
	if ((fp=fopen("fam.dat","wb"))==NULL) 
	{	
		printf("  >>���ݼ����ļ����ܴ�\n");
		return;
	}
	for (i=0;i<n;i++)
		fwrite(&fam[i],sizeof(FamType),1,fp);
	fclose(fp);
}
void InputFam(FamType fam[],int &n)	//���һ����¼
{
	printf("  >>���븸�ס�ĸ�׺Ͷ�������:");
	scanf("%s%s%s",fam[n].father,fam[n].wife,fam[n].son);
	n++;
}
void OutputFile(FamType fam[],int n)//��������ļ�ȫ����¼
{
	int i;
	if (n<0)
	{
		printf("  >>û���κμ�¼\n");
		return;
	}
	for (i=0;i<n;i++)
		printf("  >>%10s%10s%10s\n",fam[i].father,fam[i].wife,fam[i].son);
}
void main()
{
	BTree *bt;
	FamType fam[MaxSize];
	int n,sel,sel1;
	ReadFile(fam,n);
	do
	{	
		printf("1.�ļ����� 2:���ײ��� 0:�˳� ��ѡ��:");
		scanf("%d",&sel);
		switch(sel)
		{
		case 1:
			do 
			{
				printf(" 1:���� 2:��� 9:ȫ�� 0:���̷��� ��ѡ��:");
				scanf("%d",&sel1);
				switch(sel1)
				{
				case 9:
					DelAll(fam,n);
					break;
				case 1:
					InputFam(fam,n);
					break;
				case 2:
					OutputFile(fam,n);
					break;
				case 0:
					SaveFile(fam,n);
					break;
				} 
			} while (sel1!=0);
			break;
		case 2:
			bt=CreatBTree("f1",fam,n);
			do 
			{
				printf(" 1:���ű�ʾ�� 2.�����ʾ�� 3.��ĳ�����ж��� 4.��ĳ���������� 0:���� ��ѡ��:");
				scanf("%d",&sel1);
				switch(sel1)
				{
				case 1:
					printf("  >>");DispTree1(bt);printf("\n");
					break;
				case 2:
					DispTree2(bt);
					break;
				case 3:
					FindSon(bt);
					break;
				case 4:
					printf("  >>");Ancestor(bt);
					break;
				} 
			} while (sel1!=0);
			break;
		}
	} while (sel!=0);
}
