#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

typedef int ElemType;
typedef struct DNode {
	ElemType data;
	struct DNode *prior;	
	struct DNode *next;		
} DLinkNode;

void CreateLinkH(DLinkNode *L,ElemType a[],int n){
	DLinkNode *s;
	//L=(DLinkNode *)malloc(sizeof(DLinkNode));  	
	L->prior=L->next=NULL;
	for (int i=0;i<n;i++){	
		s=(DLinkNode *)malloc(sizeof(DLinkNode));
		s->data=a[i];
		s->next=L->next;			
		if (L->next!=NULL) L->next->prior=s;
		L->next=s;
        s->prior=L;
	}
}

void CreateLinkT(DLinkNode *L,ElemType a[],int n){
	DLinkNode *s,*r;
	//L=(DLinkNode *)malloc(sizeof(DLinkNode));  	
	L->prior=L->next=NULL;
	r=L;					
	for (int i=0;i<n;i++)
	{	
		s=(DLinkNode *)malloc(sizeof(DLinkNode));
		s->data=a[i];
		r->next=s;
        s->prior=r;	
		r=s;
	}
	r->next=NULL;			
}

void InitList(DLinkNode *L){
    //L = (DLinkNode*)malloc(sizeof(DLinkNode));
	L->data=(ElemType)malloc(sizeof(ElemType));	
	L->prior=L->next=NULL;
}

void DestroyList(DLinkNode *L){
	DLinkNode *p=L,*q=p->next;
	while (q!=NULL){
		free(p);
		p=q;
		q=p->next;
	}
	free(p);
}

int ListEmpty(DLinkNode *L){
	return(L->next==NULL);
}

int ListLength(DLinkNode *L){
	DLinkNode *p=L;
    int n=0;
	while (p->next!=NULL){
		n++;
		p=p->next;
	}
	return(n);
}

void DispList(DLinkNode *L){
	DLinkNode *p=L->next;
	while (p!=NULL){
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}

bool GetElem(DLinkNode *L,int i,ElemType *e){
    if (i<=0) return false;
	int j=0;
	DLinkNode *p=L;
	while (j<i && p!=NULL){
		j++;
		p=p->next;
	}
	if (p==NULL)
		return false;
	else{
		*e=p->data;
		return true;
	}
}

int LocateElem(DLinkNode *L,ElemType e){
	int n=1;
	DLinkNode *p=L->next;
	while (p!=NULL && p->data!=e){
		n++;
		p=p->next;
	}
	if (p==NULL) return(0);
	else return n;
}

bool InsertElem(DLinkNode *L, ElemType e,int i){
	int j=0;
	DLinkNode *p=L,*s;
	while (j<i-1 && p!=NULL){
		j++;
		p=p->next;
	}
	if (p==NULL)	
		return false;
	else {
		s=(DLinkNode *)malloc(sizeof(DLinkNode));
		s->data=e;
		s->next=p->next;
		if (p->next!=NULL) p->next->prior=s;
		s->prior=p;
		p->next=s;
		return true;
	}
}

bool DeleteElem(DLinkNode *L,int i){
    if (i<=0) return false;
	int j=0;
	DLinkNode *p=L,*q;
	while (j<i-1 && p!=NULL){
		j++;
		p=p->next;
	}
	if (p==NULL)				
		return false;
	else						{
		q=p->next;				
		if (q==NULL) return false;	
		p->next=q->next;		
		if (p->next!=NULL) p->next->prior=p;
		free(q);				
		return true;
	}
}

int main() {
	DLinkNode *L = (DLinkNode*)malloc(sizeof(DLinkNode));
	ElemType e = 0;

    int a[5]={1,2,3,4,5};
    DLinkNode *H = (DLinkNode*)malloc(sizeof(DLinkNode));
    CreateLinkH(H,a,5);
    printf("头插法建立双链表：");
    DispList(H);

    DLinkNode *T = (DLinkNode*)malloc(sizeof(DLinkNode));
    CreateLinkT(T,a,5);
    printf("尾插法建立双链表：");
    DispList(T);

	InitList(L);
	InsertElem(L, 10, 1);
	InsertElem(L, 20, 1);
	InsertElem(L, 30, 1);
	InsertElem(L, 40, 1);
	InsertElem(L, 50, 1);
	if (InsertElem(L, 60, 1))
		DispList(L);
	printf("ListLength(L)=%d\n", ListLength(L));
	ElemType *q = &e;
	if (GetElem(L, 3, q)) {
		printf("GetElem(L,3)=%d\n", e);
	}
	else {
		printf("GetElem(L,3)不存在\n");
	}
	printf("LocateElem(L,20)==%d\n", LocateElem(L, 20));
	DeleteElem(L, 3);
	printf("after delete:");
	DispList(L);
	DestroyList(L);
}