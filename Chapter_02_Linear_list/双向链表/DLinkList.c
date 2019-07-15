/*

date:2019-07-15 16：34
Author : null
Project: DLinkList 

*/

#include <stdio.h>
#include <malloc.h>
#include "DLinkList.h"

typedef struct _tag_DLinkList
{
	DLinkListNode header;
	DLinkListNOde* slider;
	int length;
}TDLinkList;

DLinkList* DLinkList_Create()
{
	TDLinkList* ret = (TDLinkList*)malloc(sizeof(TDLinkList));

	if(ret != NULL)
	{
		ret->lenth = 0;
		ret->header.next = NULL;
		ret->header.pre = NULL;
		ret->slider = NULL;
	}
	return ret;
}

void DLinkList_Destroy(DLinkList* list) 
{
	if (list != NULL)
	{
		free(list);
	}
}

void DLinkList_Clear(DLinkList* list)
{
	TDLinkList* sList = (TDLinkList *)list;

	if(sList != NULL)
	{
		sList->length = 0;
		sList->header.next = NULL;
		sList->header.pre = NULL;
		sList->sList = NULL;
	}
}

int DLinkList_Length(DLinkList* list)
{
	TDLinkList* sList = (TDLinkList *)list;
	int ret = -1;

	if( sList != NULL)
	{
		ret = sList->length;
	}
	return ret;
}


int DLinkList_Insert(DLinkList* list,DLinkListNode* node,int pos)
{
	int ret = 0,i = 0;
	TDLinkList* sList = (TDLinkList*)list;

	if(list == NULL || node == NULL || pos < 0)
	{
		return -1;
	}

	{
		DLinkListNode* current = (DLinkListNode*)sList;
		DLinkListNode* next = NULL;

		for(i = 0;(i < pos )&& (current->next != NULL);i++)
		{
			current = current->next;
		}
		next = current->next;

		//step one - two 
		current->next = node;
		node->next = next;

		//step three-four
		if(next != NULL) // when dlink insert the first element,we need speical operate
		{
			next->pre = node;
		}
		node->pre = current;

		if(sList->length == 0)
		{
			sList->slider = node;//当链表插入第一个元素 处理游标
		}

		//if insert the element into the '0'position
		//need to speical operate 
		//the new node 'next' pre point to null	
		if(current == (DLinkListNode*)sList)
		{
			node->pre = NULL;
		}
		sList->length++;
	}
	return ret;
}


DLinkListNode* DLinkList_Get(DLinkList* list,int pos)
{
	TDLinkList* sList = (TDLinkList*)list;
	DLinkListNode* ret = NULL;
	int i = 0;

	if((sList != NULL) && (0 <= pos) && (pos < sList->length))
	{
		DLinkListNode* current = (DLinkListNode *)sList;
		for(i = 0;i < pos;i++)
		{
			current = current->next;
		}
		ret = current->next;
	}
	return ret;
}

//插入第一个结点
//删除的式最后一个结点，该如何处理
DLinkListNode* DLinkList_Delete(DLinkList* list,int pos)
{
	TDLinkList* sList = (TDLinkList*)list;
	DLinkListNode* ret = NULL;
	int i = 0;
	if(sList == NULL || pos < 0)
	{
		return NULL;
	}

	//if((sList != NULL) && (0 <= pos ) && (pos < sList->length))
	{
		DLinkListNode* current = (DLinkLIstNode *)sList;
		DLinkListNode* next = NULL;

		for(i = 0;i < pos;i++)
		{
			current = current->next;
		}

		ret = current->next;
		next = ret->next;

		//setp1
		current->next = next;

		//setp2
		if(next != NULL)
		{
			next->pre = current;

			if(current ==(DLinkListNode*)sList)
			{
				next->pre = NULL;
			}
		}

		if(sList->slider == ret)
		{
			sList->slider = next;
		}

		sList->length--;
	}
	return ret;
}


//new add
DLinkListNode* DLinkList_DeleteNode(DLinkList* list,DLinkListNode* node)
{
	TDLinkList* sList = (TDLinkList*)list;
	DLInkListNode* ret = NULL;
	int i = 0;

	if( sList != NULL)
	{
		DLinkListNode* current = (DLinkListNode*)list;

		for(i = 0; i < sList->length;i++)
		{
			if(current->next == node)
			{
				ret = current->next;
				break;
			}
			current = current->next;
		}
		if( ret != NULL)
		{
			DLinkList_Delete(sList,i);
		}
	}
	return ret;
}

DLinkListNode* DLinkList_Reset(DLinkList* list)
{
	TDLinkList* sList = (TDLinkList*)list;
	DLinkListNode* ret = NULL;

	if(sList != NULL)
	{
		sList->slider = sList->header.next;
		ret= sList->slider;
	}
	return ret;
}

DLinkListNode* DLinkList_Current(DLinkList* list)
{
	TDLinkList* sList = (TDLinkList*)list;
	DLinkListNode* ret = NULL;

	if(sList != NULL)
	{
		ret = sList->slider;
	}
	return ret;
}

DLinkListNode* DLinkList_Next(DLinkList* list)
{
	TDLinkList* sList = (TDLinkList *)list;
	DLinkListNode* ret = NULL;

	if((sList != NULL) && (sLIst->slider != NULL))
	{
		ret = sList->slider;
		sList->slider = ret->next;
	}
}

DLinkListNode* DLinkList_Pre(DLinkList* list)
{
	TDLinkList* sList = (TDLinkList *)list;
	DLinkListNode* ret = NULL;

	if((sList != NULL) && (sList->slider != NULL))
	{
		ret = sList->slider;
		sList->slider = ret->pre;
	}	
	return ret;
}
