#include "SqList.h"
#include <stdio.h>
#include <time.h>
#pragma 
int main(int argc, char const *argv[])
{
	SqList test; 
	SqList sq ,sq2,sq3;
	ElemType e;
	InitList_Sq(&sq);
	printOut(&sq);
	InitList_Sq(&sq2);
	printOut(&sq2);
	InitList_Sq(&sq3);
	printOut(&sq3);
	ListInsert_Sq(&sq,1,0);
	printOut(&sq);
	ListInsert_Sq(&sq,2,0);
	printOut(&sq);
	ListInsert_Sq(&sq,3,0);
	printOut(&sq);
	ListDelete_Sq(&sq,3,&e);
	printOut(&sq);

	ListInsert_Sq(&sq2,1,0);
	printOut(&sq2);
	ListInsert_Sq(&sq2,8,0);
	printOut(&sq2);
	ListInsert_Sq(&sq2,9,0);
	printOut(&sq2);

	MergeList_Sq(&sq,&sq2,&sq3);
	printOut(&sq3);
	destroyListSq(&sq);
	printOut(&sq);
	destroyListSq(&sq2);
	printOut(&sq2);
	destroyListSq(&sq3);
	printOut(&sq3);
	//end SqList test 
	//linkList test
	/*linkList La;
	ElemType e;
	initLinkList(&La); 
	linkListInsert(&La,1,0);
	linkListInsert(&La,4,0);
	linkListInsert(&La,6,0);
	linkListInsert(&La,8,0);
	linkListDelete(&La,4,&e);
	print(&La);
	destroylinkList(&La);*/
	//end linkListe test
	
//	time_t timet = 0x7fffffff;	
//	printf("%s",ctime(&timet));
//	int c = 'a';
/*int *d = NULL; 
	unsigned int c = 1;
	if(d<c)
		printf("-1<1");
	else
		printf("-1>1");
	int apple = sizeof ((int)(*d));
	printf("%d",apple);
	return 0;*/
	//printf(&unix["\021%siz\012\0"],(unix)["have"]+"fun"-0x60);
}
