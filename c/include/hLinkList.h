/*
 * 带头节点的单链表,有头指针和尾指针
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

//创建一个节点
int MakeNode(Link *p,ElemType e);

//释放一个节点
void FreeNode(Link p);

//初始化链表
int InitList(hLinkList *L);

//销毁链表
int DestroyList(hLinkList *L);

//在表头插入节点
int InsFirst(hLinkList *h,Link s);

//在表头删除节点
int DelFirst(hLinkList *h,Link q);

//在表尾插入节点
int Append(hLinkList *L,Link s);

//返回第i个节点
int LocatePos(hLinkList L,int i, int * p);

//返回元素e的位置
Position LocateElem(hLinkList *L,ElemType e);

//遍历链表
int ListTraverse(hLinkList *L,void (* visit)());

//合并两个有序链表
void MergeList(hLinkList La,hLinkList Lb,hLinkList Lc);
 
void Print(hLinkList L);
#endif /* HLINKLIST_H */
