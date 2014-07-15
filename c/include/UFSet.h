/*
 * 并查集
 */
#ifndef UFSET_H
#define UFSET_H

#define MAX_TREE_SIZE 100

typedef struct PTNode{
    int data;
    struct PTNode *parent;
}PTNode;

typedef struct {
    PTNode nodes[MAX_TREE_SIZE];
    int r,n; //根的位置和节点数
}UFSet;


#endif
