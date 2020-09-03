#include <stdio.h>
#define M 6
#define N 7
#define MaxSize  100         //�����з���Ԫ��������
typedef int ElemType;
typedef struct 
{
	int r;                 	//�к�
	int c;                 	//�к�
	ElemType d;            	//Ԫ��ֵ
} TupNode;               	//��Ԫ�鶨��
typedef struct 
{	
	int rows;              	//����ֵ
	int cols;              	//����ֵ
	int nums;              	//����Ԫ�ظ���
	TupNode data[MaxSize];
} TSMatrix;                   	//��Ԫ��˳�����
void CreatMat(TSMatrix &t,ElemType A[M][N])
{
	int i,j;
	t.rows=M;t.cols=N;t.nums=0;
	for (i=0;i<M;i++)
	{
		for (j=0;j<N;j++) 
			if (A[i][j]!=0) 	//ֻ�洢����Ԫ��
			{
				t.data[t.nums].r=i;t.data[t.nums].c=j;
				t.data[t.nums].d=A[i][j];t.nums++;
			}
	}
}
int Value(TSMatrix &t,ElemType x,int rs,int cs)
{
	int i,k=0;
	if (rs>=t.rows || cs>=t.cols)
		return 0;
	while (k<t.nums && rs>t.data[k].r) k++;	//������
	while (k<t.nums && rs==t.data[k].r && cs>t.data[k].c) k++;	//������
	if (t.data[k].r==rs && t.data[k].c==cs)	//����������Ԫ��
		t.data[k].d=x;
	else   									//������������Ԫ��ʱ����һ��Ԫ��
	{
		for (i=t.nums-1;i>=k;i--) 
		{
			t.data[i+1].r=t.data[i].r;
			t.data[i+1].c=t.data[i].c;
			t.data[i+1].d=t.data[i].d;
		}
		t.data[k].r=rs;t.data[k].c=cs;t.data[k].d=x;
		t.nums++;
	}
	return 1;
}
int Assign(TSMatrix t,ElemType &x,int rs,int cs)
{
	int k=0;
	if (rs>=t.rows || cs>=t.cols)
		return 0;
	while (k<t.nums && rs>t.data[k].r) k++;
	while (k<t.nums && rs==t.data[k].r && cs>t.data[k].c) k++;
	if (t.data[k].r==rs && t.data[k].c==cs) 
	{
		x=t.data[k].d;
		return 1;   
	}
	else  
		return 0;
}
void DispMat(TSMatrix t)
{
	int i;
	if (t.nums<=0) return;
	printf("\t%d\t%d\t%d\n",t.rows,t.cols,t.nums);
	printf("\t------------------\n");
	for (i=0;i<t.nums;i++)
		printf("\t%d\t%d\t%d\n",t.data[i].r,t.data[i].c,t.data[i].d);
}
void TranTat(TSMatrix t,TSMatrix &tb)
{
	int p,q=0,v;      				//qΪtb.data���±�
	tb.rows=t.cols;tb.cols=t.rows;tb.nums=t.nums;
	if (t.nums!=0) 
	{
		for (v=0;v<t.cols;v++)      //tb.data[q]�еļ�¼��c��Ĵ�������
			for (p=0;p<t.nums;p++) 	//pΪt.data���±�
				if (t.data[p].c==v) 
				{
					tb.data[q].r=t.data[p].c;
					tb.data[q].c=t.data[p].r;
					tb.data[q].d=t.data[p].d;
					q++;
				}
	}
}
/*void main()
{
	TSMatrix t;
	int x,y=10;
	int A[6][7]={
		{0,0,1,0,0,0,0},
		{0,2,0,0,0,0,0},
		{3,0,0,0,0,0,0},
		{0,0,0,5,0,0,0},
		{0,0,0,0,6,0,0},
		{0,0,0,0,0,7,4}};
	CreatMat(t,A);
	DispMat(t);
	if (Assign(t,x,2,5)==1)  //����ʱ����1
		printf("x=%d\n",x);
	else  //����ʱ����0
		printf("x=0\n");
	Value(t,y,2,5);
	DispMat(t);
	if (Assign(t,x,2,5)==1)  //����ʱ����1
		printf("x=%d\n",x);
	else  //����ʱ����0
		printf("x=0\n");
}
*/