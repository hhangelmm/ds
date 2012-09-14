/*
 * 带头节点的单链表
 */
#ifndef HLINKLIST_H
#define HLINKLIST_H 
typedef int ElemType;
typedef struct LNode{
	ElemType data;
	struct LNode * next;
}*Link, *Position;
typedef struct{
	Link head,tail;
	int len;
}hLinkList;

int MakeNode(Link *p,ElemType e);
void FreeNode(Link p);
int InitList(hLinkList *L);
int DestroyList(hLinkList *L);
int ClearList(hLinkList *L);
int InsFirst(hLinkList *h,Link s);
int DelFirst(hLinkList *h,Link q);
int Append(hLinkList *L,Link s);
int Remove(hLinkList *L,Link q);
int InsBefore(hLinkList *L,Link p,Link s);
int InsAfter(hLinkList *L,Link p,Link s);
int SetCurElem(Link p,ElemType e);
ElemType GetCurElem(Link p);
int ListEmpty(hLinkList *L);
int ListLength(hLinkList *L);
Position GetHead(hLinkList *L);
Position GetLast(hLinkList *L);
Position PriorPos(hLinkList *L,Link p);
Posotion NextPos(hLinkList *L,Link p);
int LocatePos(hLinkList L,int i, Link p);
Position LocateElem(hLinkList *L,ElemType e);
int ListTraverse(hLinkList *L,void (* visit)());

void MergeList(hLinkList La,hLinkList Lb,hLinkList Lc);
 
#endif /* HLINKLIST_H */
