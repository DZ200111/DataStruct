#ifndef __BINARY_SEARCH_TREE_H_
#define __BINARY_SEARCH_TREE_H_

#define ELEMENTTYPE int

struct BSTreeNode
{
    ELEMENTTYPE data;
    struct BSTreeNode *left; //左子树
    struct BSTreeNode *right;  //右子树
    
    struct BSTreeNode *parent;  //双亲结点
};
typedef struct BSTreeNode BSTNode;

struct BinarySearchTree
{
    BSTNode *root;  //根节点
    int size;  //结点个数

};
typedef struct BinarySearchTree BSTree;

//初始化树
int InitBinarySearchTree(BSTree **BStree);

//二叉搜索树的插入
int InsertBinarySearchTree(BSTree *BStree, ELEMENTTYPE val, int(*compareFunc)(ELEMENTTYPE, ELEMENTTYPE));

//二叉搜索树的前序遍历
int PreTravelBinarySearchTree();

//二叉搜索树的中序遍历
int MidTravelBinarySearchTree();

//二叉搜索树的后序遍历
int PosTravelBinarySearchTree();

//二叉搜索树的层序遍历
int LevelTravelBinarySearchTree();


#endif