#include "stdio.h"
#include "string.h"
#include "stdio.h"
#include "I_SeqQueue.h"
/*
 *Date:2019-08-10 17:40
 *Author:null
 *Project:seqqueue业务集成测试
 *
*/

void main()
{
	int i,a[10];

	SeqQueue *queue = NULL;

	queue = SeqQueue_Create(10);

	//add element
	for(i = 0; i < 10;i++)
	{
		a[i] = i + 1;
		SeqQueue_Append(queue,&a[i]);
	}

	//printf property
	printf("the header of queue:%d\n",*((int *)SeqQueue_Header(queue)));
	printf("the length of queue:%d\n",SeqQueue_Length(queue));
	printf("the capacity of queue:%d\n",SeqQueue_Capacity(queue));

	//delete queue (out queue)
	while( SeqQueue_Length(queue) > 0)
	{
		int tmp = *((int *)SeqQueue_Retrieve(queue))
		printf("%d\n", tmp);
	}

	SeqQueue_Destory(queue);

	system("pause");
}