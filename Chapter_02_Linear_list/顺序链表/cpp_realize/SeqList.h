#pragma
//只要在头文件的最开始加入这条指令就能够保证头文件被编译一次

/*
Date:2019-08-16 16:30
Author:null
 */

//业务离不开 增 删 查 改
template <typename T>
class SeqList
{
public:
	SeqList(int Capacity);

	~SeqList(void);

	int SeqList_Insert(T &t,int pos);//增

	int del(int pos, T &t);//删

	int get(int pos, T &t);//查

	int getCapacity();

	int getLen();//获取链表长度

private:
	int len;
	int capacity;

	T *pArray;//数组
};


