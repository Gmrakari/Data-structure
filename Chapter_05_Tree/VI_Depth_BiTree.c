#define  _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include "stdlib.h"
#include "string.h"

//date:2019-08-17 10：30
//Author : null
//Project: 计算树的高度

//定义二叉树
struct BiTNode
{
	int data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

//递归中序遍历
void InOrder(BiTNode *root)
{
	if(root == NULL)
	{
		return NULL;
	}

	InOrder(root->lchild);
	printf("%d\n",root->data);
	InOrder(root->rchild);
}


int Depth(BiTNode *T)
{
	int deptleft = 0;
	int deptright = 0;
	int depval = 0;

	if(T == NULL)
	{
		depval = 0;
		return depval;
	}

	//求左子树的高度
	deptleft = Depth(T->lchild);

	//求右子树的高度
	deptright = Depth(T->rchild);

	//根结点占一个度
	depval = 1 + (deptleft > deptright ? deptleft : deptright);

	return depval;
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

	//调用打印树的高度
	printf("%d\n",	Depth(&t1) );

	printf("InOrder:");
	InOrder(&t1);

	printf("hello world");
	system("pause");
}