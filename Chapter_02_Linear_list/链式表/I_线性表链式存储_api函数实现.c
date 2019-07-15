#include<stdio.h>
#include "stdlib.h"
#include "string.h"

#include "linklist.h"

//date:2019-07-12 15:00
//Author : null
//Project: 线性表链式存储 


typedef struct _tag_LinkList
{
	//这个句柄里面，需要保存所有节点信息。需要有一个起始点
	//就是带头节点的链表。。。	
	LinkListNode header;
	int length;
}TLinkList;

LinkList* LinkList_Create()
{
	TLinkList *ret = (TLinkList *)malloc(sizeof(TLinkList));

	if(ret == NULL)
	{
		return NULL;
	}

	//memset(ret,0,sizeof(TLinkList));

	ret->length = 0;
	ret->header.next = NULL;
	return ret;
}

void LinkList_Destroy(LinkList* list)
{
	if(list != NULL)
	{
		free(list);
		list = NULL;
	}
	return ;
}

//让链表恢复到初始化状态
void LinkList_Clear(LinkList* list)
{
	TLinkList *tList = NULL;
	if(list == NULL)
	{
		return ;
	}
	tList = (TLinkList *)list;

	tList->length = 0;
	tList->header.next = NULL;

	return ;
}

int LinkList_Length(LinkList* list)
{
	TLinkList *tList = (TLinkList *)list;
	if(list == NULL)
	{
		return -1;
	}

	return tList->length;
}

int LinkList_Insert(LinkList* list, LinkListNode* node, int pos)
{
	//向2 3号位置插入元素
	//因为链表是单向的，3号位置保存在2号位置的next域中

	//1、指针指向谁就把谁的地址赋给指针
	//2、分清楚 链表的操作逻辑 和 辅助指针变量 之间的关系
	
	/*
	1 node->next = current->next
	2 current->next = node;
	 */
	int i = 0;
	TLinkList *tList = NULL;
	LinkListNode *current = NULL;

	tList = (TLinkList *)list;

	//准备环境让辅助指针变量 指向链表头节点
	current =&(tList->header);
	if(list == NULL || node == NULL || pos < 0)
	{
		ret = 0;
		printf("fun LinkList_Insert() err:%d\n",ret);
		return NULL;
	}

	for(i = 0;i < pos && (current->next != NULL);i++)
	{
		current = current->next;
	}

	//1 让node连接后续链表
	node->next = current->next
	//2 让前面的链表 链接新的结点
	current->next = node;

	tList->length++;
	return 0;
}

LinkListNode* LinkList_Get(LinkList* list, int pos)
{
	int i = 0;
	TLinkList *tList = NULL;
	LinkListNode *current = NULL;
	LinkListNode *ret = NULL;

	tList = (TLinkList *)list;
	if(list == NULL || pos < 0 || pos>=tList->length)
	{
		return NULL;
	}


	current =&(tList->header;);//让辅助指针变量指向链表的头部 

	for(i = 0;i < pos && (current->next != NULL);i++)//跳pos次
	{
		current = current->next;
	}
	ret = current->next

	return ret;

}

LinkListNode* LinkList_Delete(LinkList* list, int pos)
{
	int i = 0;
	TLinkList *tList = NULL;
	LinkListNode *ret = NULL;
	LinkListNode *current = NULL;

	tList = (TLinkList *)list;

	if(list == NULL || pos < 0)
	{
		printf("fun LinkList_Delete() err:%d\n",ret);
		return NULL;
	}


	current =&(tList->header);//让辅助指针变量指向链表的头部 

	for(i = 0;i < pos && (current->next != NULL);i++)//跳pos次
	{
		current = current->next;
	}

	//缓存背删除的结点位置
	ret = current->next;

	//连线
	current->next = ret->next;

	tList->length--;
	return ret;	
}

