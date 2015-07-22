#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include  <assert.h>
#include <limits.h>
#include "hashtable.h"


static int hashtable_can_resize = 1;
static unsigned int dict_force_resize_ratio = 5;

/*------------- private prototypes-------------- */
static int _hashtable_expand_ifneeded(hashtable *htb);
static unsigned long _hashtable_next_power(unsigned long size);
static int _hashtable_key_index(hashtable *htb, const void *key);
static int _hashtable_init(hashtable *htb);
/**/


static unsigned long _hashtable_next_power(unsigned long size)
{
    unsigned long i = HTB_HT_INITIAL_SIZE;

    if (size >= LONG_MAX) return LONG_MAX;
    while(1) {
        if (i >= size)
            return i;
        i *= 2;
    }
}
static void _hashtable_reset(htable *ht)
{
    ht->table = NULL;
    ht->size = 0;
    ht->sizemask = 0;
    ht->used = 0;
}
/* Initialize the hash table */
int _hashtable_init(hashtable *htb)
{
    _hashtable_reset(&htb->ht[0]);
    _hashtable_reset(&htb->ht[1]);

    htb->rehashidx = -1;
    return 1;
}
static void _hashtable_rehashstep(hashtable *htb) {
    hashtable_rehash(htb,1);
}
static int _hashtable_keyindex(hashtable *htb, const void *key)
{
    unsigned int h, idx, table;
    ht_node *he;

    if (_hashtable_expand_ifneeded(htb) == 0)
        return -1;

    /* Compute the key hash value */
    h = murmurhash2_hashfunction(key,strlen(key));
    for (table = 0; table <= 1; table++) {
        idx = h & htb->ht[table].sizemask;
        he = htb->ht[table].table[idx];
        while(he) {
            if (hashtable_comparekeys(htb, key, he->key))
                return -1;
            he = he->next;
        }
        if (!hashtable_isrehashing(htb)) break;
    }
    return idx;
}
static int _hashtable_expand_ifneeded(hashtable *htb)
{
    /* Incremental rehashing already in progress. Return. */
    if (hashtable_isrehashing(htb)) return 1;
    /* If the hash table is empty expand it to the initial size. */
    if (htb->ht[0].size == 0) return hashtable_expand(htb, HTB_HT_INITIAL_SIZE);

    /* If we reached the 1:1 ratio, and we are allowed to resize the hash
     * table (global setting) or we should avoid it but the ratio between
     * elements/buckets is over the "safe" threshold, we resize doubling
     * the number of buckets. */
    if (htb->ht[0].used >= htb->ht[0].size &&
            (hashtable_can_resize ||
             htb->ht[0].used/htb->ht[0].size > dict_force_resize_ratio))
    {
        return hashtable_expand(htb, htb->ht[0].used*2);
    }

    return 1;
}
int _hashtable_clear(hashtable *htb, htable *ht) {
    unsigned long i;
    /* Free all the elements */
    for (i = 0; i < ht->size && ht->used > 0; i++) {
        ht_node *he, *nextHe;
        if ((he = ht->table[i]) == NULL) continue;
        while(he) {
            nextHe = he->next;
            hashtable_freeval(htb, he);
            free(he);
            ht->used--;
            he = nextHe;
        }
    }

    /* Free the table and the allocated cache structure */
    free(ht->table);

    /* Re-initialize the table */
    _hashtable_reset(ht);

    return 1; /* never fails */
}

/* MurmurHash2, by Austin Appleby*/
unsigned int murmurhash2_hashfunction(const void *key, int len) {
    /* 'm' and 'r' are mixing constants generated offline.
       They're not really 'magic', they just happen to work well.  */
    uint32_t seed = 5363;
    const uint32_t m = 0x5bd1e995;
    const int r = 24;

    /* Initialize the hash to a 'random' value */
    uint32_t h = seed ^ len;

    /* Mix 4 bytes at a time into the hash */
    const unsigned char *data = (const unsigned char *)key;

    while(len >= 4) {
        uint32_t k = *(uint32_t*)data;

        k *= m;
        k ^= k >> r;
        k *= m;

        h *= m;
        h ^= k;

        data += 4;
        len -= 4;
    }

    /* Handle the last few bytes of the input array  */
    switch(len) {
        case 3: h ^= data[2] << 16;
        case 2: h ^= data[1] << 8;
        case 1: h ^= data[0]; h *= m;
    };

    /* Do a few final mixes of the hash to ensure the last few
     * bytes are well-incorporated. */
    h ^= h >> 13;
    h *= m;
    h ^= h >> 15;

    return (unsigned int)h;
}

void  hashtable_freeval(hashtable *htb, ht_node * he)
{
    if (he->valDestructor)
        he->valDestructor(he->val);
}
ht_node *hashtable_addraw(hashtable *htb, void *key)
{
    int index;
    ht_node *node;
    htable *ht;
    if (hashtable_isrehashing(htb))
        _hashtable_rehashstep(htb);

    if ((index = _hashtable_keyindex(htb, key)) == -1)
        return NULL;
    ht = hashtable_isrehashing(htb) ? &htb->ht[1] : &htb->ht[0];
    node = malloc(sizeof(*node));
    node->next = ht->table[index];
    ht->table[index] = node;
    ht->used++;
    hashtable_setkey(htb, node, key);
    return node;
}
ht_node *hashtable_find(hashtable *htb, const void *key)
{
    ht_node *he;
    unsigned int h, idx, table;
    if (htb->ht[0].size == 0) return NULL; /* We don't have a table at all */

    if (hashtable_isrehashing(htb)) _hashtable_rehashstep(htb);
    h = murmurhash2_hashfunction(key,strlen(key));
    for (table = 0; table <= 1; table++) {
        idx = h & htb->ht[table].sizemask;
        he = htb->ht[table].table[idx];
        while(he) {
            if (hashtable_comparekeys(htb, key, he->key))
                return he;
            he = he->next;
        }
        if (!hashtable_isrehashing(htb)) return NULL;
    }
    return NULL;
}



/*---------------API------------------------------*/
/* Create a new hash table */
hashtable *hashtable_create()
{
    hashtable *htb = malloc(sizeof(*htb));
    _hashtable_init(htb);
    return htb;
}

int hashtable_resize(hashtable *htb)
{
    int minimal;
    if (!hashtable_can_resize || hashtable_isrehashing(htb)) return 0;
    minimal = htb->ht[0].used;
    if (minimal < HTB_HT_INITIAL_SIZE)
        minimal = HTB_HT_INITIAL_SIZE;
    return hashtable_expand(htb, minimal);
}

int hashtable_expand(hashtable *htb, unsigned long size)
{
    htable n; /* the new hash table */

    unsigned long realsize = _hashtable_next_power(size);

    if (hashtable_isrehashing(htb) || htb->ht[0].used > size)
        return 0;

    n.size = realsize;
    n.sizemask = realsize-1;
    // T = O(N)
    n.table = calloc(1,realsize*sizeof(htable*));
    n.used = 0;

    if (htb->ht[0].table == NULL) {
        htb->ht[0] = n;
        return 1;
    }

    htb->ht[1] = n;
    htb->rehashidx = 0;
    return 1;
}

int hashtable_rehash(hashtable *htb, int n) {

    if (!hashtable_isrehashing(htb)) return 0;

    while(n--) {
        ht_node *de, *nextde;

        if (htb->ht[0].used == 0) {
            free(htb->ht[0].table);
            htb->ht[0] = htb->ht[1];
            _hashtable_reset(&htb->ht[1]);
            htb->rehashidx = -1;
            return 0;
        }
        /* Note that rehashidx can't overflow as we are sure there are more
         * elements because ht[0].used != 0 */
        assert(htb->ht[0].size > (unsigned)htb->rehashidx);

        while(htb->ht[0].table[htb->rehashidx] == NULL) htb->rehashidx++;

        de = htb->ht[0].table[htb->rehashidx];
        while(de) {
            unsigned int h;
            nextde = de->next;

            /* Get the index in the new hash table */
            h = murmurhash2_hashfunction(de->key,strlen(de->key)) & htb->ht[1].sizemask;

            de->next = htb->ht[1].table[h];
            htb->ht[1].table[h] = de;

            htb->ht[0].used--;
            htb->ht[1].used++;

            de = nextde;
        }
        htb->ht[0].table[htb->rehashidx] = NULL;
        htb->rehashidx++;
    }
    return 1;
}
/* Add an element to the target hash table 
 * The Last param is a function pointer used to free val of the node ,
 * if the val is not malloced, than pass NULL
 */
int hashtable_set(hashtable *htb, void *key, void *val,void (*valDestructor)(void *val))
{
    ht_node *node = hashtable_addraw(htb,key);
    if (!node)
        return 0;
    hashtable_setval(htb, node, val);
    node->valDestructor = valDestructor;
    return 1;
}

/* Search and remove an element */
int hashtable_delete(hashtable *htb, const void *key)
{
    unsigned int h, idx;
    ht_node *he, *prevHe;
    int table;
    if (htb->ht[0].size == 0) return 0; /* d->ht[0].table is NULL */
    if (hashtable_isrehashing(htb)) _hashtable_rehashstep(htb);

    h = murmurhash2_hashfunction(key,strlen(key));

    for (table = 0; table <= 1; table++) {
        idx = h & htb->ht[table].sizemask;
        he = htb->ht[table].table[idx];
        prevHe = NULL;
        while(he) {
            if (hashtable_comparekeys(htb, key, he->key)) {
                if (prevHe)
                    prevHe->next = he->next;
                else
                    htb->ht[table].table[idx] = he->next;
                hashtable_freeval(htb, he);
                free(he);
                htb->ht[table].used--;
                return 1;
            }

            prevHe = he;
            he = he->next;
        }
        if (!hashtable_isrehashing(htb)) break;
    }

    return 0; /* not found */
}

void hashtable_release(hashtable *htb)
{
    _hashtable_clear(htb,&htb->ht[0]);
    _hashtable_clear(htb,&htb->ht[1]);
    free(htb);
}
void hashtable_empty(hashtable *htb) {
    _hashtable_clear(htb,&htb->ht[0]);
    _hashtable_clear(htb,&htb->ht[1]);
    htb->rehashidx = -1;
}
void *hashtable_get(hashtable *htb, const void *key) {
    ht_node *he;
    he = hashtable_find(htb,key);
    return he ? hashtable_getval(he) : NULL;
}
