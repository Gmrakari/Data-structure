#include "string.h"
#include "stdio.h"    
#include "stdlib.h"   

/*
	date:2019-10-16 09:45
	Author : null
	Project:选择法排序
 */

void printArray(int array[],int len)
{
	int i = 0;
	for(i = 0;i < len;i++)
	{
		printf("%d",array[i]);
	}
	printf("\n");
}

void swap(int array[],int i ,int j)
{
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

void SelectionSort(int array[],int len)
{
	int i = 0;
	int j = 0;
	int k = -1;

	for(i = 0;i < len;i++)
	{
		k = i;//寻找最小元素的下标
		for(j = i + 1;j < len;j++)
		{
			if(array[k] > array[j])
			{
				k = j;
			}
		}
		swap(array,i,k);
	}
}


int main()
{
	int array[] = {12, 5, 433, 253};

	int len = sizeof(array) / sizeof(*array);

	printArray(array,len);

	SelectionSort(array,len);

	printArray(array,len);

	system("pause");
	return 0;
}