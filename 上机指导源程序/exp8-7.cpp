//�ļ���:exp8-7.cpp
#include <stdio.h>
#include "graph.h"
#define INF 32767       //INF��ʾ��
#define MAXE 100		//������
typedef struct 
{	int u;				//�ߵ���ʼ����
    int v;				//�ߵ���ֹ����
    int w;				//�ߵ�Ȩֵ		
} Edge;
extern void DispMat(MGraph);		//�ⲿ������algo9-1.cpp��
void SortEdge(MGraph g,Edge E[])	//���ڽӾ������Ȩֵ�����ı߼�
{
	int i,j,k=0;
	Edge temp;
	for (i=0;i<g.vexnum;i++)
		for (j=0;j<g.vexnum;j++)
			if (g.edges[i][j]<INF)
			{
				E[k].u=i;
				E[k].v=j;
				E[k].w=g.edges[i][j];
				k++;
			}
	for (i=1;i<k;i++)	//��Ȩֵ�����������ֱ�Ӳ������� 
	{
		temp=E[i];
		j=i-1;			//����������������E[0..i-1]����E[i]�Ĳ���λ��
		while (j>=0 && temp.w<E[j].w) 
		{ 	
			E[j+1]=E[j]; //��Ȩֵ����E[i].w�ļ�¼����
			j--;
		}
		E[j+1]=temp;      //��j+1������E[i]
	}
}
void Kruskal(Edge E[],int n,int e)
{
	int i,j,m1,m2,sn1,sn2,k;
	int vset[MAXE];
	for (i=0;i<n;i++) vset[i]=i;	//��ʼ����������
	k=1;                 			//k��ʾ��ǰ������С�������ĵڼ�����,��ֵΪ1
	j=0;                 			//E�бߵ��±�,��ֵΪ0
	while (k<n)       				//���ɵı���С��nʱѭ��
	{	
		m1=E[j].u;m2=E[j].v;        //ȡһ���ߵ�ͷβ����
		sn1=vset[m1];sn2=vset[m2]; 	//�ֱ�õ��������������ļ��ϱ��
		if (sn1!=sn2)     			//���������ڲ�ͬ�ļ���,�ñ�����С��������һ����
		{	
			printf("  (%d,%d):%d\n",m1,m2,E[j].w);
			k++;                    //���ɱ�����1
			for (i=0;i<n;i++)      	//��������ͳһ���
				if (vset[i]==sn2)  	//���ϱ��Ϊsn2�ĸ�Ϊsn1
				    vset[i]=sn1;
		}
		j++;   						//ɨ����һ����
	}
}
void main()
{
	int i,j,u=3;
	MGraph g;
	Edge E[MAXE];
	int A[MAXV][11];
	g.vexnum=6;g.arcnum=10;
	for (i=0;i<g.vexnum;i++)
		for (j=0;j<g.vexnum;j++)
			A[i][j]=INF;
	A[0][1]=5;A[0][2]=8;A[0][3]=7;A[0][5]=3;
	A[1][2]=4;
	A[2][3]=5;A[2][5]=9;
	A[3][4]=5;
	A[4][5]=1;
	for (i=0;i<g.vexnum;i++)
		for (j=0;j<g.vexnum;j++)
			A[j][i]=A[i][j];
	for (i=0;i<g.vexnum;i++)
		for (j=0;j<g.vexnum;j++)
			g.edges[i][j]=A[i][j];
	SortEdge(g,E);
	printf("\n");
	printf("ͼG���ڽӾ���:\n");
	DispMat(g);
	printf("\n");
	printf("��³˹�����㷨�����:\n");
	Kruskal(E,g.vexnum,g.arcnum);
	printf("\n");
}
