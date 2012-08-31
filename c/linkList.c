#include	"linkList.h"
#include <stdlib.h>

int initLinkList( linkList *L)
{
	*L = NULL;
	return 1;
}
int linkListInsert(linkList *L,ElemType e,int i)
{
	linkList node = (linkList)malloc(sizeof(lNode));
	if(!node)
		return 0;
	node->elem = e;
	node->next = NULL;
	if(*L == NULL){
		*L = node;
	}else{
		lNode *p = *L;
		int j = 1;
		while(j<i || i<1){
			if(p->next){
				p = p->next;
			}else
				break;
			j++;
		}
		if(p->next)
			node->next = p->next;
		p->next = node;
	}
	node = NULL;
	return 1;
}
int linkListDelete(linkList *L, int i, ElemType *e)
{
	if(*L==NULL || i<1)
		return 0;
	lNode *p = *L;
	if(i == 1){
		*e = p->elem;
		*L = p->next;
		p->next = NULL;
		free(p);
	}else{
		int j = 2;
		while(j<i){
			if(p->next){
				p = p->next;
			}else
				break;
			j++;
		}	
		if(j != i)
			return 0;
		*e = p->next->elem;
		lNode *t = p->next;
		p->next = p->next->next;
		if(t->next)
			t->next = NULL;
		free(t);
	}
	return 1;
}

void linkListMerge(linkList La,linkList Lb,linkList Lc){
	return ;
}
void destroylinkList(linkList *La){
	lNode *p = *La;
	while(*La){
		p = *La;
		*La = (*La)->next;
		free(p);
	}
}
void print(linkList *La){
	while(*La){
		printf("%d",(*La)->elem);
		(*La) = (*La)->next;
	}
	printf("\n");
}
