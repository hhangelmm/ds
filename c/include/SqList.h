/*
 *线性表的动态分配顺序存储结构
 */
#ifndef SqList_H
#define SqList_H

#define LIST_INIT_SIZE 2
#define LISTINCREMENT  1
typedef int ElemType;
typedef struct {
	ElemType *elem;
	int length;
	int listsize;
} SqList;
/*
 *初始化顺序表
 *分配初始空间为LIST_INIT_SIZE的顺序表
 */
int InitList_Sq( SqList *L);
int ListInsert_Sq(SqList *L,ElemType e,int i);
int ListDelete_Sq(SqList *L, int i, ElemType *e);

void MergeList_Sq(SqList *La,SqList *Lb,SqList *Lc);
void destroyListSq(SqList *La);
void printOut(SqList *L);
#endif /* !SqList_H */
