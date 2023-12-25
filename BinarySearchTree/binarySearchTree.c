#include "binarySearchTree.h"
#include <stdio.h>
#include <stdlib.h>

enum STATUS_CODE
{
    NOT_FOUND = -1,
    ON_SUCCESS,
    NULL_PTR,
    MALLOC_ERROR,
    INVALID_ACCESS,
};

//初始化树
int InitBinarySearchTree(BSTree **BStree)
{
    int ret = 0;
    BSTree *bstree = (BSTree *)malloc(sizeof(BSTree));
    if(!bstree)
    {
        return MALLOC_ERROR;
    }
    memset(bstree, 0, sizeof(BSTree));
    //初始化树
    bstree->root = NULL;
    bstree->size = 0;

    bstree->root = (BSTree *)malloc(sizeof(BSTree));
    if(bstree->root == NULL)
    {
        return MALLOC_ERROR;
    }
    memset(bstree->root, 0 , sizeof(BSTree));
    
    //初始化根结点
    bstree->root->data = 0;
    bstree->root->right = NULL;
    bstree->root->left = NULL;
    bstree->root->parent = NULL;

    *BStree = bstree;

    return ret;
}

//二叉搜索树的插入
int InsertBinarySearchTree(BSTree *BStree, ELEMENTTYPE val)
{
    int ret = 0;
    //空树
    if(BStree->size == 0)
    {
        //更新树的结点
        BStree->size++;

        BStree->root->data = val;
        return ret;
    }
    
    BSTNode *travelNode = BStree->root;
    BSTNode *parentNode = BStree->root; 

    int cmp = 0;
    
    while(travelNode != NULL)
    {
        //标记父节点
        parentNode = travelNode;
        cmp = val - travelNode->data;
        if(cmp < 0)
        {
            travelNode = travelNode->left;
        }
        else if(cmp > 0)
        {
            travelNode = travelNode->right;
        }
        else
        {
            //插入元素与遍历到的元素相等
            return ret;
        }
    }
    if(cmp < 0)
    {
        parentNode->left = 
    }
}