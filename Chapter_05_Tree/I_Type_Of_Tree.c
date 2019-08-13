#define  _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include "stdlib.h"
#include "string.h"

//date:2019-08-13 19:00
//Author : null
//Project: 树的表示法

/*
struct BiTNode
{
	int data;
	struct BiTNode *lchild,*rchild;
};
//重新重命名类型
typedef struct BiTNode 	BiTNode;
//也是重命名类型 是一个指针的数据类型
typedef struct BitNode* BiTree;
 */

//二叉表示法
struct BiTNode
{
	int data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

//第二种表示方法 三叉链表
//三叉链表
typedef struct TriTNode
{
	int data;
	//左右孩子指针
	struct TriTNode *lchild,*rchild;
	struct TriTNode *parent;
}TriTNode,*TriTree;

//第三种表示方法 双亲链表
//双亲链表:子节点中保存了 双亲的位置信息()
#define MAX_TREE_SIZE 100
typedef struct BPTNode
{
	int data;
	int parentPosition;//指向双亲的指针 //数组下标
	char LRTag;//左右孩子标志域
}BPTNode;

typedef struct BPTree
{
	BPTNode nodes[100];//因为节点之间是分散的，需要把节点存储到数组中
	int num_node;//节点数目
	int root;//根节点的位置 //注意此域存储的是父亲节点在数组的下标
}BPTree;

//怎么对第三种结构体表示的树 进行初始化

int main01()
{
	BiTNode t1,t2,t3,t4,t5;

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

	printf("hello world");
	system("pause");
}


int main02()
{
	BiTNode *p1,*p2,*p3,*p4,*p5;

	p1 = (BiTNode *)malloc(sizeof(BiTNode));
	p2 = (BiTNode *)malloc(sizeof(BiTNode));
	p3 = (BiTNode *)malloc(sizeof(BiTNode));
	p4 = (BiTNode *)malloc(sizeof(BiTNode));
	p5 = (BiTNode *)malloc(sizeof(BiTNode));

	p1->data = 1;
	p2->data = 2;
	p3->data = 3;
	p4->data = 4;
	p5->data = 5;



	//建立关系
	p1->lchild = p2;
	p1->rchild = p3;
	p2->lchild = p4;
	p3->lchild = p5;

	printf("hello world");
	system("pause");
}

int main03()
{
	BPTree tree;

	//根节点(A)
	tree.nodes[0].parentPosition = 100;

	//B
	tree.nodes[1].parentPosition = 0;
	tree.nodes[1].data = 'B';
	tree.nodes[1].LRTag = 1;

	//C
	tree.nodes[2].parentPosition = 0;
	tree.nodes[2].data = 'C';
	tree.nodes[2].LRTag = 2;

	//D
	tree.nodes[3].parentPosition = 1;
	tree.nodes[3].data = 'D';
	tree.nodes[3].LRTag = 3;

	//E
	tree.nodes[4].parentPosition = 1;
	tree.nodes[4].data = 'E';
	tree.nodes[4].LRTag = 4;	

	printf("hello world");
	system("pause");
}