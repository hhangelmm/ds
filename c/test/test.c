#include "btree.h"
#include <stdio.h>
#include <time.h>
#pragma 
int main(int argc, char const *argv[])
{
    Btree btree;
    btree = createNode(1);
    Btree btree2;
    btree2 = createNode(2);
    Btree btree3;
    btree3 = makeBtree(3,btree,btree2);

    btree = createNode(4);
    btree2 = makeBtree(5,btree3,btree);
//    spreOrder(btree2);
  //  printf("\n");
    //sinOrder(btree2);
    //printf("\n");
    spostOrder(btree2);
    printf("\n");
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
