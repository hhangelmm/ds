#include "lStack.h"
#include <stdio.h>
#include <time.h>
#pragma 
int main(int argc, char const *argv[])
{
	LStack Ls;
	InitStack(&Ls);	
	int a = 1348;
	int b = a%8;
	while(a){
		Push(&Ls,b);
		a = a/8;
		b = a%8;
	}
	Print(Ls);
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
