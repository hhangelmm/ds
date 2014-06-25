#include "loopList.h"
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
int InitList(loopList *L){
	L->head = NULL;
	L->len = 0;
	return 1;
}
int DestroyList(loopList *L){
	while(L->len > 0 ){
		Link pnode = L->head;
		L->head = pnode->next;
		free(pnode);
		L->len = L->len-1;
	}
	L->head = NULL;
	return 1;
}
int InsFirst(loopList *h,Link s){
	Link p = h->head;
	h->head = s;
	s->next = p;
	h->len += 1;
	if(h->len ==1)
		s->next = s;
	else{
		while(p->next && p->next !=s->next){
			p = p->next;
		};
		p->next = h->head;
	}
	return 1;
}
int DelFirst(loopList *h,Link q){
	q = h->head;
	h->head = h->head->next;
	h->len -= 1;
	if(h->len == 0)
		h->head = NULL;
	else{
		Link p = h->head;
		while(p->next != q){
			p = p->next;
		};
		p->next = h->head;
	}
	return 1;
}
int LocatePos(loopList L,int i, int * q){
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
Link LocateElem(loopList *L,ElemType e){
	Link  p;
	p = L->head;
	while(p){
		if (p->data == e)
			return p;
		p = p->next;
	};
	return 0;
}
void Print(loopList L){
	printf("\nlength : %d ",L.len);
	Link p;
	p = L.head;
	if(p == NULL)
		return;
	do{
		printf(" %d;",p->data);
		p = p->next;
	}while(p != L.head);
}
