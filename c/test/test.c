#include "loopList.h"
#include <stdio.h>
#include <time.h>
#pragma 
int main(int argc, char const *argv[])
{
	loopList La;
	InitList(&La);
	Link p;
	MakeNode(&p,2);
	InsFirst(&La,p);
	Print(La);
	Link q;
	MakeNode(&q,3);
	InsFirst(&La,q);
	Print(La);
	struct LNode s;
	DelFirst(&La,&s);
	Print(La);
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
