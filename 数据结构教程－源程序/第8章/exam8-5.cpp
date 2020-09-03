#include <stdio.h>
#include <malloc.h>
#include "graph.h"
#define INF 32767       //INF��ʾ��
int visited[MAXV],path[MAXV];  //path[]���ڴ�Ż�··��,��Ϊȫ�ֱ���
void DFSPath(ALGraph *g ,int i,int j,int d)
{
	int v,k;
	ArcNode *p;
	visited[i]=1;
	d++;path[d]=i;
	if (i==j && d>2)         	//�ҵ�һ����·,�����
	{	
		printf("  ");
		for (k=1;k<=d;k++)
			printf("%d ",path[k]);
		printf("\n");
	}
	p=g->adjlist[i].firstarc;  //�Ҷ���i�ĵ�һ���ڽӶ���
	while (p!=NULL) 
	{	
		v=p->adjvex;          	//vΪ����i���ڽӶ���
		if (visited[v]==0 || v==j) 
			DFSPath(g,v,j,d); 	//���ö���δ��Ƿ���,��Ϊvj,��ݹ����֮
		p=p->nextarc;           //�Ҷ���i����һ���ڽӶ���
	}
	visited[i]=0;              //ȡ�����ʱ��,��ʹ�ö��������ʹ��
}
void FindCyclePath(ALGraph *G,int k)	//�����������k�����л�·
{
	printf("��������%d�����л�·\n",k);
    DFSPath(G,k,k,0);
}

void MatToList(MGraph g,ALGraph *&G)
//���ڽӾ���gת�����ڽӱ�G
{
	int i,j,n=g.n;						//nΪ������
	ArcNode *p;
	G=(ALGraph *)malloc(sizeof(ALGraph));
	for (i=0;i<n;i++)					//���ڽӱ�������ͷ����ָ�����ó�ֵ
		G->adjlist[i].firstarc=NULL;
	for (i=0;i<n;i++)					//����ڽӾ�����ÿ��Ԫ��
		for (j=n-1;j>=0;j--)
			if (g.edges[i][j]!=0)				//�ڽӾ���ĵ�ǰԪ�ز�Ϊ0
			{   
			   	p=(ArcNode *)malloc(sizeof(ArcNode));	//����һ�����*p
				p->adjvex=j;
				p->info=g.edges[i][j];
				p->nextarc=G->adjlist[i].firstarc;		//��*p���������
				G->adjlist[i].firstarc=p;
			}
	G->n=n;G->e=g.e;
}
void ListToMat(ALGraph *G,MGraph &g)
//���ڽӱ�Gת�����ڽӾ���g
{
	int i,n=G->n;
	ArcNode *p;
	for (i=0;i<n;i++) 
	{	
		p=G->adjlist[i].firstarc;
	    while (p!=NULL) 
		{	
			g.edges[i][p->adjvex]=p->info;
		    p=p->nextarc;
		}
	}
	g.n=n;g.e=G->e;
}
void DispMat(MGraph g)
//����ڽӾ���g
{
	int i,j;
	for (i=0;i<g.n;i++)
	{
		for (j=0;j<g.n;j++)
			if (g.edges[i][j]==INF)
				printf("%3s","��");
			else
				printf("%3d",g.edges[i][j]);
		printf("\n");
	}
}
void DispAdj(ALGraph *G)
//����ڽӱ�G
{
	int i;
	ArcNode *p;
	for (i=0;i<G->n;i++)
	{
		p=G->adjlist[i].firstarc;
		if (p!=NULL) printf("%3d: ",i);
		while (p!=NULL)
		{
			printf("%3d",p->adjvex);
			p=p->nextarc;
		}
		printf("\n");
	}
}
void main()
{ 
	int i,j;
	MGraph g;
	ALGraph *G;
	g.n=5;g.e=7;
	int A[MAXV][MAXV]={
		{0,1,1,0,0},
		{0,0,1,0,0},
		{0,0,0,1,1},
		{0,0,0,0,1},
		{1,0,0,0,0}};	
	for (i=0;i<g.n;i++)	
		for (j=0;j<g.n;j++)
			g.edges[i][j]=A[i][j];
	MatToList(g,G);
	for (i=0;i<g.n;i++) 		//visited�����ó�ֵ
		visited[i]=0;
	printf("ͼG:\n");DispAdj(G);//����ڽӱ�
	FindCyclePath(G,0);
	printf("\n");
}
