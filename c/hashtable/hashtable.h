#ifndef __HASH_TABLE_H
#define __HASH_TABLE_H

typedef struct ht_node {
    void *key;
    void *val;
    void (*valDestructor)(void *val);
    struct ht_node *next;
} ht_node;

typedef struct htable { 
    ht_node **table;
    unsigned long size;
    unsigned long sizemask;
    unsigned long used;
} htable;

typedef struct hashtable {
    htable ht[2];
    /* rehashing not in progress if rehashidx == -1 */
    int rehashidx;
} hashtable;

#define FORCE_INLINE    __forceinline
#define HTB_HT_INITIAL_SIZE     4
#define hashtable_isrehashing(ht) ((ht)->rehashidx != -1)
#define hashtable_setval(htb, node, _val_) do { \
    node->val = (_val_); \
} while(0)
#define hashtable_comparekeys(d, key1, key2) \
    ( (key1) == (key2))
#define hashtable_getkey(he) ((he)->key)
#define hashtable_getval(he) ((he)->val)
#define hashtable_setkey(d, entry, _key_) do { \
        entry->key = (_key_); \
} while(0)

ht_node *hashtable_addraw(hashtable *htb, void *key);
ht_node * hashtable_find(hashtable *htb, const void *key);
void  hashtable_freeval(hashtable *htb, ht_node * he);

/* API */
hashtable *hashtable_create();
int hashtable_resize(hashtable *htb);
int hashtable_expand(hashtable *htb, unsigned long size);
int hashtable_rehash(hashtable *htb, int n);
int hashtable_set(hashtable *htb, void *key, void *val, void (*valDestructor)(void *val));
int hashtable_delete(hashtable *htb, const void *key);
void hashtable_release(hashtable *htb);
void *hashtable_get(hashtable *htb, const void *key);
unsigned int murmurhash2_hashfunction(const void *buf, int len);
void hashtable_empty(hashtable *htb);

#endif /* __HASH_TABLE_H */
