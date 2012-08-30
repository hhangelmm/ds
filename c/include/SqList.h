/*
 *线性表的动态分配顺序存储结构
 */
#ifndef SqList_H
#define SqList_H

#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10
typedef int ElemType;
typedef struct {
	ElemType *elem;
	int length;
	int listsize;
} SqList;

int InitList_Sq( SqList *L);
int ListInsert_Sq(SqList *L,ElemType e,int i);
int ListDelete_Sq(SqList *L, int i, ElemType *e);
void MergeList_Sq(SqList *La,SqList *Lb,SqList *Lc);
void destroyListSq(SqList *La);
#endif /* !SqList_H */
