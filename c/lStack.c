#include "lStack.h"
#include <stdlib.h>
#include <stdio.h>

int InitStack(LStack * S){
	S->base = NULL;
	S->top = NULL;
	S->stacklen = 0;
	return 1;
}
int DestroyStack(LStack *S){
	ClearStack(S);
	S = NULL;
	return 1;
}
int ClearStack(LStack *S){
	StackNode *sn;
	while(S->stacklen){
		sn = S->top;
		S->top = sn->next;
		free(sn);
		S->stacklen -=1;
	}
	S->base = NULL;
	return 1;
}
int IsEmpty(LStack S){
	if(S.stacklen == 0)
		return 1;
	return 0;
}
int GetLen(LStack S){
	return S.stacklen;
}
int GetTop(LStack S ,ElemType *e){
	*e = S.top->data;
	return 1;
}
int Pop(LStack *s ,ElemType *e){
	*e = s->top->data;
	StackNode * p;
	p = s->top;
	s->top = s->top->next;
	s->stacklen -=1;
	free(p);
	return 1;
}
int Push(LStack *s ,ElemType e){
	StackNode * p ;
	p = (StackNode*)malloc(sizeof(StackNode));
	p->data = e;
	p->next = s->top;
	s->top = p;
	s->stacklen  += 1;
	return 1;
}
void Print(LStack S){
	struct StackNode *p;
	p = S.top;
	printf("length : %d\n",S.stacklen);
	while(p){
		printf("%d,",p->data);
		p = p->next;
	};
	printf("\n");
}
