/*
 * 循环链表
 */
#ifndef LOOPLIST_H
#define LOOPLIST_H
typedef int ElemType;
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}*Link;
typedef struct{
	Link head;
	int len;
}loopList;


//创建一个节点
int MakeNode(Link *p,ElemType e);

//释放一个节点
void FreeNode(Link p);

//初始化链表
int InitList(loopList *L);

//销毁链表
int DestroyList(loopList *L);

//在表头插入节点
int InsFirst(loopList *h,Link s);

//在表头删除节点
int DelFirst(loopList *h,Link q);


//返回第i个节点
int LocatePos(loopList L,int i, int * p);

//返回元素e的位置
Link LocateElem(loopList *L,ElemType e);

//遍历链表
int ListTraverse(loopList *L,void (* visit)());

//合并两个有序链表
void MergeList(loopList La,loopList Lb,loopList Lc);
 
void Print(loopList L);

#endif /* LOOPLIST_H */
