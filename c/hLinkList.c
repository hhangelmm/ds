#include "hLinkList.h"
#include <stdlib.h>
#include <stdio.h>
int MakeNode(Link *p,ElemType e){
	Link pnode = (Link)malloc(sizeof(struct LNode));
	if(!pnode)
		return 0;
	pnode->data = e;
	pnode->next = NULL;
	*p = pnode;
	return 1;
}
void FreeNode(Link p){
	free(p);
}
int InitList(hLinkList *L){
	L->head = NULL;
	L->tail = NULL;
	L->len = 0;
	return 1;
}
int DestroyList(hLinkList *L){
	while(L->len > 0 ){
		Link pnode = L->head;
		L->head = pnode->next;
		free(pnode);
		L->len = L->len-1;
	}
	L->tail = NULL;
	return 1;
}
int InsFirst(hLinkList *h,Link s){
	Link p = h->head;
	h->head = s;
	s->next = p;
	h->len += 1;
	if(h->len == 1)
		h->tail = s;
	return 1;
}
int DelFirst(hLinkList *h,Link q){
	q = h->head;
	h->head = h->head->next;
	h->len -= 1;
	if(h->len == 0)
		h->tail = NULL;
	return 1;
}
int Append(hLinkList *L,Link s){
	Link p = L->tail;
	p->next = s;
	s->next = NULL;
	L->tail = s;
	L->len += 1;
	return 1;
}
int LocatePos(hLinkList L,int i, int * q){
	if(i < 0 || i > L.len)
		return 0;
	Link p;
	p = L.head;
	while(i>1){
		p = p->next;
		i--;
	};
	*q  = p->data;
	return 1;
}
Position LocateElem(hLinkList *L,ElemType e){
	Link  p;
	p = L->head;
	while(p){
		if (p->data == e)
			return p;
		p = p->next;
	};
	return 0;
}
void Print(hLinkList L){
	printf("\nlength : %d ",L.len);
	Link p;
	p = L.head;
	while(p){
		printf(" %d;",p->data);
		p = p->next;
	};
}
