/*
 * 双链表 
 */
#ifndef DOUBLELIST_H
#define DOUBLELIST_H
typedef int ElemType;
typedef struct DuLNode{
	ElemType data;
	struct DuLNode *next;
	struct DuLNode *prior;
}*doubleList,DuLNode;


#endif /* DOUBLELIST_H */
