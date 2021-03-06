#pragma once

#include "BinaryTree.h"
#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <stdlib.h>

typedef BTNode* QUDataType;

typedef struct QueueNode
{
	struct QueueNode* _next;
	QUDataType _data;
}QueueNode;

typedef struct Queue
{
	QueueNode* _front; // 队头
	QueueNode* _back;  // 队尾
}Queue;

void QueueInit(Queue* pq);//初始化队列
void QueueDestory(Queue* pq);//销毁队列
QueueNode* BuyQueueNode(QUDataType x);//开辟新结点
void QueuePush(Queue* pq, QUDataType x);//队尾加入新结点
void QueuePop(Queue* pq);//队头弹出元素
QUDataType QueueFront(const Queue* pq);//返回队头元素
int QueueEmpty(const Queue* pq);//判断队列是否为空
int QueueSize(const Queue* pq);//返回队列的大小
void TestQueue();//测试函数