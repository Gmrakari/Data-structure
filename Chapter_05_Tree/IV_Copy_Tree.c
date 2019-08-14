#define  _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include "stdlib.h"
#include "string.h"

//date:2019-08-14 16:20
//Author : null
//Project: 树的拷贝

/*无法通过编译
struct BiTNode
{
	int data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
*/

//下面才可以
struct BiTNode
{
	int data;
	struct BiTNode *lchild, *rchild;
};
typedef struct BiTNode 	BiTNode;
typedef struct BitNode* BiTree;

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

BiTNode * CopyTree(BiTNode *T)
{
	BiTNode *newNode = NULL;
	BiTNode *newLp = NULL;
	BiTNode *newRp = NULL;

	if(T == NULL)
	{
		return NULL;
	}

	//copy左子树
	if(T->lchild != NULL)
	{
		newLp = CopyTree(T->lchild);//copy左子树
	}
	else
	{
		newLp = NULL;
	}

	//copy右子树
	if(T->rchild != NULL)
	{
		newRp = CopyTree(T->rchild);//copy右子树
	}
	else
	{
		newRp = NULL;
	}	

	//malloc根结点
	
	newNode = (BiTNode *)malloc(sizeof(BiTNode));

	if(newNode == NULL)
	{
		return NULL;
	}

	newNode->lchild = newLp;
	newNode->rchild = newRp;

	newNode->data = T->data;

	return newNode;
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

	{
		BiTNode *root = CopyTree(&t1);
		printf("\ncopy inorder:\n");
		inOrder(root);
	}

	{
		printf("older inOrder\n");
		inOrder(&t1);
	}

	printf("hello world");
	system("pause");
}