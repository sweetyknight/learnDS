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
int mgpath(int xi,int yi,int xe,int ye)	//���·��Ϊ:(xi,yi)->(xe,ye)
{
	struct 
	{	
		int i;					//��ǰ������к�
		int j;					//��ǰ������к�
		int di;					//di����һ���߷�λ�ķ�λ��
	} st[MaxSize];				//����ջ
	int top=-1;					//��ʼ��ջָ��
	int i,j,k,di,find;
	top++;      				//��ʼ�����ջ
	st[top].i=xi;st[top].j=yi;
	st[top].di=-1;mg[1][1]=-1; 
	while (top>-1)				//ջ����ʱѭ��
	{
		i=st[top].i;j=st[top].j;di=st[top].di;  //ȡջ������
		if (i==xe && j==ye)		//�ҵ��˳���,���·��
		{ 
			printf("�Թ�·������:\n");
			for (k=0;k<=top;k++)
			{
				printf("\t(%d,%d)",st[k].i,st[k].j);
				if ((k+1)%5==0)	//ÿ���ÿ5�������һ��
					printf("\n");  
			}
			printf("\n");
			return(1);		//�ҵ�һ��·���󷵻�1
		}
		find=0;
		while (di<4 && find==0)		//����һ�����߷���
		{	
			di++;
			switch(di)
			{
			case 0:i=st[top].i-1;j=st[top].j;break;
			case 1:i=st[top].i;j=st[top].j+1;break;
			case 2:i=st[top].i+1;j=st[top].j;break;
			case 3:i=st[top].i,j=st[top].j-1;break;
			}
			if (mg[i][j]==0) find=1;//�ҵ���һ���������ڷ���
		}
		if (find==1)				//�ҵ�����һ�����߷���
		{	
			st[top].di=di;			//�޸�ԭջ��Ԫ�ص�diֵ
			top++;					//��һ�����߷����ջ
			st[top].i=i;st[top].j=j;st[top].di=-1;
			mg[i][j]=-1;			//�����ظ��ߵ��÷���
		}
		else						//û��·������,����ջ
		{	
			mg[st[top].i][st[top].j]=0;//�ø�λ�ñ�Ϊ����·�����߷���
			top--;					//���÷�����ջ
		}
	}
	return(0);	//��ʾû�п���·��,����0
}
void main()
{
	mgpath(1,1,M,N);
}