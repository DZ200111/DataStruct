#ifndef __DOUBLELINKLIST_H_
#define __DOUBLELINKLIST_H_
#include <stdbool.h>

#define ELEMENTTYPE int

struct Node
{
    ELEMENTTYPE data; //数据域
    struct Node *prev; //前驱指针
    struct Node *next; //指针域 指向下一个结点的地址
};
typedef struct Node Node;

struct DoubleLinkList
{
    struct Node *head; //头指针 指向头结点（不放数据）
    struct Node *tail; //尾指针 不用分配空间，作指针用
    int len;  //链表长度
};
typedef struct DoubleLinkList DLlist;
//初始化双链表
void InitLinkList(DLlist *list);

//双链表尾插
int InsertDLlistTail(DLlist *list, ELEMENTTYPE element);

//双链表头插
int InsertDLlistHead(DLlist *list, ELEMENTTYPE element);

//双链表中间插入
int InsertDLlistByIndex(DLlist *list, int Index, ELEMENTTYPE element);

//链表头删
int LinkListHeadDel(DLlist *list);

//链表尾删
int LinkListTailDel(DLlist *list);

//链表中间删
int LinkListIndexDel(DLlist *list, int Index);

//链表删除指定的数据
int LinkListDelData(DLlist *list, ELEMENTTYPE element, int(*compare)(ELEMENTTYPE, ELEMENTTYPE));

//获取链表的长度
int LinkListGetLen(DLlist *list, int *pSize);

//链表销毁
int FreeLinkList(DLlist *list);

//链表遍历
int TravelLinkList(DLlist  *list, int(*printFunc)(ELEMENTTYPE));


typedef struct DoubleLinkList DDLlist;

#endif