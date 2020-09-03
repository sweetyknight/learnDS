//�ļ���:exp8-9.cpp
#include <stdio.h>
#define	MAXV  100				//��󶥵����
#define INF 32767               //��32767��ʾ��
#include "graph.h"
extern void DispMat(MGraph g);	//�ⲿ������algo9-1.c
void ppath(int path[][MAXV],int i,int j) 
{
	int k;
	k=path[i][j];
	if (k==-1)  return;
	ppath(path,i,k);
	printf("%d,",k);
	ppath(path,k,j);
}
void DisPath(int A[][MAXV],int path[][MAXV],int n)
{
	int i,j;
	for (i=0;i<n;i++)
		for (j=0;j<n;j++) 
			if (A[i][j]==INF)
			{
				if (i!=j) 
					printf("��%d��%dû��·��\n",i,j);
			}
			else 
			{	
				printf("��%d��%d·��Ϊ:",i,j);
				printf("%d,",i);ppath(path,i,j);printf("%d",j);
				printf("\t·������Ϊ:%d\n",A[i][j]);
			}
} 
void Floyd(MGraph g)	//���������㷨��ÿ�Զ���֮������·��
{
	int A[MAXV][MAXV],path[MAXV][MAXV];
	int i,j,k,n=g.vexnum;
	for (i=0;i<n;i++)						//��A�����ó�ֵ
		for (j=0;j<n;j++) 
		{	
			A[i][j]=g.edges[i][j];
			path[i][j]=-1;
		}
	for (k=0;k<n;k++)						//����Ak
	{
    	for (i=0;i<n;i++)
	    	for (j=0;j<n;j++)
		    	if (A[i][j]>(A[i][k]+A[k][j])) 
				{	
					A[i][j]=A[i][k]+A[k][j];
			    	path[i][j]=k;
		    	}
	}
	printf("\n������·��:\n");
	DisPath(A,path,n);   //������·��
}
void main()
{
	int i,j,u=0;
	MGraph g;
	int A[MAXV][6]={
		{INF,5,INF,7,INF,INF},
		{INF,INF,4,INF,INF,INF},
		{8,INF,INF,INF,INF,9},
		{INF,INF,5,INF,INF,6},
		{INF,INF,INF,5,INF,INF},
		{3,INF,INF,INF,1,INF}};
	g.vexnum=6;g.arcnum=10;
	for (i=0;i<g.vexnum;i++)
		for (j=0;j<g.vexnum;j++)
			g.edges[i][j]=A[i][j];
	printf("\n");
	printf("����ͼG���ڽӾ���:\n");
	DispMat(g);
	Floyd(g);
	printf("\n");
}

