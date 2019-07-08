#define  _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*
Date:2019-07-07
时间复杂度 & 空间复杂度 的 calc
时间换空间

Review & clean up 2019-07-08 10:53
 */


//算法得最终要编译成具体的计算机指令
//每一个指令 在具体的计算机 cpu上运行的时间是固定
//通过具体的n的步骤的多少就可以推导出算法的复杂度

//时间复杂度的度量
long sum1(int n) //2n + 3 ----> O(n)
{
	long ret = 0;
	int* array = (int*)malloc(n*sizeof(int)); //1
	int i = 0; //1

	for(i = 0;i<n;i++) //n
	{
		array[i] = i + 1;
	}

	for(i = 0;i<n;i++) //n
	{
		ret += array[i];
	}

	free(array);//1

	return ret;
}

long sum2(int n) //n + 2 ----->O(n)
{
	long ret = 0; //1
	int i = 0;//1

	for(i = 1;i<=n;i++)//n
	{
		ret +=i;
	}

	return ret;
}

long sum3(int n) //2 -----> O(1)
{
	long ret = 0; //1

	if(n > 0) //判断不算
	{
		ret = (1 + n)*n/2; //1
	}
	return ret;
}

int main()
{
	printf("%d\n",sum1(100));
	printf("%d\n",sum2(100));
	printf("%d\n",sum3(100));


}

//空间复杂度的度量
long sum1(int n) // 4n + 8
{
	long ret = 0;//4
	int* array = (int*)malloc(n*sizeof(int)); //4*n
	int i = 0; //4

	for(i = 0;i<n;i++) //
	{
		array[i] = i + 1;
	}

	for(i = 0;i<n;i++) //
	{
		ret += array[i];
	}

	free(array);//

	return ret;
}

long sum2(int n) // 8 === O(1)
{
	long ret = 0; //4
	int i = 0;//4

	for(i = 1;i<=n;i++)//
	{
		ret +=i;
	}

	return ret;
}

long sum3(int n) // 4 O(1)
{
	long ret = 0; //4

	if(n > 0) //判断不算
	{
		ret = (1 + n)*n/2; // 
	}
	return ret;
}

//练习2：时间换空间
/*
    问题： 
    在一个由自然数1-1000中某些数字所组成的数组中，每个数字可能出现零次或者多次。
    设计一个算法，找出出现次数最多的数字。
*/


//用空间换时间思想
void search(int a[],int len)
{
	int sp[1000] = {0};
	int i = 0;
	int max = 0;

	for(i = 0;i < len;i++) //遍历数组 求出每一个数字出现的次数，然后记录下来
	{
		int index = a[i] - 1;
		sp[index]++;
	}

	for(i = 0;i < 1000;i++) //扫描数组 求出最大数
	{
		if(max <sp[i])
		{
			max = sp[i];
		}
	}

	for(i = 0;i<1000;i++) 	//	打印数字 出现最多的
	{
		if(max ==sp[i])
		{
			printf("%d\n",i+1);
		}
	}
}

//方法二：排序的方法找到数字最多的数

void search2()
{
    int array[] = { 1, 3, 3, 3, 6, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 8, 8 };
    int temp = 0;
    int max = 0;
    int num = 0;
    int N = sizeof(array) / sizeof(*array);
    for (int i = 0; i < N; i++)
    {
        for (int j = i; j < N; j++)
        {
            if (array[i] == array[j])
            {
                temp++;

            }
        }

        if (max < temp)//max为最多的次数
        {
            max = temp;
            num = array[i];

        }
        temp = 0;
    }

   printf("%d\n",num);
    return 0;	
}

int main()
{
	int array[] = {1,1,3,4,5,6,6,6,2,3};

	search(array,sizeof(array)/sizeof(*array));
	system("pause");

	return 0;
}

