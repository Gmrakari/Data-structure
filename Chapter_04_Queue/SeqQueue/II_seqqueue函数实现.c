#include "stdio.h"
#include "string.h"
#include "stdio.h"
#include "I_SeqQueue.h"
#include "seqlist.h"
/*
 *Date:2019-08-10 17:50
 *Author:null
 *Project:seqqueue函数实现
 *
*/

//队列也是一种特殊的线性表

//创建一个队列 相当于 创建一个顺序存储线性表
SeqQueue* SeqQueue_Create(int capacity)
{
	return SeqList_Create(capacity);
}

//销毁队列 相当于 清空线性表
void SeqQueue_Destroy(SeqQueue* queue)
{
	return SeqList_Destroy(queue)
}

//清空队列 相当于 清空线性表
void SeqQueue_Clear(SeqQueue* queue)
{
	return SeqList_Clear(queue);
}

//向队列中添加一个元素 相当于 向线性表中 添加一个元素 
int SeqQueue_Append(SeqQueue* queue, void* item)
{
	SeqList_Insert(queue,item,SeqList_Length(queue));//尾插
}

//出队列 相当于 从线性表中删除0号位置元素
void* SeqQueue_Retrieve(SeqQueue* queue)
{
	return SeqList_Delete(queue,0);
}

//获取队头元素 相当于 从线性表中提取0号位置元素
void* SeqQueue_Header(SeqQueue* queue)
{
	return SeqList_Get(queue,0);
}

int SeqQueue_Length(SeqQueue* queue)
{
	return SeqList_Length(queue);
}

int SeqQueue_Capacity(SeqQueue* queue)
{
	return SeqList_Capacity(queue);
}

