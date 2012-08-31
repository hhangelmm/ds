/*
 * 带头节点的单链表
 */
#ifndef LINKLIST_H
#define LINKLIST_H 
typedef int ElemType;
typedef struct LNode{
	ElemType data;
	struct LNode * next;
}*Link, *Position;
typedef struct{
	Link head,tail;
	int len;
}LinkList;

bool MakeNode(Link &p,ElemType e);
void FreeNode(Link &p);
bool InitList(LinkList &L);
bool DestroyList(LinkList &L);
bool ClearList(LinkList &L);
bool InsFirst(Link h,Link s);
bool DelFirst(Link h,Link &q);
bool Append(LinkList &L,Link s);
bool Remove(LinkList &L,Link &q);
bool InsBefore(LinkList &L,Link &p,Link s);
bool InsAfter(LinkList &L,Link &p,Link s);
bool SetCurElem(Link &p,ElemType e);
ElemType GetCurElem(Link p);
bool ListEmpty(LinkList L);
int ListLength(LinkList L);
Position GetHead(LinkList L);
Position GetLast(LinkList L);
Position PriorPos(LinkList L,Link p);
Posotion NextPos(LinkList L,Link p);
bool LocatePos(LinkList L,int i, Link &p);
Position LocateElem(LinkList L,ElemType e);
bool ListTraverse(LinkList L,void (* visit)());

void MergeList(LinkList &La,LinkList &Lb,LinkList &Lc);
 
#endif /* LINKLIST_H */
