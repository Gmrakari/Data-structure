/*
 *Date:2019-07-17 16:43
 *Author:null
 *Project:linkstack_API
 *
*/

/*
Review and go on leaning 2019-07-18 09:35
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "I_linkstack.h"
#include "II_II_linklist.h" 

typedef struct Teacher//链表的业务结点
{
	LinkListNode node;//第一个域（第一个元素）
	void* item;//栈的业务结点
}Teacher;

typedef struct _tag_LinkStackNode//链表的业务结点
{
	LinkListNode node;//第一个域（第一个元素）
	void* item;//栈的业务结点
}TLinkStackNode;


//创建栈 相当于 创建一个线性表
LinkStack* LinkStack_Create()
{
	return NULL;
}

// 销毁一个栈 相当于 销毁一个线性表
void LinkStack_Destroy(LinkStack* stack)
{
	LinkStack_Clear(stack);
	LinkList_Destory(stack);
	return ;
}

// 清空一个栈 相当于 清空一个线性表
// 清空栈的时候 涉及到栈元素 生命周期的管理
// 
// 所有入站的结点都是malloc
// 若要清空栈 把栈中元素弹出 栈元素生命周期的管理
void LinkStack_Clear(LinkStack* stack)
{
	if(stack == NULL)
	{
		return ;
	}
	while(LinkList_Lengtn(stack) > 0)//LinkStack_Size
	{
		LinkStack_Pop(stack);//释放结点的内存
	}
	return ;
}

//向栈中 添加元素 相当于 向线性表的头部插入元素
//void* item 栈的业务结点 ====>  转换成 链表的业务结点 
int LinkStack_Push(LinkStack* stack, void* item)
{
	TLinkStackNode *tmp = NULL;
	int ret = 0;
	tmp = (TLinkStackNode *)malloc(sizeof(TLinkStackNode));

	if(tmp == NULL)
	{
		return -1;
	}
	memset(tmp.0,sizeof(TLinkStackNode));
	tmp->item = item;

	//int LinkList_Insert(LinkList* list, LinkListNode* node, int pos);
	ret = LinkList_Insert(stack,(LinkListNode *)tmp,0);
	if(ret != 0)
	{
		printf("fun LinkList_Insert()err:%d",ret);
		if(tmp != NULL)
		{
			free(tmp);
		}
	}
	return 0;
}

//从栈中弹出元素，相当于 从线性表的头部删除元素
void* LinkStack_Pop(LinkStack* stack)
{
	TLinkStackNode *tmp = NULL;
	void *item = NULL;//栈的业务结点
	tmp = (TLinkStackNode *)LinkList_Delete(stack,0);
	if(tmp == NULL)
	{
		return NULL;
	}
	item = tmp->item;
	//因为LinkList_Insert的时候 分配了内存 所以LinkList_Delete 释放内存
	free(tmp);
	return item;
}

//获取栈顶元素 相当于 获取线性表0号位置
void* LinkStack_Top(LinkStack* stack)
{
	TLinkStackNode *tmp = NULL;
	tmp = (TLinkStackNode *)LinkList_Get(stack,0);

	if(tmp == NULL)
	{
		return NULL;
	}
	return tmp->item;
}

//求栈的大小 相当于 求 线性表的length
int LinkStack_Size(LinkStack* stack)
{
	return LinkList_Lengtn(stack);
}
