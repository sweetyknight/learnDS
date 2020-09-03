//�ļ���:exp2-5.cpp
#include <stdio.h>
typedef char ElemType;
typedef struct DNode	//����ѭ��˫����������
{	
	ElemType data;
	struct DNode *prior,*next;
} DLinkList;
extern void InitList(DLinkList *&L);		//���¾�Ϊ�ⲿ����
extern void DestroyList(DLinkList *&L);
extern int ListEmpty(DLinkList *L);
extern int ListLength(DLinkList *L);
extern void DispList(DLinkList *L);
extern int GetElem(DLinkList *L,int i,ElemType &e);
extern int LocateElem(DLinkList *L,ElemType e);
extern int ListInsert(DLinkList *&L,int i,ElemType e);
extern int ListDelete(DLinkList *&L,int i,ElemType &e);
void main()
{
	DLinkList *h;
	ElemType e;
	printf("(1)��ʼ��ѭ��˫����h\n");
	InitList(h);
	printf("(2)���β���β�巨����a,b,c,d,eԪ��\n");
	ListInsert(h,1,'a');
	ListInsert(h,2,'b');
	ListInsert(h,3,'c');
	ListInsert(h,4,'d');
	ListInsert(h,5,'e');
	printf("(3)���ѭ��˫����h:");
	DispList(h);
	printf("(4)ѭ��˫����h����=%d\n",ListLength(h));
	printf("(5)ѭ��˫����hΪ%s\n",(ListEmpty(h)?"��":"�ǿ�"));
	GetElem(h,3,e);
	printf("(6)ѭ��˫����h�ĵ�3��Ԫ��=%c\n",e);
	printf("(7)Ԫ��a��λ��=%d\n",LocateElem(h,'a'));
	printf("(8)�ڵ�4��Ԫ��λ���ϲ���fԪ��\n");
	ListInsert(h,4,'f');
	printf("(9)���ѭ��˫����h:");
	DispList(h);
	printf("(10)ɾ��h�ĵ�3��Ԫ��\n");
    	ListDelete(h,3,e);
	printf("(11)���ѭ��˫����h:");
	DispList(h);
	printf("(12)�ͷ�ѭ��˫����h\n");
	DestroyList(h);
}
