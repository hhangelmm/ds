#include "SqList.h"
#include <stdlib.h>
#include <stdio.h>
int InitList_Sq(SqList *L)
{
	L->elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if( !L->elem )	
		return 0;
 	L->length = 0;
	L->listsize = LIST_INIT_SIZE;
	return 1;	
}

int ListInsert_Sq(SqList *L,ElemType e,int i)
{
	if( i<0 || i>L->length+1)
		return 0;
	if( L->length >= L->listsize)
	{
		ElemType *newbase = (ElemType *)realloc(L->elem,(L->listsize+LISTINCREMENT)*sizeof(ElemType));
		if( !newbase )
			return 1;
		L->elem = newbase;
		L->listsize += LISTINCREMENT;
	}
	if(i == 0) i = L->length;
	int p = 0;
	
	for( p=L->length-1; p>=i;p--)
	{
		*(L->elem+p+1) = *(L->elem+p);
	}
	*(L->elem+i) = e;
	++L->length;
	return 1;
}
int ListDelete_Sq(SqList *L, int i, ElemType *e)
{
	if( i<0 || i>L->length+1)
        return 0;
	e = (L->elem+i-1);
	int p = 0;
	for(p=i-1; p<L->length-1; p++)
	{
		*(L->elem+p) = *(L->elem+p+1);
	}
	--L->length;
	return 0;
}
void MergeList_Sq(SqList *La,SqList *Lb,SqList *Lc)
{
	ElemType *pa = La->elem;
	ElemType *pb = Lb->elem;
	Lc->listsize = Lc->length = La->length + Lb->length;
	ElemType *pc = Lc->elem = (ElemType *)malloc(Lc->listsize*sizeof(ElemType));
	if(!Lc->elem)
		exit(0);
	ElemType *pa_last = La->elem+La->length-1;
	ElemType *pb_last = Lb->elem+Lb->length-1;
	while(pa <= pa_last && pb <= pb_last)
	{
		if(*pa<=*pb) *pc++ = *pa++;
		else *pc++ = *pb++;
	} 
	while (pa<=pa_last) *pc++ = *pa++;
	while (pb<=pb_last) *pc++ = *pb++;
}

