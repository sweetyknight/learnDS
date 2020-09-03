#include <stdio.h>
#include<stdlib.h>
#include <stdbool.h>

//需要说明的是函数中的i代表的是逻辑序号而非实际序号
typedef int ElemType;
//定义顺序表的结构体类型
typedef struct
{
    ElemType *data;
    int maxSize;
    int length;
}SeqList;

//初始化线性表
void InitList(SeqList *L,int sz){
    if(sz>0){
        L->maxSize=sz;
        L->length=0;  
        L->data=(ElemType *)malloc(sizeof(ElemType)*L->maxSize);         
    }
}
//销毁线性表
void DestroyList(SeqList*L){
    free(L->data);
}
//判断是否为空表
bool ListEmpty(SeqList *L){
    return (L->length==0);
}
//判断线性表是否为满
bool ListFull(SeqList *L){
    return(L->length > L->maxSize);
}
//求线性表长度
int ListLength(SeqList *L){
    return (L->length);
}
//取线性表的第i个表目
bool GetElem(SeqList *L,int i,ElemType *e){
    if (i<1||i>L->maxSize+1)
        return false;
    *e=L->data[i-1];
    return true;
}
//在线性表中查找，查找成功返回该节点逻辑序号，否则返回0
//若表中值为e的节点有多个，找到的是第一个
int LocateElem(SeqList*L,ElemType e){
    int i=1;
    for(i=1;i<L->length+1;i++){
        if(L->data[i]==e) return i+1;
    }      
    return 0;
}

//在表中第i个位置插入值为e的节点，成功返回true否则返回false
bool InsertElem(SeqList *L,ElemType e,int i){
    int j;
    if(i<1||i>L->length+1||L->length==L->maxSize) //插入条件不对，插入失败
        return false;
    for(j=L->length;j>i;j--) //后移
        L->data[j]=L->data[j-1];
    L->data[i-1]=e;  //插入元素e
    L->length++;   //表长增1
    return true;
}
//删除表中第i个节点，成功返回true否则返回false
bool DeleteElem(SeqList *L,int i){
    int j;
    if(i<1||i>L->length||L->length==0)
        return false;
    for(j=i;j<L->length-1;j++)
        L->data[j]=L->data[j+1];
    L->length--;
    return true;
}
//打印线性表
void DispList(SeqList *L){
    int i;
    for (i=0;i<L->length;i++)
        printf("%d ",L->data[i]);
    printf("\n");
}

int main(){
    SeqList *L=(SeqList*)malloc(sizeof(SeqList));
    ElemType e=0;
    InitList(L,5);
    InsertElem(L,10,1);
    InsertElem(L,20,2);
    InsertElem(L,30,3);
    InsertElem(L,40,4);
    InsertElem(L,50,5);
    if(InsertElem(L,60,0))
        DispList(L);
    else {
        printf("List is full,insert failed\n");
    }
    DispList(L);
    printf("ListLength(L)=%d\n",ListLength(L));
    ElemType *q=&e;
    if(GetElem(L,3,q)){
        printf("GetElem(L,3)=%d\n",e);
    }else{
        printf("GetElem(L,3)不存在\n");
    }
    printf("LocateElem(L,20)==%d\n",LocateElem(L,20));
	DeleteElem(L,3);
    printf("after delete:");
	DispList(L);
	DestroyList(L);
}
