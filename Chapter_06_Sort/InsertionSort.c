#include "string.h"
#include "stdio.h"    
#include "stdlib.h"   

/*
	date:2019-10-16 10:30
	Author : null
	Project:插入排序
 */

/*两个要点
1、拿出来
2、符合条件的元素后移
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

void InsertionSort(int array[],int len)
{
	int i = 0;
	int j = 0;
	int k = -1;

	int temp = -1;

	for(i = 1;i < len;i++)
	{
		k = i;
		temp = array[k];//第一要点 拿出来

		for(j = i -1 ;(j >= 0) && (array[j] > temp);j--)
		{
			array[j + 1] = array[j];//第二要点 符合条件的元素后移
			k = j;//k需要插入的位置
		}
		array[k] = temp;//元素插入
	}
}

int main(int argc, char const *argv[])
{
	int array[] = {12, 5, 433, 253, 216, 7};

	int len = sizeof(array)/sizeof(*array);

	printArray(array, len);

	InertionSort(array, len);

	printArray(array, len);
	system("pause");
	return 0;
}