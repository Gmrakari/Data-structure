#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "I_seqstack.h"

/*
 * Date:2019-07-17 13:58
 * Author:null
 * Project:SeqStack
 *
*/

void main()
{
/*		
	SeqStack* SeqStack_Create(int capacity);

	void SeqStack_Destroy(SeqStack* stack);

	void SeqStack_Clear(SeqStack* stack);

	int SeqStack_Push(SeqStack* stack,void* item);

	void* SeqStack_Pop(SeqStack* stack);

	void* SeqStack_Top(SeqStack* stack);

	int SeqStack_Size(SeqStack* stack);

	int SeqStack_Capacity(SeqStack* stack);
*/
	int i = 0;
	int a[10];
	SeqStack* stack = NULL;
	stack = SeqStack_Create(10);
	if(stack == NULL)
	{
		return ;
	}

	//压栈
	for(i = 0;i < 5;i++)
	{
		a[i] = i + 1;
		SeqStack_Push(stack,&a[i]);
	}

	printf("Capacity:%d\n",SeqStack_Capacity(stack));
	printf("length:%d\n",SeqStack_Size(stack));

	printf("top:%d\n",*((int *)SeqStack_Size(stack)));

	while(seqStack_Size(stack) > 0)
	{
		int tmp = *(int *)SeqStack_Pop(stack);
		printf("tmp:%d\n",tmp);
	}
	printf("\n");


}
