#include "DoubleLinkList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int LinkListGetIndex(DLlist *list, ELEMENTTYPE element, int *pPos, int (*compare)(ELEMENTTYPE, ELEMENTTYPE));
static struct Node * CreateNode(ELEMENTTYPE element);

enum STATUS_CODE
{
    NOT_FOUND = -1,
    ON_SUCCESS,
    NULL_PTR,
    MALLOC_ERROR,
    INVALID_ACCESS,
};

//创建结点
Node * CreateNode(ELEMENTTYPE element)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if(!newNode)
    {
        return MALLOC_ERROR;
    }
    memset(newNode, 0, sizeof(Node));
    
    newNode->data = element;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
} 

//初始化双链表
void InitLinkList(DLlist *list)
{
    list->head = (Node *)malloc(sizeof(Node));
    if(list->head == NULL)
    {
        printf("malloc failed\n");
        return;
    }
    memset(list->head, 0, sizeof(Node));
    //链表头结点不放数据，初始化为0
    list->head->data = 0;

    list->head->next = NULL;
    list->head->prev = NULL;
    //初始化的时候尾指针 = 头指针
    list->tail = list->head;
    list->len = 0;
    
}

//双链表尾插
int InsertDLlistTail(DLlist *list, ELEMENTTYPE element)
{
   return InsertDLlistByIndex(list, list->len, element);
}

//双链表头插
int InsertDLlistHead(DLlist *list, ELEMENTTYPE element)
{
    return InsertDLlistByIndex(list, 0, element);
}

//双链表中间插入
int InsertDLlistByIndex(DLlist *list, int Index, ELEMENTTYPE element)
{
    if(list == NULL)
    {
        return NULL_PTR;
    }
    
    if(Index < 0 || Index > list->len)
    {
        return INVALID_ACCESS;
    }

    //封装结点
    Node *newNode = CreateNode(element);
    if(newNode == NULL)
    {
        return MALLOC_ERROR;
    }
     
    //遍历
    Node *travelNode = list->head;

    int flag = 0;
    //这种情况标记尾指针
    if(Index == list->len)
    {
         travelNode = list->tail;

         flag = 1;
    }
    else
    {
        while(Index)
        {
            travelNode = travelNode->next;
            Index--;
        }
        /*问题在于当尾插的时候travelNode->next是一个NULL没有前驱,
        所以把traveNode->next->prev = newNode提到不是尾插的情况中。*/
        travelNode->next->prev = newNode; 
    }
    newNode->next = travelNode->next;
    newNode->prev = travelNode;
    //travelNode->next->prev = newNode;
    travelNode->next = newNode;

     //更改尾指针
    if(flag)
    {
        list->tail = newNode;
    }

    list->len++;

    return ON_SUCCESS;

}

//获取链表长度
int LinkListGetLen(DLlist *list, int *pSize)
{
    if(list == NULL)
    {
        return NULL_PTR;
    }

    if(pSize)
    {
        *pSize = list->len;
    }

    return list->len;
}

//顺序遍历链表
int TravelLinkList(DLlist *list, int (*printFunc)(ELEMENTTYPE))
{
    if(list == NULL)
    {
        return NULL_PTR;
    }

    Node *travelNode = list->head;
    while(travelNode->next != NULL)
    {
        travelNode = travelNode->next;
        /*包装器 钩子 回调函数*/
        printFunc(travelNode->data); 
    }
    
    /*
      Node *travelNode = list->head->next;
    while(travelNode != NULL)
    {
        printf("travelNode->data:%d\n", travelNode->data);
        travelNode = travelNode->next;
    }
    */
    return ON_SUCCESS;
}

//逆序遍历链表
int ReverseTravelList(DLlist *list, void(*printFunc)(ELEMENTTYPE element))
{
    if(!list)
    {
        return NULL_PTR;
    }

    Node *travelNode = list->tail;

    while(travelNode->prev != list->head)
    {
        printFunc(travelNode->data);
        travelNode = travelNode->prev;
    }

    return ON_SUCCESS;    
}
//链表遍历
// int TravelLinkList1(DLlist  *list)
// {
//     if(list == NULL)
//     {
//         return NULL_PTR;
//     }

//     Node *travelNode = list->head;
//     while(travelNode->next != NULL)
//     {
//         travelNode = travelNode->next;
//         printf("travelNode->data:%d\n",travelNode->data);
//     }
//     return ON_SUCCESS;
// }

//链表头删
int LinkListHeadDel(DLlist *list)
{
    return LinkListIndexDel(list, 1);
}

//链表尾删
int LinkListTailDel(DLlist *list)
{
     return LinkListIndexDel(list, list->len);
}

//链表中间删
int LinkListIndexDel(DLlist *list, int Index)
{
    if(list == NULL)
    {
        return NULL_PTR;
    }

    if(Index <= 0 || Index > list->len)
    {
        return INVALID_ACCESS;
    }

    Node *travelNode = list->head;
    int flag = 0;
    //需要修改尾指针
    if(Index == list->len)
    {
        flag = 1;
    }
    else
    {
      while(--Index)
      {
          travelNode = travelNode->next;
      }
      travelNode->next->prev = travelNode->prev;
    }
    travelNode->prev->next = travelNode->next;
    
    if(flag)
    {
        /*调整尾指针*/
        list->tail = travelNode->prev;
    }
    
    //释放内存
    if(travelNode != NULL)
    {
        free(travelNode);
        travelNode = NULL;
    }
    
    list->len--;

    return ON_SUCCESS;
}

//链表销毁
int FreeLinkList(DLlist *list)
{
    int size = 0;
    while(LinkListGetLen(list, &size))
    {
        LinkListHeadDel(list);
    }

    if(list->head != NULL)
    {
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
    }

    return ON_SUCCESS;
}

static int LinkListGetIndex(DLlist *list, ELEMENTTYPE element, int *pPos, int (*compare)(ELEMENTTYPE, ELEMENTTYPE))
{
    /*静态函数只能在本源文件使用*/
    int Index = 1;
    Node *travelNode = list->head->next;
    while(travelNode != NULL)
    {
        if(compare(element, travelNode->data) == 0)
        {
            *pPos = Index;
            return Index;
        }
        travelNode = travelNode->next;
        Index++;
    }
    //解引用
    *pPos = NOT_FOUND;
    return NOT_FOUND;
}

//链表删除指定的数据
int LinkListDelData(DLlist *list, ELEMENTTYPE element, int (*compare)(ELEMENTTYPE, ELEMENTTYPE))
{
    
    int pos = 0;  //元素在链表中的位置
    int size = 0;
    while(LinkListGetLen(list, &size) && pos != NOT_FOUND)
    {
        LinkListIndexDel(list, LinkListGetIndex(list, element, &pos, compare));
    }
    
    return ON_SUCCESS;
}

//双链表按位置修改
bool UpdataDLlistByIndex(DLlist *list, int Index, ELEMENTTYPE element)
{
     
     if(list == NULL)
     {
        return false;
     }
     if(Index < 0 || Index > list->len)
     {
        printf("访问位置非法!\n");
        return false;
     }
     
     Node *travelNode = list->head->next;
     while(--Index)
     {
        travelNode = travelNode->next;     
     }
     travelNode->data = element;
     return true;
}
