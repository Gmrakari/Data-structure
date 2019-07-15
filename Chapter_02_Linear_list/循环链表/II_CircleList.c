#include <stdio.h>
#include <malloc.h>
#include "CircleList.h"
/*

date:2019-07-15 10:23
Author : null
Project: CircleList

*/


typedef struct _tag_CircleList
{
	CircleListNode header;
	CircleListNode* slider;
	int length;
}TCircleList;

//对比线性表 循环链表多了一个slider 
/*
typedef struct _tag_LinkList
{
	//这个句柄里面，需要保存所有节点信息。需要有一个起始点
	//就是带头节点的链表。。。	
	LinkListNode header;
	int length;
}TLinkList;
*/

CircleList* CircleList_Create()
{
	TCircleList* ret = (TCircleList *)malloc(sizeof(TCircleList));

	if(ret == NULL)
	{
		return NULL;
	}

	ret->length = 0;
	ret->header.next = NULL;
	ret->slider = NULL;
	return ret;
}


void List_Destroy(CircleList* list)
{
	if(list != NULL)
	{
		free(list);
		list = NULL;
	}
	return ;
}



void CircleList_Clear(CIRcleList* list)
{
	TCircleList *sList = NULL;
	if(list == NULL)
	{
		return;
	}
	sList = (TCircleList *)list;

	sList->length = 0;
	sList->header.next = NULL;
	sList->slider = NULL;

	return ;
}

int CircleList_Length(CircleList* list)
{
	TCircleList* sList = (TCircleList*)list;
	int ret = -1;

	if(list == NULL)
	{
		return ret;
	}
	ret = sList->length;

	return ret;
}

int CircleList_Insert(CircleList* list,CircleListNode* node,int pos)
{
	int i = 0 , ret = 0;
	TCircleList *sList = (TCircleList *)list;

	if(list == NULL || node == NULL || pos < 0)
	{
		return -1;
	}
	//if(ret)
	{
		CircleListNode *current = (CircleListNode *)sList;

		for(i = 0;(i < pos) && (current->next != NULL);i++)
		{
			current = current->next;
		}

		//current->next  0号结点的地址
		
		node->next = current->next;//1
		current->next = node;//2
		//看下面第三步 思考为什么?
		//画图 知道，如果用头插法，插入的节点，未知尾节点，所以导致尾节点不能连接到链表上，不能形成一个循环链表
		//所以，要先用CircleListNode* CircleList_Get(CIrcleList* list,int pos),求出尾节点的位置
		//就变成普通的插入了，让新节点指向0号位置的结点，尾节点指向新插入的结点，这样才能形成循环链表
		

		//上面都与链表的操作一样，下面是循环链表的不同点
		
		//若第一次插入节点
		if(sList->length == 0)
		{
			sList->slider = node;
		}

		sList->length++;

		//若头插法 current仍然指向头部
		//（原因是：跳0步，没有跳走）
		if(current == (CircleListNode *)sList)
		{
			//获取最后一个元素
			CircleListNode* last = CircleList_Get(sList,sList->length -1);
			last->next = current->next;//3
		}
	}
	return ret;
}

CircleListNode* CircleList_Get(CircleList* list,int pos)
{
	TCircleList* sList = (TCircleList*)list;
	CircleListNode* ret = NULL;

	int i = 0;

	if(list == NULL || pos < 0)
	{
		return NULL;
	}

	//if((sList != NULL) && (pos >= 0) && (sList->length > 0))
	{
		CircleListNode* current = (CircleListNode*)sList;

		for(i = 0;i < pos;i++)
		{
			current = current->next;
		}
		ret = current->next;
	}
	return ret;
}

CircleListNode* CircleList_Delete(CircleList* list,int pos)
{
	TCircleList* sList = (TCircleList*)list;
	CircleListNode* ret = NULL;

	int i = 0;

	if((sList != NULL) && (pos >= 0) && (sList->length > 0))
	{
		CircleListNode* current = (CircleListNode*)sList;//==>CircleListNode* current =(CircleListNode*)(&(sList->header));
		CIrcleListNode* last = NULL;

		for(i = 0;i < pos;i++)
		{
			current = current->next;
		}

		//若删除第一个元素 （头节点）
		if(current == (CIrcleListNode*)sList)
		{
			last = (CircleListNode*)CircleList_Get(sList,sList->length -1 );

		}

		//要求删除的元素
		ret = current->next;
		current->next = ret->next;

		sList->length--;

		//判断链表是否为空
		
		if(last != NULL)
		{
			sList->head.next = ret->next;
			last->next = ret->next;
		}

		//若删除的元素为游标所指的元素
		if(sList->slider == ret)
		{
			sList->slider = ret->next;
		}

		//若删除元素后，链表长度为0
		if(sList->length == 0)
		{
			sList->header.next = NULL;
			sList->slider = NULL;
		}
	}
	return ret;
}

//new add

//直接指定删除链表中的某个数据
CircleListNode* CircleList_DeleteNode(CircleList* list,CircleListNode* node)
{
	TCircleList* sList = (TCircleList*)list;
	CIrcleListNode* ret = NULL;
	int i = 0;

	if(sList != NULL)
	{
		CircleListNode* current = (CircleListNode *)sList;

		//查找node在循环链表中的位置i
		for(i = 0;i < sList->length;i++)
		{
			if(current->next == node)
			{
				ret = current->next;
				break;
			}
			current = current->next;
		}

		//如果ret找到,根据i去删除元素
		if(ret != NULL)
		{
			CircleList_Delete(sList,i);
		}
		return ret;
	}
}

//将游标重置指向链表中的第一个数据元素
CircleListNode* CircleList_Reset(CircleList* list)
{
	TCircleList* sList = (TCircleList*)list;
	CircleListNode* ret = NULL;

	if(sList != NULL)
	{
		sList->slider = sList->header.next;
		ret = sList->slider;
	}

	return ret;
}

//获取当前游标指向的数据元素
CircleListNode* CircleList_Current(CircleList* list)
{
	TCircleList* sList = (TCircleList*)list;
	CircleListNode* ret = NULL;

	if(sList != NULL)
	{
		ret = sList->slider;
	}
	return ret;
}

//将游标移动指向到链表中的下一个数据元素
CircleListNode* CircleList_Next(CircleList* list)
{
	TCircleList* sList = (TCircleList*)list;
	CircleListNode* ret = NULL;

	if((sList != NULL) && (sList->slider != NULL))
	{
		ret = sList->slider;
		sLIst->slider = ret->next;
	}
	return ret;
}