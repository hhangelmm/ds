/*
 *单链表
 */
#ifndef linkList_H
#define linkList_H

#include <stdio.h>
typedef int ElemType;
typedef struct lNode {
	ElemType elem;
	struct lNode *next;
} lNode,*linkList;
int linkListInit(linkList *L);
int linkListInsert(linkList *L,ElemType e,int i);
int linkListDelete(linkList *L, int i, ElemType *e);
void linkListMerge(linkList La,linkList Lb,linkList *Lc);
void destroylinkList(linkList *La);
void print(linkList La);
#endif /* !linkList_H */
