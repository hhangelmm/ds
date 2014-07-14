#include "btree.h"
#include "lStack.h"
#include <stdlib.h>
#include <stdio.h>

BtreeNode* createNode( int data)
{
    BtreeNode *bnode;
    bnode = (BtreeNode*)malloc(sizeof(BtreeNode));
    if(!bnode)
        return 0;
    bnode->data = data;
    bnode->lchild = NULL;
    bnode->rchild = NULL;
    return bnode;
}
BtreeNode* makeBtree(int data, Btree lbtree,Btree rbtree)
{
    BtreeNode *bnode;
    bnode = (BtreeNode*)malloc(sizeof(BtreeNode));
    if(!bnode)
        return 0;
    bnode->data = data;
    bnode->lchild = lbtree;
    bnode->rchild = rbtree;
    return bnode;

}
void preOrder(Btree btree)
{
    if(btree->data)
        printf("%d\t",btree->data);
    if(btree->lchild)
        preOrder(btree->lchild);
    if(btree->rchild)
        preOrder(btree->rchild);
}
void spreOrder(Btree btree)
{
    LStack s;
    Btree bt = btree;
    while(bt || !IsEmpty(s)){
        if(bt){
            printf("%d\t",bt->data);
            Push(&s,bt);
            bt = bt->lchild;
        }else{
            Pop(&s,&bt);
            bt = bt->rchild;
        }
    }
}
void inOrder(Btree btree)
{
}
void sinOrder(Btree btree)
{
    LStack s;
    Btree bt = btree;
    InitStack(&s);
    while(bt || !IsEmpty(s)){
        if(bt ){
            Push(&s,bt);
            bt = bt->lchild;
        }else{
            Pop(&s,&bt);
            printf("%d\t",bt->data);
            bt = bt->rchild;
        }
    }
}
void postOrder(Btree btree)
{

}
void spostOrder(Btree btree)
{
}
