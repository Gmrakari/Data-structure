#include "string.h"
#include "stdio.h"    
#include "stdlib.h"   

/*
	date:2019-10-16 19:37
	Author : null
	Project:快速排序 不稳定
 */

/*要点
1、让数据分成两部分
2、partition
*/

void printArray(int array[],int len)
{
	int i = 0;

	for(i = 0; i < len;i++)
	{
		printf("%d",array[i]);
	}	
	printf("\n");
}

void swap(int array[],int i,int j)
{
	int temp = array[i];

	array[i] = array[j];

	array[j] = temp;
}

//划分过程 第一个元素当枢轴 分成2个有效子序列
int partition(int array[],int low,int high)
{
	int pv = array[low];

	while(low < high)
	{
		while((low < high) && (array[high] >= pv))
		{
			high--;
		}
		swap(array,low,high);

		while((low < high) && (array[low] <= pv))
		{
			low++;
		}
		swap(array,low,high);
	}

	//返回枢轴的位置 
	return low;
}


//让n个元素 依次减少 减少到1个元素的时候，因为一个元素可以看成一个有序的序列

/*

 void QuickSort2(int array[],int low,int high)
{
	if(low < high)
	{
		int pivot = partition(array,low,high)

		//对子序列1排序
		QuickSort2(array,low,pivot - 1);

		//对子序列2排序
		QuickSort2(array,pivot + 1,high);
	}
}

*/

void QSort(int array[],int low,int high)
{
	if( low < high)
	{
		int pivot = partition(array,low,high);

		//对子序列1排序
		QuickSort(array,low,pivot - 1);

		//对子序列2排序
		QuickSort(array,pivot + 1,high);
	}
}

void QuickSort(int array[],int len)
{
	QSort(array,0,len - 1);
}

int main(int argc, char const *argv[])
{
	//int array[] = {12, 5, 433, 253, 216, 7};
	//int array[] = {12, 5, 433};
	int array[] = {12, 5};

	int len = sizeof(array) / sizeof(*array);

	printArray(array,len);

	QuickSort(array,len);

	printArray(array,len);
	system("pause");
	return 0;
}