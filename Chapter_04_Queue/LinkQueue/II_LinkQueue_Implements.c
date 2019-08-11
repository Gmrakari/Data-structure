# pragma warning (disable:4819)
#define  _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include "stdlib.h"
#include "string.h"

#include "linklist.h"
#include "linkqueue.h"

//date:2019-08-11 15:00
//Author : null
//Project: LinkQueue_Implements


void main()
{
	int i,a[10];
	LinkQueue* queue = NULL;

	queue = LinkQueue_Create();

	if (queue == NULL)
	{
		return;
	}

	//向LinkQueue中添加元素
	for(i = 0;i < 10;i++)
	{
		a[i] = i + 1;
		LinkQueue_Append(queue,&a[i]);
	}

	printf("the length of linkqueue: %d \n",LinkQueue_Length(queue));

	printf("the header of linkqueue: %d \n",*( (int *)LinkQueue_Header(queue)));

	while ((LinkQueue_Length(queue)) > 0)
	{
		printf("%d \n",*( (int *)LinkQueue_Retrieve(queue)) );
	}

	LinkQueue_Destroy(queue);

	system("pause");
}