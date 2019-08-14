#define  _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include "stdlib.h"
#include "string.h"

//date:2019-08-14 16:00
//Author : null
//Project: 树的叶子结点计算

//定义二叉树
struct BiTNode
{
	int data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

int sum;

void coutLeafNum(BiTNode *T)
{
	if(T != NULL)
	{
		if(T->lchild == NULL && T->rchild ==NULL)
		{
			sum++;
		}

		if(T->lchild)
		{
			coutLeafNum(T->lchild);
		}

		if(T->rchild)
		{
			coutLeafNum(T->rchild);
		}		
	}
}

void coutLeafNum02(BiTNode *T,int *sum)
{
	if(T != NULL)
	{
		if(T->lchild == NULL && T->rchild ==NULL)
		{
			(*sum)++; //++ *p p++ sum 
		}

		if(T->lchild)
		{
			coutLeafNum02(T->lchild,sum);
		}

		if(T->rchild)
		{
			coutLeafNum02(T->rchild,sum);
		}		
	}	
}

//与coutLeafNum02比较 修改(*sum)++;的位置，考虑是否能求出coutLeaf的个数
//涉及树三种遍历的本质
//三种遍历算法的访问路径是相同的，只是访问结点的时机不同 
void coutLeafNum03(BiTNode *T,int *sum)
{
	if(T != NULL)
	{
		if(T->lchild)
		{
			coutLeafNum03(T->lchild,sum);
		}

		if(T->rchild)
		{
			coutLeafNum03(T->rchild,sum);
		}

		if(T->lchild == NULL && T->rchild ==NULL)
		{
			(*sum)++; 
		}				
	}	
}

int main()
{
	BiTNode t1,t2,t3,t4,t5;
	memset(&t1,0,sizeof(BiTNode));
	memset(&t2,0,sizeof(BiTNode));
	memset(&t3,0,sizeof(BiTNode));
	memset(&t4,0,sizeof(BiTNode));
	memset(&t5,0,sizeof(BiTNode));

	t1.data = 1;
	t2.data = 2;
	t3.data = 3;
	t4.data = 4;
	t5.data = 5;

	//建立关系
	t1.lchild = &t2;
	t1.rchild = &t3;

	t2.lchild = &t4;

	t3.lchild = &t5;

	sum = 0;

	coutLeafNum(&t1);

	printf("sum:%d\n",sum);

	//调用coutLeaf02
	{
		int mysum = 0;
		coutLeafNum02(&t1,&mysum);
		printf("mysum:%d\n",mysum);
	}

	//结果是否一样
	{
		int mysum03 = 0;
		coutLeafNum03(&t1,&mysum03);
		printf("mysum03:%d\n",mysum03);
	}

	printf("hello world");
	system("pause");
}