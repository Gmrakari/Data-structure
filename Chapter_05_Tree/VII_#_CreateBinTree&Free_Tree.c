#define  _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include "stdlib.h"
#include "string.h"

//date:2019-08-17 10：30
//Author : null
//Project: #号法创建树与释放树

//定义二叉树
struct BiTNode
{
	int data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

BiTNode * CreateBiThrTree(BiTNode *T)
{
	char h;
	scanf("%c",&h);

	BiTNode *node = NULL;
	BiTNode *pL = NULL;
	BiTNode *pR = NULL;

	if(h == '#')
	{
		return NULL;
	}
	else
	{
		node = (BiTNode *)malloc(sizeof(BiTNode));
		memset(node,0,sizeof(BiTNode));
		node->data = h;

		pL = CreateBiThrTree(T->lchild);
		if(pL != NULL)
		{
			node->lchild = PL;
		}
		else
		{
			node->lchild = NULL;
		}

		pR = CreateBiThrTree(T->rchild);
		if(pR != NULL)
		{
			node->rchild = pR;
		}
		else
		{
			node->rchild = NULL;
		}
	}
	return node;
}

//更改创建#号法Version
BiTNode * CreateBiThrTree02()
{
	BiTNode *tmp = NULL;
	char ch;

	printf("\n请输入字符:");
	scanf("%c",&ch);

	if(ch == '#')
	{
		return NULL;
	}

	else
	{
		tmp = (BiTNode *)malloc(sizeof(BiTNode));
		if(tmp == NULL)
		{
			return NULL;
		}
		tmp->data = ch;//生成根节点
		tmp->lchild = CreateBiThrTree02();//构建左子树
		tmp->rchild = CreateBiThrTree02();//构建右子树
		return tmp;
	}
}

//释放树
void BiTree_Free(BiTNode *T)
{
	BiTNode *tmp = NULL;
	if(T!=NULL)
	{
		if(T->rchild != NULL)
		{
			BiTree_Free(T->rchild);
		}
		if(T->lchild != NULL)
		{
			BiTree_Free(T->lchild);
		}

		if(T!= NULL)
		{
			free(T);
			T = NULL;
		}
	}
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

	BiTNode *my = CreateBiThrTree02();
	printf("\n中序遍历:\n");

	BiTree_Free(my);

	printf("hello world");
	system("pause");
}

/*
结论
后序遍历销毁一个树
单独先序遍历：能求解根，但不能求解左子树和右子树的结束、开始分界线
 */