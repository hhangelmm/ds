#include "hLinkList.h"

int MakeNode(Link &p,ElemType e){
	Link pnode = (Link)malloc(sizeof(ElemType));
	if(!pnode)
		return 0;
	pnode->data = e;
	pnode->next = NULL;
	p = pnode;
	return 1;
}
void FreeNode(Link p){
	free(p);
}
int InitList(hLinkList *L){
	L->head = NULL;
	L->tail = NULL;
	L->len = 0;
}
int DestroyList(hLinkList *L){
	while(L->len > 0 ){
		Link pnode = L->head;
		L->head = pnode->next;
		free(pnode);
		L->len = L->len-1;
	}
	L->tail = NULL;
}
