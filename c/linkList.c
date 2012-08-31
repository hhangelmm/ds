#include	"linkList.h"

int initLinkList( linkList *L)
{
	L = NULL;
	return 1;
}
int linkListInsert(linkList *L,ElemType e,int i)
{
	lNode *node = (lNode*)malloc(sizeof(lNode));
	if(!node)
		return 0;
	node->elem = e;
	node->next = NULL;
	if(L == NULL){
		L = node;
	}
	else {
		lNode *p = L;
		int j = 1;
		while(j<i){
			if(!p->next){
				p = p->next;
				break;
			}
			j++;
		}
		if(!p->next)
			node->next = p->next;
		p->next = node;
	}
	node = NULL;
	return 1;
}
int linkListDelete(linkList *L, int i, ElemType *e)
{
	if(L==NULL)
		return 1;
	lNode *p = L;
	int j = 2;
	while(j<i){
		if(!p->next){
			p = p->next; 
			break;
		}
		j++;
	}
	if(p == L){
		e = p->elem;
		L->next = p->next;
		p->next = NULL;
	}else{
		e = p->next->elem;
		p->next = p->next->next;
		p->next->next = NULL;

	}
	return 1;
}

void linkListMerge(linkList *La,linkList *Lb,linkList *Lc){

}
void destroylinkList(linkList *La){
	lNode *p = La;
	while(!La){
		p = La;
		La = La->next;
		free(p);
	}
}
void printf(linkList *La){
	while(!La){
		printf("%d",*La->elem);
		La = La->next;
	}
	printf("\n");
}
