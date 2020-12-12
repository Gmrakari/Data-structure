#include <stdio.h>
#include <malloc.h>

/*
	date:2019-10-16 20:15
	Author : null
	Project:归并排序 稳定
 */

/*要点
1、让数据分成两部分
2、partition
*/

void printArray(int array[],int len)
{
	int i = 0;

	for(int i = 0;i < len;i++)
	{
		printf("%d",array[i]);
	}
	printf("\n");
}

int swap(int array[],int i,int j)
{
	int temp = array[i];

	array[i] = array[j];

	array[j] = temp;
}

//src 原数组 des 合并后数组
void Merge(int src[],int des[],int low,int mid,int high)
{
	int i = low;
	int j = mid + 1;
	int k = low;

	while((i <= mid) && (j <= high)) //将小的放到目的地重
	{
		if( src[i] < src[j]) //比较左右两边的值
		{
			des[k++] = src[i++]; 
		}
		else
		{
			des[k++] = src[j++];
		}
	}

	while( i <= mid) //若左边还是剩几个尾部元素 补到des合并后的数组中
	{
		des[k++] = src[i++];
	}

	while( j <= high) //若右边还是剩几个尾部元素 补到des合并后的数组中
	{
		des[k++] = src[j++]
	}
}

void MSort(int src[],int des[],int low,int high,int max)
{
	if( low == high) //只有一个元素，不需要归并，结果赋给des[low]
	{
		des[low] = src[low];
	}
	else //如果多个元素，进行两路划分
	{
		int mid = (low + high) / 2;
		int *space = (int *)malloc(sizeof(int) * max);

		//递归进行两路 两路的划分
		//当剩下一个元素的时候，递归划分结束，然后卡是merge归并操作
		
		if( space != NULL)
		{
			MSort(src,space,low,mid,max);
			MSort(src,space,mid + 1,high,max);
			Merge(space,des,low,mid,high);//调用归并函数进行合并
		}
		free(space);
	}
}

void MergeSort(int array[],int len)
{
	MSort(array,array,0,len - 1,len);
}

int main()
{
	//int array[] = {21, 25, 49, 25, 16, 8};
	int array[] = {21, 25};

	printArray(array,len);

	MergeSort(array,len);

	printArray(array,len);

	system("pasue");
	return 0;	
}