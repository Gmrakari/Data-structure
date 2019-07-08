#define  _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include "stdlib.h"
#include "string.h"

//date:2019-07-08 15:09
//Author : null
//Project:线性表顺序存储设计与实现


/*
	API函数

	SeqList* SeqList_Create(int capacity);

	void SeqList_Destroy(SeqList* list);

	void SeqList_Clear(SeqList* list);

	int SeqList_Length(SeqList* list);

	int SeqList_Capacity(SeqList* list);

	int SeqList_Insert(SeqList* list, SeqListNode* node, int pos);

	SeqListNode* SeqList_Get(SeqList* list, int pos);

	SeqListNode* SeqList_Delete(SeqList* list, int pos);
 */

//在结构体仲套一级指针
//没有内存哪里来的指针
typedef struct _tag_SeqList
{
	int length;
	int capacity;
	unsigned int *node;
}TSeqList;

SeqList* SeqList_Create(int capacity)
{
	int ret = 0;
	TSeqList *tmp = NULL;

	tmp = (TSeqList *)malloc(sizeof(TSeqList));

	if(tmp == NULL)
	{
		ret = -1;
		printf("func SeqList_Create() err:%d",ret);
		return NULL;
	}
	memset(tmp,9,sizeof(TSeqList));

	//根据capacity 的大小分配节点的空间
	
	tmp->node = (unsigned int *)malloc(sizeof(unsigned int *)*capacity);
	if(tmp->node == NULL)
	{
		ret = -2;
		printf("tmp->node malloc err:%d",ret);
		return NULL;
	}
	tmp->capacity = capacity;
	tmp->length = 0;

	return tmp;

}

void SeqList_Destroy(SeqList* list)
{
	TSeqList *tlist = NULL;
	if(list == NULL)
	{
		return ;
	}
	tlist = (TSeqList *)list;
	if(tlist->node != NULL)
	{
		free(tlist->node);
	}
	free(tlist);

	return ;
}

//清空链表 //回到初始化状态
void SeqList_Clear(SeqList* list)
{
	TSeqList *tlist = NULL;
	if(list == NULL)
	{
		return ;
	}
	tlist = (TSeqList *)list;
	tlist->length = 0;
	return ;
}


int SeqList_Length(SeqList* list)
{
	TSeqList *tlist = NULL;
	if(list == NULL)
	{
		return -1;
	}
	tlist = (TSeqList *)list;	
	return tlist->length;
}

int SeqList_Capacity(SeqList* list)
{
	TSeqList *tlist = NULL;
	if(list == NULL)
	{
		return -1;
	}
	tlist = (TSeqList *)list;	
	return tlist->capacity;	
} 

int SeqList_Insert(SeqList* list, SeqListNode* node, int pos)
{
	int i = 0,ret = 0;
	TSeqList *tlist = NULL;
	if(list == NULL || node == NULL || pos < 0)
	{
		ret = -1;
		printf("list == NULL || node == NULL || pos < 0 err:%d\n",ret);
		return ret;
	}
	tlist = (TSeqList *)list;	

	//判断是不是满了
	if(tlist->length >=tlist->capacity)
	{
		ret = -2;
		printf("tlist->length >=tlist->capacity err:%d\n",ret);	
		return ret;
	}

	//容量修正 6个长度 容量20 用户 pos10位置插入..
	if(pos >=tlist->length)
	{
		pos = tlist->length;
	}

	//元素移动 --后移
	for(i =tlist->length;i > pos;i--)
	{
		tlist->node[i] = tlist->node[i - 1]	;//reference a[i] = a[i - i]--->a[7] = a[6]
	}

	//插入元素
	tlist->node[i] =(unsigned int)node;
	tlist->length++;

	return 0;
}

SeqListNode* SeqList_Get(SeqList* list, int pos)
{
	int i = 0;
	SeqListNode *ret = 0;
	TSeqList *tlist = NULL;
	if(list == NULL || node == NULL || pos < 0)
	{
		printf("SeqList_Get() err:%d\n",ret);
		return NULL;
	}
	tlist = (TSeqList *)list;	

	ret = (void *)tlist->node[pos];	
	return ret;
}

SeqListNode* SeqList_Delete(SeqList* list, int pos)
{
	int i = 0;
	SeqListNode *ret = 0;
	TSeqList *tlist = NULL;

	if(list == NULL || pos < 0)
	{
		ret = -1;
		printf("SeqList_Delete() err:%d\n",ret);
		return ret;
	}
	tlist = (TSeqList *)list;

	//缓存pos位置
	ret = (SeqListNode *)tlist->node[pos];	

	//pos位置后面的元素前移
	for(i = pos + 1;i < tlist->length;i++) //person write err: for(i = tlist->length;i > pos;i--) 
	{
		tlist->node[i - 1] = tlist->node[i];
	}

	tlist->length--;

	return ret;
}

typedef struct _Teacher
{
	int age;
	char name[64];
}Teacher;

void main()
{
	int		ret = 0, i = 0;
	SeqList* list = NULL;

	Teacher t1, t2, t3, t4,t5;
	t1.age = 31;
	t2.age = 32;
	t3.age = 33;
	t4.age = 34;
	t5.age = 35;

	list = SeqList_Create(10);
	if (list == NULL)
	{
		printf("func SeqList_Create() ret :%d \n", ret);
		return ;
	}

	ret = SeqList_Insert(list, (SeqListNode*) &t1, 0); //头插法
	ret = SeqList_Insert(list, (SeqListNode*) &t2, 0); //头插法
	ret = SeqList_Insert(list, (SeqListNode*) &t3, 0); //头插法
	ret = SeqList_Insert(list, (SeqListNode*) &t4, 0); //头插法
	ret = SeqList_Insert(list, (SeqListNode*) &t5, 0); //头插法

	//遍历
	for (i=0; i<SeqList_Length(list); i++)
	{
		Teacher*  tmp = (Teacher *) SeqList_Get(list, i);
		if (tmp == NULL)
		{
			return ;
		}
		printf("tmp->age:%d ", tmp->age);
	}

	//删除链表中的节点
	while( SeqList_Length(list) > 0 )
	{
		SeqList_Delete(list, 0);
	}

	system("pause");

}