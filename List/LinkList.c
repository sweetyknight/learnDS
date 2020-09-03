
#include <stdio.h>
#include<stdlib.h>
#include <stdbool.h>

typedef int ElemType;
typedef struct LNode {
	ElemType data;
	struct LNode *next;
}LinkNode;

//初始化线性表
void InitList(LinkNode *L) {
	//L = (LinkNode*)malloc(sizeof(LinkNode));
	L->data = (ElemType)malloc(sizeof(ElemType));
	L->next = NULL;

}
//销毁链表
void DestroyList(LinkNode *L) {
	LinkNode *pre = L, *p = L->next;
	while (p!=NULL) {
		free(pre);
		pre = p;
		p = pre->next;
	}
	free(pre);
}
//判断是否为空表
bool ListEmpty(LinkNode *L) {
	return(L->next == NULL);
}
//求线性表的长度
int ListLength(LinkNode *L) {
	int n = 0;
	LinkNode *p = L;
	while (p->next != NULL) {
		n++;
		p = p->next;
	}
	return n;
}
//输出线性表
void DispList(LinkNode*L) {
	LinkNode *p = L->next;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
	//free(p);
	printf("\n");
}
//取链表中第i个节点的元素值
bool GetElem(LinkNode*L, int i, ElemType *e) {
	int j = 0;
	LinkNode *p = L;
	if (i <= 0) return false;
	while (j<i&&p != NULL) {
		j++;
		p = p->next;
	}
	if (p == NULL)
		return false;
	else
	{
		*e = p->data;
		return true;
	}
}
//按元素值查找,成功则返回其节点逻辑序号，否则返回0
int LocateElem(LinkNode*L, ElemType e) {
	int i = 1;
	LinkNode*p = L->next;
	while (p != NULL&&p->data != e) {
		p = p->next;
		i++;
	}
	if (p == NULL) return 0;
	else return i;
}
//插入数据元素,在单链表中找到第i-1个节点，由p指向它
//若存在这样的节点，将值为e的节点（s指向它）插入到p所指节点的后面
bool InsertElem(LinkNode*L, ElemType e, int i) {
	int j = 0;
	LinkNode *p = L, *s;
	if (i <= 0) return false;
	while (j<i - 1 && p != NULL) {
		j++;
		p = p->next;
	}
	if (p == NULL) {
		return false;
	}
	else {   //找到第i-1个节点，将其插入
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = e;   //建立新节点，将data域置为e
		s->next = p->next;
		p->next = s;
		return true;
	}
}
//删除元素，首先在链表中找到第i-1个节点，由p指向它
//若存在这样的节点，且也存在后继节点（由q指向它），则删除q所指的节点并返回true，否则false
bool DeleteElem(LinkNode *L, int i) {
	if (i <= 0) return false;
	int j = 0;
	LinkNode *p = L, *q;
	while (j<i - 1 && p != NULL) {
		j++;
		p = p->next;
	}
	if (p == NULL) {   //未找到第i-1个节点，返回false
		return false;
	}
	else {    //找到第i-1个节点p
		// q = (LinkNode*)malloc(sizeof(LinkNode));
		q = p->next;   //q指向第i个节点
		if (q == NULL) return false;
		p->next = q->next;
		free(q);
		return true;
	}
}

//从数组整体建立单链表：
//头插法建立单链表
void CreateLinkH(LinkNode*L,ElemType a[],int n){
    LinkNode *s;
    //L=(LinkNode*)malloc(sizeof(LinkNode));
    L->next=NULL;
    for(int i=0;i<n;i++){
        s=(LinkNode*)malloc(sizeof(LinkNode));
        s->data=a[i];
        s->next=L->next;
        L->next=s;
    }
}
//尾插法建立单链表
void CreateLinkT(LinkNode*L,ElemType a[],int n){
    LinkNode *s,*r;
    //L=(LinkNode*)malloc(sizeof(LinkNode));
    r=L;
    for(int i=0;i<n;i++){
        s=(LinkNode*)malloc(sizeof(LinkNode));
        s->data=a[i];
        r->next=s;
        r=s;
    }
    r->next=NULL;
}
int main() {
	LinkNode *L = (LinkNode*)malloc(sizeof(LinkNode));
	ElemType e = 0;

    int a[5]={1,2,3,4,5};
    LinkNode *H = (LinkNode*)malloc(sizeof(LinkNode));
    CreateLinkH(H,a,5);
    printf("头插法建立单链表：");
    DispList(H);

    LinkNode *T = (LinkNode*)malloc(sizeof(LinkNode));
    CreateLinkT(T,a,5);
    printf("尾插法建立单链表：");
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