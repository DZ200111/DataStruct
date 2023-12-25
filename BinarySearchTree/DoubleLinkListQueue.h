#ifndef __DOUBLELINKLISTQUEUE_H_
#define __DOUBLELINKLISTQUEUE_H_
#include "DoubleLinkList.h"

typedef DLlist DLlistQueue;
//队列初始化
int doubleLinkListQueueInit(DLlistQueue *queue);

//队列入队
int doubleLinkListQueuePush(DLlistQueue *queue, ELEMENTTYPE val);

//队头元素
int doubleLinkListQueueTop(DLlistQueue *queue, ELEMENTTYPE val);

//队尾元素
int doubleLinkListQueueRear(DLlistQueue *queue, ELEMENTTYPE val);

//队列出队
int doubleLinkListQueuePop(DLlistQueue *queue);

//队列大小
int doubleLinkListQueueGetSize(DLlistQueue *queue, int *pSize);

//队列是否为空
int doubleLinkListQueueIsEmpty(DLlistQueue *queue);

//队列销毁
int doubleLinkListQueueDestroy(DLlistQueue *queue);

#endif