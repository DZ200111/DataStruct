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
//静态函数前置声明
static BSTNode* CreateNode(ELEMENTTYPE val, BSTNode *parentNode);
static BSTNode* CreateNode(ELEMENTTYPE val, BSTNode *parentNode)
{
    BSTNode *newNode = (BSTNode *)malloc(sizeof(BSTNode));
    if(newNode == NULL)
    {
        return MALLOC_ERROR;
    }
    memset(newNode, 0, sizeof(BSTNode));
    newNode->data = 0;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;

    newNode->data = val;
    newNode->parent = parentNode;
    return newNode;

}

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

    // bstree->root = (BSTree *)malloc(sizeof(BSTree));
    // if(bstree->root == NULL)
    // {
    //     return MALLOC_ERROR;
    // }
    // memset(bstree->root, 0 , sizeof(BSTree));
    
    // //初始化根结点
    // bstree->root->data = 0;
    // bstree->root->right = NULL;
    // bstree->root->left = NULL;
    // bstree->root->parent = NULL;
    bstree->root = CreateNode(0, NULL);

    *BStree = bstree;

    return ret;
}

//二叉搜索树的插入
int InsertBinarySearchTree(BSTree *BStree, ELEMENTTYPE val, int (*compareFunc)(ELEMENTTYPE, ELEMENTTYPE))
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
        cmp = compareFunc(val, travelNode->data);
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

    // BSTNode *newNode = (BSTNode *)malloc(sizeof(BSTNode));
    // if(newNode == NULL)
    // {
    //     return MALLOC_ERROR;
    // }
    // memset(newNode, 0, sizeof(BSTNode));
    // newNode->data = 0;
    // newNode->left = NULL;
    // newNode->right = NULL;
    // newNode->parent = NULL;

    // //新节点赋值
    // newNode->data = val;
    BSTNode *newNode = CreateNode(val, parentNode);

    if(cmp < 0)
    {
        parentNode->left = newNode;
    }
    else if(cmp > 0)      
    {
        parentNode->right = newNode;
    }
    BStree->size++;

    return ret;
}

static BSTNode * baseAppointValGetBSTNode(BSTree *BStree, ELEMENTTYPE val, int(*compareFunc)(ELEMENTTYPE, ELEMENTTYPE))
{
    BSTNode *travelNode = BStree->root;
    while(travelNode != NULL)
}
//二叉搜索树是否包含指定的元素
int IsBinarySearchTreeContainVal(BSTree *BStree, ELEMENTTYPE val)
{

}

//二叉搜索树的前序遍历
int PreTravelBinarySearchTree()
{

}

//二叉搜索树的中序遍历
int MidTravelBinarySearchTree()
{

}

//二叉搜索树的后序遍历
int PosTravelBinarySearchTree()
{

}

//二叉搜索树的层序遍历
int LevelTravelBinarySearchTree()
{

}
