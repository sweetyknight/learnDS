#include <stdio.h>
#define MaxSize 100
#define M 8
#define N 8
int mg[M+2][N+2]=
{	
	{1,1,1,1,1,1,1,1,1,1},
	{1,0,0,1,0,0,0,1,0,1},
	{1,0,0,1,0,0,0,1,0,1},
	{1,0,0,0,0,1,1,0,0,1},
	{1,0,1,1,1,0,0,0,0,1},
	{1,0,0,0,1,0,0,0,0,1},
	{1,0,1,0,0,0,1,0,0,1},
	{1,0,1,1,1,0,1,1,0,1},
	{1,1,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1}
};
struct 
{	int i,j;			//�����λ��
	int pre;			//��·������һ������Qu�е��±�
} Qu[MaxSize];
int front=-1,rear=-1;	//�ֱ�Ϊ����ָ��Ͷ�βָ��
void print(int front)	//�Ӷ��������·��
{
	int k=front,j,ns=0;
	printf("\n");
	do				//�����ҵ����·��,����·���ϵķ����pre��Ա���ó�-1
	{	j=k;
		k=Qu[k].pre;
		Qu[j].pre=-1;
	} while (k!=0);
	printf("�Թ�·������:\n");
	k=0;
	while (k<MaxSize)  //����������preΪ-1�ķ���,�����������·��
	{	if (Qu[k].pre==-1)
		{	ns++;
			printf("\t(%d,%d)",Qu[k].i,Qu[k].j);
			if (ns%5==0) printf("\n");	//ÿ���ÿ5�������һ��
		}
		k++;
	}
	printf("\n");
}
int mgpath(int xi,int yi,int xe,int ye)					//����·��Ϊ:(xi,yi)->(xe,ye)
{
	int i,j,find=0,di;
	rear++;
	Qu[rear].i=xi;Qu[rear].j=yi;	//(xi,yi)����
	Qu[rear].pre=-1;	
	mg[1][1]=-1;					//���丳ֵ-1,�Ա���ع����ظ�����
	while (front<=rear && !find)	//���в�Ϊ����δ�ҵ�·��ʱѭ��
	{	
		front++;					//����,���ڲ��ǻ��ζ��У��ó���Ԫ�����ڶ�����
		i=Qu[front].i;j=Qu[front].j;
		if (i==xe && j==ye)			//�ҵ��˳���,���·��
		{	
			find=1;				
			print(front);			//����print�������·��
			return(1);				//�ҵ�һ��·��ʱ����1
		}
		for (di=0;di<4;di++)		//ѭ��ɨ��ÿ����λ,��ÿ�����ߵķ�����������
		{	
			switch(di)
			{
			case 0:i=Qu[front].i-1;j=Qu[front].j;break;
			case 1:i=Qu[front].i;j=Qu[front].j+1;break;
			case 2:i=Qu[front].i+1;j=Qu[front].j;break;
			case 3:i=Qu[front].i,j=Qu[front].j-1;break;
			}
			if (mg[i][j]==0)
			{	rear++;				//�������ڷ�����뵽������
				Qu[rear].i=i;Qu[rear].j=j;
				Qu[rear].pre=front; //ָ��·������һ��������±�
				mg[i][j]=-1;		//���丳ֵ-1,�Ա���ع����ظ�����
			}
		}
     }
     return(0);						//δ�ҵ�һ��·��ʱ����1
}
void main()
{
	mgpath(1,1,M,N);
}