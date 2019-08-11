# pragma warning (disable:4819)
#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include "stdlib.h"
#include "string.h"

#include "linklist.h"
#include "linkqueue.h"

//date:2019-08-11 14：30
//Author : null
//Project: LinkQueue_API_Realize

//队列使一种特殊的线性表

//队列的业务结点的数据结构
typedef struct _tag_LinkQueueNode
{
	LinkListNode node;
	void *item;
}TLinkQueueNode;


//创建队列 相当于 创建线性表
LinkQueue* LinkQueue_Create()
{
	return LinkList_Create();
}

//销毁队列 相当于 销毁 线性表
//结点的内存管理
void LinkQueue_Destroy(LinkQueue* queue)
{
	LinkQueue_Clear(queue);
	LinkQueue_Destroy(queue);
}

//如果清空队列 需要显示的把队列中的所有结点 搞出来
//释放每一个结点
void LinkQueue_Clear(LinkQueue* queue)
{
	while(LinkQueue_Length(queue) > 0)
	{
		LinkQueue_Retrieve(queue);
	}
	LinkQueue_Clear(queue);
	return ;
}

//向队列中添加元素 相当于 向线性表的尾部添加元素
int LinkQueue_Append(LinkQueue* queue, void* item)
{
	int ret = 0;
	TLinkQueueNode *node = NULL;

	node = (TLinkQueueNode *)malloc(sizeof(TLinkQueueNode));
	if(node == NULL)
	{
		ret = -1;
		printf("func LinkQueue_Append（） malloc error:%d\n",ret);
		return ret;
	}
	memset(node,0,sizeof(TLinkQueueNode));
	node->item = item;
/*	tmp->node.next = NULL;*/ //初始化

	//需要把栈的item(栈的业务结点)  转换成链表的 LinkListNode
	ret = LinkList_Insert(queue, (LinkListNode *)node, LinkList_Length(queue));
	if(ret != 0)
	{
		printf("func LinkList_Insert() error:%d\n",ret);
		if(node != NULL)
		{
			free(node);
		}
	}
	return ret;
}

//从队列中删除元素 相当于 从线性表的头部删除元素
void* LinkQueue_Retrieve(LinkQueue* queue)
{
	TLinkQueueNode *ret = NULL;
	TLinkQueueNode *tmp = NULL;
	tmp = (TLinkQueueNode *)LinkList_Delete(queue,0);

	if(tmp == NULL)
	{
		printf("func LinkList_Delete() error");
		return NULL;
	}

	//删除之前缓存
	ret = tmp->item;

	if(tmp != NULL)
	{
		free(tmp);
	}
	return ret;
}

//获取队列头部元素 相当于 从线性表0号位置 拿数据
void* LinkQueue_Header(LinkQueue* queue)
{
	TLinkQueueNode *tmp = NULL;
	void *ret = NULL;

	tmp = (TLinkQueueNode *)LinkList_Get(queue,0);

	if(tmp == NULL)
	{
		printf("func LinkList_Get error");
		return NULL;
	}

	return tmp->item;
}

//求队列的长度 相当于 求线性表的长度
int LinkQueue_Length(LinkQueue* queue)
{
	return LinkList_Length(queue);
}

