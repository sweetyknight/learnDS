#include <stdio.h>
#include <malloc.h>
#include "graph.h"
#define INF 32767       //INF��ʾ��
int visited[MAXV];
void PathAll(ALGraph *G,int u,int v,int l,int path[],int d)
//d�ǵ���ǰΪֹ���߹���·�����ȣ�����ʱ��ֵΪ-1
{
	int m,i;
	ArcNode *p;
	visited[u]=1;
	d++;						//·��������1
	path[d]=u;					//����ǰ������ӵ�·����
	if (u==v && d==l)			//���һ��·��
	{	
		printf("  ");
		for (i=0;i<=d;i++)
			printf("%d ",path[i]);
		printf("\n");
	}
	p=G->adjlist[u].firstarc;  	//pָ�򶥵�u�ĵ�һ�����Ļ�ͷ���
	while (p!=NULL)
	{	m=p->adjvex;			//mΪu���ڽӶ���
		if (visited[m]==0)		//���ö���δ��Ƿ���,��ݹ����֮
			PathAll(G,m,v,l,path,d);
		p=p->nextarc;			//��u����һ���ڽӶ���
	}
	visited[u]=0;				//�ָ�������ʹ�ö��������ʹ��
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
	int path[MAXV],u=1,v=4,d=3,i,j;
	MGraph g;
	ALGraph *G;
	g.n=5;g.e=6;
	int A[MAXV][MAXV]={
		{0,1,0,1,0},
		{1,0,1,0,0},
		{0,1,0,1,1},
		{1,0,1,0,1},
		{0,0,1,1,0}};	
	for (i=0;i<g.n;i++)		
		for (j=0;j<g.n;j++)
			g.edges[i][j]=A[i][j];
	MatToList(g,G);
	for (i=0;i<g.n;i++) 		//visited�����ó�ֵ
		visited[i]=0;
	printf("ͼG:\n");DispAdj(G);//����ڽӱ�
	printf("��%d��%d�����г���Ϊ%d·��:\n",u,v,d);
	PathAll(G,u,v,d,path,-1);
	printf("\n");
}
