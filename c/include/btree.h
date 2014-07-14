#ifndef BTREE_H
#define BTREE_H

typedef struct BtreeNode{
    int data;
    struct BtreeNode *lchild,*rchild;
} BtreeNode,*Btree;

BtreeNode* createNode(int data);
BtreeNode* makeBtree(int data, Btree lbtree,Btree rbtree); 
void preOrder(Btree btree);
void spreOrder(Btree btree);
void inOrder(Btree btree);
void sinOrder(Btree btree);
void postOrder(Btree btree);
void spostOrder(Btree btree);
#endif
