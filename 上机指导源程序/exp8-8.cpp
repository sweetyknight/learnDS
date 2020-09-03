//�ļ���:exp8-8.cpp
#include <stdio.h>
#include "graph.h"
#define	MAXV  100				//��󶥵����
#define INF 32767               //��32767��ʾ��
extern void DispMat(MGraph g);	//�ⲿ������algo9-1.c
void ppath(int path[],int i,int v0) 
{
	int k;
	k=path[i];
	if (k==v0)  return;
	ppath(path,k,v0);
	printf("%d,",k);
}
void DisPath(int dist[],int path[],int s[],int n,int v0) //��path�������·��
{
	int i;
	printf("  path:");		//���pathֵ
	for (i=0;i<n;i++)
		printf("%3d",path[i]);
	printf("\n");
	for (i=0;i<n;i++)
		if (s[i]==1 && i!=v0) 
		{	
		  	printf("  ��%d��%d�����·������Ϊ:%d\t·��Ϊ:",v0,i,dist[i]);
			printf("%d,",v0);ppath(path,i,v0);printf("%d\n",i);
		}
		else  
			printf("  ��%d��%d������·��\n",v0,i);
}
void Dijkstra(MGraph g,int v0)	//�ҿ�˹�����㷨�Ӷ���v0���������������·��
{
	int dist[MAXV],path[MAXV];
	int s[MAXV];
	int mindis,i,j,u,n=g.vexnum;
	for (i=0;i<n;i++) 
	{	
		dist[i]=g.edges[v0][i];   		//�����ʼ��
		s[i]=0;                			//s[]�ÿ�
		if (g.edges[v0][i]<INF)			//·����ʼ��
			path[i]=v0;
		else
		    path[i]=-1;
	}
	s[v0]=1;path[v0]=0;        			//Դ����v0����s��
	for (i=0;i<n;i++)     				//ѭ��ֱ�����ж�������·�������
	{	
		mindis=INF;
		u=-1;
		for (j=0;j<n;j++)     			//ѡȡ����s���Ҿ�����С����Ķ���u
			if (s[j]==0 && dist[j]<mindis) 
			{ 	
				u=j;mindis=dist[j];	
			}
		s[u]=1;               			//����u����s��
		for (j=0;j<n;j++)      			//�޸Ĳ���s�еĶ���ľ���
			if (s[j]==0) 
				if (g.edges[u][j]<INF && dist[u]+g.edges[u][j]<dist[j]) 
				{	
					dist[j]=dist[u]+g.edges[u][j];
					path[j]=u;
				}  
	}
	printf("������·��:\n");
	DisPath(dist,path,s,n,v0);  		//������·��
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

	for (i=0;i<g.vexnum;i++)		//����ͼ9.1���ڽӾ���
		for (j=0;j<g.vexnum;j++)
			g.edges[i][j]=A[i][j];
	printf("\n");
	printf("����ͼG���ڽӾ���:\n");
	DispMat(g);
	Dijkstra(g,u);
	printf("\n");
}
