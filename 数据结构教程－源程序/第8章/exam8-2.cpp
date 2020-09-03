#include <stdio.h>
#include <malloc.h>
#include "graph.h"
#define INF 32767       //INF��ʾ��
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
		printf("%3d: ",i);
		while (p!=NULL)
		{
			printf("%3d",p->adjvex);
			p=p->nextarc;
		}
		printf("\n");
	}
}
/*������������������
void main()
{
	int i,j;
	MGraph g,g1;
	ALGraph *G;
	int A[MAXV][6]={
		{0,5,0,7,0,0},
		{0,0,4,0,0,0},
		{8,0,0,0,0,9},
		{0,0,5,0,0,6},
		{0,0,0,5,0,0},
		{3,0,0,0,1,0}};
	g.n=6;g.e=10;
	for (i=0;i<g.n;i++)
		for (j=0;j<g.n;j++)
			g.edges[i][j]=A[i][j];
	printf("\n");
	printf(" ����ͼG���ڽӾ���:\n");
	DispMat(g);
	G=(ALGraph *)malloc(sizeof(ALGraph));
	printf(" ͼG���ڽӾ���ת�����ڽӱ�:\n");
	MatToList(g,G);
	DispAdj(G);
	printf(" ͼG���ڽӱ�ת�����ڽ�����:\n");
	for (i=0;i<g.n;i++)
	   	for (j=0;j<g.n;j++)
			g1.edges[i][j]=0;
	ListToMat(G,g1);
	DispMat(g1);
	printf("\n");
}
*/