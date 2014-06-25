/*
 *链栈
 */
#ifndef LSTACK_H
#define LSTACK_H
typedef int ElemType;
typedef struct StackNode{
	ElemType data;
	struct StackNode * next;
}StackNode;

typedef struct LStack{
	struct StackNode *base;
	struct StackNode *top;
	int stacklen;
}LStack;

int InitStack(LStack * S);
int DestroyStack(LStack *S);
int ClearStack(LStack *S);
int IsEmpty(LStack S);
int GetLen(LStack S);
int GetTop(LStack S ,ElemType *e);
int Pop(LStack *s ,ElemType *e);
int Push(LStack *s ,ElemType e);
void Print(LStack s);
#endif /* LSTACK_H*/

