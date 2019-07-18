#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "I_linkstack.h"


void main()
{

	int i = 0;
	int a[10];
	LinkStack* stack = NULL;
	stack = LinkStack_Create();

	if(stack == NULL)
	{
		return ;
	}

	//添加元素
	for(i = 0;i < 5;i++)
	{
		a[i] = i + 1;
		LinkStack_Push(stack,&a[i]);
	}

	//获取栈的基本属性
	printf("len:%d\n",LinkStack_Size(stack);
	printf("top:%d\n",*((int *)LinkStack_Top(stack)));

	//删除栈元素
	while(LinkStack_Size(stack) > 0)
	{
		int tmp = *((int *)LinkStack_Pop(stack));
		printf("tmp:%d\n",tmp);
	}

	//销毁栈
	LinkStack_Destroy(stack);

	printf("C\n");
	system("pause");
	return ;
}