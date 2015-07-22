#include "hashtable.h"
#include <stdlib.h>

int main()
{
    typedef struct nodeval {
        char* str;
        int num;
    } nodeval;
    hashtable *htb = hashtable_create();
    char* key1 = "weryjsh";
    nodeval* val1 = malloc(sizeof(nodeval));
    val1->str = "hahahah";
    val1->num = 23;
    hashtable_set(htb,key1,val1,NULL);
    nodeval* val2 = hashtable_get(htb,"weryjsh");
    int re = hashtable_delete(htb,"weryjsh");
    hashtable_release(htb);
    return 1;
}
