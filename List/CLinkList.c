#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

typedef int ElemType;
typedef struct cNode{
    ElemType data;
    struct cNode *next;
}CLinkNode;

void InitCList(CLinkNode *CN){
    // CN=(CLinkNode*)malloc(sizeof(CLinkNode));
    CN->data=(ElemType)malloc(sizeof(ElemType));
    CN->next=CN; //后继节点指向其本身
}

void DestroyCList(CLinkNode *CN){
    CLinkNode *p=CN,*q=p->next;
    while(q!=CN){
        free(p);
        p=q;
        q=p->next;
    }
    free(p);
}

bool CListEmpty(CLinkNode *CN){
    return(CN->next==CN);
}

int CListLength(CLinkNode *CN){
    int n=0;
    CLinkNode *p=CN;
    while(p->next!=CN){
        n++;
        p=p->next;
    }
    return n;
}

void DispCList(CLinkNode *CN){
    CLinkNode *p=CN->next;
    while(p!=CN){
        printf("%d ", p->data);
        p=p->next;
    }
    printf("\n");
}

bool GetElem(CLinkNode *CN, int i, ElemType *e){
    int j=0;
    CLinkNode *p=CN;
    if (i<=0) return false;
    if (CN->next!=CN) {
		if (i==1){
			*e=CN->next->data;
			return true;
		}else {
			p=CN->next;
			while (j<i-1 && p!=CN){
				j++;
				p=p->next;
			}
			if (p==CN) return false;
			else{
				*e=p->data;
				return true;
			}
		}
	}else return false;
}

int LocateElem(CLinkNode *CN,ElemType e){
    int i=1;
    CLinkNode* p=CN->next;
    while(p != CN && p->data != e) {
        p = p->next;
        i++;
    }
    if (p == CN) return 0;
    else return i;
}

bool InsertElem(CLinkNode *CN,ElemType e,int i){
    if (i<=0) return false;
    int j=0;
    CLinkNode* p=CN,*s;
    if (p->next==CN || i==1){
        s=(CLinkNode *)malloc(sizeof(CLinkNode));
        s->data=e;
        s->next=p->next;
        p->next=s;
        return true;
    }else{
        while (j<i-1 && p!=CN){
            j++;
            p=p->next;
        }
        if (p==CN){
            return false;
        }else{
            s=(CLinkNode *)malloc(sizeof(CLinkNode));
            s->data=e;
            s->next=p->next;
            p->next=s;
            return true;
        }
    }
}

// 如何删除循环链表的第一个结点？
bool DeleteElem(CLinkNode *CN,int i){
    if (i<=0) return false;
    int j=0;
    CLinkNode *p=CN, *q;
    if (p->next != CN){
        if (i==1){
            q=CN->next;
            p->next=q->next;
            free(q);
            return true;
        }else{
            p=CN->next;
            while(j<i-2 && p!=CN){
                j++;
                p=p->next;
            }
            if(p==CN){
                return false;
            }else{
                q=p->next;
                p->next=q->next;
                free(q);
                return true;
            }
        }
    }else return false;  // 如果只有一个结点，返回false
}

void CreateCLinkH(CLinkNode* CN,ElemType a[],int n){
    CLinkNode *s;
    //L=(LinkNode*)malloc(sizeof(LinkNode));
    CN->next=NULL;
    for(int i=0;i<n;i++){
        s=(CLinkNode*)malloc(sizeof(CLinkNode));
        s->data=a[i];
        s->next=CN->next;
        CN->next=s;
    }
    s=CN->next;
    while (s->next!=NULL){
        s=s->next;
    }
    s->next=CN;
}

void CreateCLinkT(CLinkNode*CN,ElemType a[],int n){
    CLinkNode *s,*r;
    //L=(LinkNode*)malloc(sizeof(LinkNode));
    CN->next=NULL;
    r=CN;
    for(int i=0;i<n;i++){
        s=(CLinkNode*)malloc(sizeof(CLinkNode));
        s->data=a[i];
        r->next=s;
        r=s;
    }
    r->next=CN;
}

int main() {
	CLinkNode *L = (CLinkNode*)malloc(sizeof(CLinkNode));
	ElemType e = 0;

    int a[5]={1,2,3,4,5};
    CLinkNode *H = (CLinkNode*)malloc(sizeof(CLinkNode));
    CreateCLinkH(H,a,5);
    printf("头插法建立循环单链表：");
    DispCList(H);

    CLinkNode *T = (CLinkNode*)malloc(sizeof(CLinkNode));
    CreateCLinkT(T,a,5);
    printf("尾插法建立循环单链表：");
    DispCList(T);

	InitCList(L);
	InsertElem(L, 10, 1);
	InsertElem(L, 20, 1);
	InsertElem(L, 30, 1);
	InsertElem(L, 40, 1);
	InsertElem(L, 50, 1);
	if (InsertElem(L, 60, 1))
		DispCList(L);
	printf("ListLength(L)=%d\n", CListLength(L));
	if (GetElem(L, 3, &e)) {
		printf("GetElem(L,3)=%d\n", e);
	}
	else {
		printf("GetElem(L,3)不存在\n");
	}
	printf("LocateElem(L,20)==%d\n", LocateElem(L, 20));
	DeleteElem(L, 1);
	printf("after delete:");
	DispCList(L);
	DestroyCList(L);
}