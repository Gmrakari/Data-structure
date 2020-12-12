#include "string.h"
#include "stdio.h"    
#include "stdlib.h"   

/*
	date:2019-10-16 10:50
	Author : null
	Project:冒泡排序
 */

/*要点
1、相邻元素比较
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

void BubbleSort(int array[],int len)
{
	int i = 0;
	int j = 0;
	int exchange = 1;//表明数组是否已经排好序 已经排好序为0   1表示没有排好序

	for(i = 0;(i < len) && exchange;i++)
	{
		exchange = 0;//认为已经排序完毕
		for(j = len - 1;j > i;j--)
		{
			if(array[j] < array[j - 1])
			{
				swap(array,j,j - 1)
				exchange = 1;
			}
		}
	}
}

int main()
{
	int array[] = {8,3,6,1};

	int len = sizeof(array) / sizeof(*array);

	printArray(array,len);

	BubbleSort(array,len);

	printArray(array,len);

	system("pause");
	return 0;
}