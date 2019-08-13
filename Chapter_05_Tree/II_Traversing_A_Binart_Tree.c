#define  _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include "stdlib.h"
#include "string.h"

//date:2019-08-13 20:45
//Author : null
//Project: 树的遍历

//定义二叉树
struct BiTNode
{
	int data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

//先序遍历 根 左子树 右子树
void preOrder(BiTNode *root)
{
	if(root == NULL)
	{
		return ;
	}
	printf("%d",root->data);

	//遍历左子树
	preOrder(root->lchild);
	
	//遍历右子树
	preOrder(root->rchild);	

}

//中序遍历 左子树 根 右子树
void inOrder(BiTNode *root)
{
	if(root == NULL)
	{
		return ;
	}

	inOrder(root->lchild);

	printf("%d ", root->data);
	
	//遍历右子树
	inOrder(root->rchild);	
}

//后序遍历 左子树 右子树 根
void posOrder(BiTNode *root)
{
	if(root == NULL)
	{
		return ;
	}

	posOrder(root->lchild);

	posOrder(root->rchild);

	printf("%d ", root->data);	
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

	printf("preOrder\n");
	preOrder();

	printf("inOrder\n");
	inOrder();
	
	printf("posOrder\n");
	posOrder();

	printf("hello world");
	system("pause");
}

