//�ļ���:exp8-5.cpp
#include <stdio.h>
#include <malloc.h>
#include "graph.h"
extern void MatToList(MGraph,ALGraph *&);	//�����ⲿ������algo8-1.cpp��
extern void DispAdj(ALGraph *);
int visited[MAXV];							//ȫ������
void DFS(ALGraph *G,int v) 
{
	ArcNode *p;
	visited[v]=1;                   		//���ѷ��ʱ��
	p=G->adjlist[v].firstarc;      			//pָ�򶥵�v�ĵ�һ�����Ļ�ͷ���
	while (p!=NULL) 
	{	
		if (visited[p->adjvex]==0)			//��p->adjvex����δ����,�ݹ������
		{
			printf("<%d,%d> ",v,p->adjvex);	//�����������һ����
			DFS(G,p->adjvex);    
		}
		p=p->nextarc;              			//pָ�򶥵�v����һ�����Ļ�ͷ���
	}
}
void BFS(ALGraph *G,int v)  
{
	ArcNode *p;
	int queue[MAXV],front=0,rear=0;			//����ѭ�����в���ʼ��
	int visited[MAXV];            			//�����Ž��ķ��ʱ�־������
	int w,i;
	for (i=0;i<G->n;i++) 
		visited[i]=0;						//���ʱ�־�����ʼ��
	visited[v]=1;              				//���ѷ��ʱ��
	rear=(rear+1)%MAXV;
	queue[rear]=v;             				//v����
	while (front!=rear)       				//�����в���ʱѭ��
	{	
		front=(front+1)%MAXV;
		w=queue[front];       				//���Ӳ�����w
		p=G->adjlist[w].firstarc; 			//���붥��w�ڽӵĵ�һ������
		while (p!=NULL) 
		{	
			if (visited[p->adjvex]==0) 		//����ǰ�ڽӶ���δ������
			{	
				printf("<%d,%d> ",w,p->adjvex);	//�����������һ����
				visited[p->adjvex]=1;		//�øö����ѱ����ʵı�־
				rear=(rear+1)%MAXV;			//�ö������
				queue[rear]=p->adjvex; 		
           	}
           	p=p->nextarc;              		//����һ���ڽӶ���
		}
	}
	printf("\n");
}
void main()
{ 
	int i,j;
	MGraph g;
	ALGraph *G;
	int A[MAXV][11];
	g.vexnum=11;g.arcnum=13;
	for (i=0;i<g.vexnum;i++)
		for (j=0;j<g.vexnum;j++)
			A[i][j]=0;
	A[0][3]=1;A[0][2]=1;A[0][1]=1;
	A[1][5]=1;A[1][4]=1;
	A[2][6]=1;A[2][5]=1;A[2][3]=1;
	A[3][7]=1;
	A[6][9]=1;A[6][8]=1;A[6][7]=1;
	A[7][10]=1;
	for (i=0;i<g.vexnum;i++)
		for (j=0;j<g.vexnum;j++)
			A[j][i]=A[i][j];
	for (i=0;i<g.vexnum;i++)	
		for (j=0;j<g.vexnum;j++)
			g.edges[i][j]=A[i][j];
	G=(ALGraph *)malloc(sizeof(ALGraph));
	MatToList(g,G);
	printf("\n");
	printf("ͼG���ڽӱ�:\n");
	DispAdj(G);
	printf("\n");
	for (i=0;i<g.vexnum;i++) 
		visited[i]=0;
	printf("�������������:");
	DFS(G,3);printf("\n");
	for (i=0;i<g.vexnum;i++) 
		visited[i]=0;
	printf("�������������:");
	BFS(G,3);printf("\n");
}
