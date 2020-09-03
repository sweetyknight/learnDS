//�ļ���:exp11-1.cpp
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 20
typedef int InfoType;		//�������������������
typedef int KeyType;		//����ؼ�������Ϊ����
struct RedType				//��¼����
{
	KeyType key;			//�ؼ�����
	InfoType otherinfo;		//����������,���������������ж���
};
#define MAXKEY 32767		//���ؼ���ֵ
#define RUNEND_SYMBOL 32767 //�ν������
#define w 5					//�ڴ湤���������ɵļ�¼����
#define M 6					//�����M�����ݻ���
#define N 18				//����ļ���N������

typedef int LoserTree[w];	//����������ȫ�������Ҳ���Ҷ��,�ɲ���˳��洢�ṹ
typedef struct
{
	RedType rec;		//��¼
	KeyType key;		//�Ӽ�¼�г�ȡ�Ĺؼ���
	int rnum;			//�����鲢�εĶκ�
} RedNode,WorkArea[w];	//�ڴ湤����,����Ϊw
void Select_MiniMax(LoserTree ls,WorkArea wa,int q) 
//��wa[q]�𵽰������ĸ��Ƚ�ѡ��MINIMAX��¼,����qָʾ�����ڵĹ鲢��
{
	int p,s,t;
	for(t=(w+q)/2,p=ls[t];t>0;t=t/2,p=ls[t])
		if(wa[p].rnum<wa[q].rnum||wa[p].rnum==wa[q].rnum&&wa[p].key<wa[q].key)
		{
			s=q;
			q=ls[t];		//qָʾ�µ�ʤ����
			ls[t]=s;
		}
		ls[0]=q;
}
void Construct_Loser(LoserTree ls,WorkArea wa,FILE *fi)
/*����w����¼���ڴ湤����wa,���ð�����ls,ѡ���ؼ�����С�ļ�¼����sָʾ
����wa�е�λ�á�*/
{
	int i;
	for(i=0;i<w;++i)
		wa[i].rnum=wa[i].key=ls[i]=0;			//��������ʼ��
	for(i=w-1;i>=0;--i)
	{
		fread(&wa[i].rec,sizeof(RedType),1,fi); //����һ����¼
		wa[i].key=wa[i].rec.key;				//��ȡ�ؼ���
		wa[i].rnum=1;							//��κ�Ϊ1
		Select_MiniMax(ls,wa,i);				//��������
	}
}
void get_run(LoserTree ls,WorkArea wa,int rc,int &rmax,FILE *fi,FILE *fo)
//���һ����ʼ�鲢��,fiΪ�����ļ�ָ��,foΪ����ļ�ָ�롣
{
	int q;
	KeyType minimax;
	while(wa[ls[0]].rnum==rc)	//ѡ�õ�MINIMAX��¼����ǰ��ʱ
	{
		q=ls[0];				//qָʾMINIMAX��¼��wa�е�λ��
		minimax=wa[q].key;
		fwrite(&wa[q].rec,sizeof(RedType),1,fo);	//����ѡ�õ�MINIMAX��¼д������ļ�
		fread(&wa[q].rec,sizeof(RedType),1,fi);		//�������ļ�������һ��¼(��)
		if (feof(fi))
		{	
			wa[q].rnum=rmax+1;	//�����ļ�����,�����¼(��rmax+1��)
			wa[q].key=MAXKEY;
		}
		else
		{	//�����ļ��ǿ�ʱ
			wa[q].key=wa[q].rec.key;//��ȡ�ؼ���
			if(wa[q].key<minimax)
			{ 
				rmax=rc+1;			//�¶���ļ�¼����һ��
				wa[q].rnum=rmax;
			}
			else //�¶���ļ�¼����ǰ��
				wa[q].rnum=rc;
		}
		Select_MiniMax(ls,wa,q); //ѡ���µ�MINIMAX��¼
    }
}
void Replace_Selection(LoserTree ls,WorkArea wa,FILE *fi,FILE *fo)
/*�ڰ�����ls���ڴ湤����wa�����û���ѡ���������ʼ�鲢��,fiΪ�����ļ�
(ֻ���ļ�)ָ��,foΪ����ļ�(ֻд�ļ�)ָ��,�����ļ����Ѵ򿪡�*/
{
	int rc,rmax;
	RedType j;
	j.key=RUNEND_SYMBOL;
	Construct_Loser(ls,wa,fi);			//����������
	rc=rmax=1;							//rcָʾ��ǰ���ɵĳ�ʼ�鲢�εĶκ�,rmaxָʾwa�йؼ���������ʼ�鲢�ε����κ�
	while(rc<=rmax)						//rc=rmax+1��־�����ļ����û���ѡ�����������
	{
		get_run(ls,wa,rc,rmax,fi,fo);	//���һ����ʼ�鲢��
		j.otherinfo=rc;
		fwrite(&j,sizeof(RedType),1,fo);//���ν�����־д������ļ�
		rc=wa[ls[0]].rnum;				//������һ�εĶκ�
	}
}
void print(RedType t)	//���t��¼
{
	if (t.key==RUNEND_SYMBOL)
		printf("(%s,%d)","��",t.otherinfo);
	else
		printf("(%d,%d)",t.key,t.otherinfo);
}
void main()
{
	RedType b,a[N]={{15,1},{4,2},{97,3},{64,4},{17,5},{32,6},{108,7},{44,8},{76,9},{9,10},{39,11},{82,12},{56,13},{31,14},{80,15},{73,16},{255,17},{68,18}};
	FILE *fi,*fo;
	LoserTree ls;
	WorkArea wa;
	KeyType tmp;
	int i,k,j=RUNEND_SYMBOL,rno=1;
	char s[3],fname[4];
	fo=fopen("ori","wb");			//��д�ķ�ʽ�򿪴��ļ�ori
	fwrite(a,sizeof(RedType),N,fo); //������aд����ļ�ori
	fclose(fo);
	fi=fopen("ori","rb");			//�Զ��ķ�ʽ���´򿪴��ļ�ori
	printf("\n ���ļ��ļ�¼Ϊ:\n\t");
	for(i=1;i<=N;i++)
	{
		fread(&b,sizeof(RedType),1,fi); //���ν����ļ�ori�����ݶ���b
		print(b);						//���b������
		if(i%M==0)
			printf("\n\t");
	}
	printf("\n");
	rewind(fi);				//ʹfi��ָ�����·��ش��ļ�ori����ʼλ��,�Ա����¶����ڴ�,������������ļ�
	fo=fopen("out","wb");	//��д�ķ�ʽ�򿪳�ʼ�鲢���ļ�out
	Replace_Selection(ls,wa,fi,fo); //���û���ѡ���������ʼ�鲢��
	fclose(fo);
	fclose(fi);
	fi=fopen("out","rb");	//�Զ��ķ�ʽ���´򿪳�ʼ�鲢���ļ�out
	printf(" ��ʼ�鲢���ļ��ļ�¼����:\n\n");
	printf(" �鲢��%d:",rno);
	i=1;tmp=0;
	do
	{
		k=fread(&b,sizeof(RedType),1,fi); //���ν����ļ�out�����ݶ���b
		if(k==1)
		{
			if(i++%M==0)
				printf("\n\t");
			if (b.key<tmp)
			{
				rno++;
				printf("\n �鲢��%d:",rno);
			}
			tmp=b.key;
			print(b);	//���b������
		}
	} while(k==1);
	printf("\n");
	rewind(fi);			//ʹfi��ָ�����·��ش��ļ�ori����ʼλ��,�Ա����¶����ڴ�,������������ļ�
	k=0;
	while(!feof(fi))	//���������ʼ�鲢���ļ�out
	{
		itoa(k,s,10);	//���������ļ���f0,f1,��
		strcpy(fname,"f");
		strcat(fname,s);
		fo=fopen(fname,"wb");	//������д�ķ�ʽ���ļ�f0,f1,��
		do
		{
			i=fread(&b,sizeof(RedType),1,fi);
			if(i==1)			//fread()���óɹ�
			{
				fwrite(&b,sizeof(RedType),1,fo); //��bд���ļ�f0,f1,��
				if(b.key==j)	//1���鲢�ν���
				{
					k++;
					fclose(fo);
					break;
				}
			}
		} while(i==1);
    }
	fclose(fi);
	printf("\n ������%d����ʼ�鲢���ļ�\n\n",k);
}
