#include	"linkList.h"
#include <stdlib.h>
int linkListInit(linkList *L)
{
	*L =NULL;
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
void linkListMerge(linkList La,linkList Lb,linkList *Lc){
	linkList pLa = La;
	linkList pLb = Lb;
	linkList pLc = *Lc;
	while(pLa->next){
		if(pLa->elem > pLa->next->elem){
			printf("pLa is not sorted!");
		}
		pLa = pLa->next; 
	}
	while(pLb->next){
		if(pLb->elem > pLb->next->elem){
			printf("pLb is not sorted!");
		}
		pLb = pLb->next;
	}
	while(La && Lb){
		if(La->elem < Lb->elem){
			linkListInsert(Lc,La->elem,0);
			La = La->next;
		}else{
			linkListInsert(Lc,Lb->elem,0);
			Lb = Lb->next;
		}
	}
	pLc = *Lc;
	while(pLc->next){
		pLc = pLc->next;
	};
	if(La)
		pLc->next = La;
	if(Lb)
		pLc->next = Lb;
	return ;
}
void destroylinkList(linkList *La){
	lNode *p = *La;
	if(!*La)
		return;
	while(*La){
		p = *La;
		*La = (*La)->next;
		free(p);
	}
}
void print(linkList La){
	if(La == NULL)
		return;
	do{
		printf("%d",La->elem);
		La = La->next;
	}while(La);
	printf("\n");
}
