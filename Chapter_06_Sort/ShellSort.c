#include "string.h"
#include "stdio.h"    
#include "stdlib.h"   

/*
	date:2019-10-16 10:50
	Author : null
	Project:希尔排序 不稳定
 */

/*要点
1、分组 然后d = 1 的时候就是一个插入排序 
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

//nlogn
void ShellSort(int array[],int len)
{
	int i = 0;
	int j = 0;
	int k = -1;
	int temp = -1;
	int gap = len;

	do
	{
		//业界统一实验的 平均最好情况 经过若干次后，收敛为1
		gap = gap / 3 + 1;

		for(i = gap;i < len;i += gap)
		{
			k = i;
			temp = array[k];

			for(j = i - gap;(j >= 0) && (array[j] > temp);j -= gap)
			{
				array[j + gap] = array[j];
				k = j;
			}

			array[k] = temp;
		}
	}while( gap > 1)
}

int main(int argc, char const *argv[])
{
	int array[] = {12, 5, 433, 253, 216, 7};

	int len = sizeof(array) / sizeof(*array);

	printArray(array,len);

	ShellSort(array,len);

	printArray(array,len);

	system("pause");
	return 0;
}