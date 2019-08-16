#include "SeqList.h"

/*
Date:2019-08-16 16:30
Author:null
 */

template <typename T>
SeqList<T>::SeqList(int Capacity)
{
	pArray = new T[Capacity];
	this->capacity = Capacity;
	this->len = 0;
}

template <typename T>
SeqList<T>::~SeqList(void)
{
	delete[] pArray;
	pArray = NULL;
	len = 0;
	capacity = 0;
}

template <typename T>
int SeqList::insert(T &t,int pos)
{
	int i = 0;
	if(pos < 0)
	{
		return -1;
	}

	for(i = len;i > pos ;i--)
	{
		pArray[i] = pArray[i - 1];
	}

	pArray[i] = t;//stl元素保存时通过 复制的机制实现的, 你的类要可以复制 才行.
	this->len ++;
	return 0;
}

template <typename T>
int SeqList::del(int pos,T &t)
{
	int i;
	t = pArray[pos];

	for(i = pos + 1;i < len;i++)
	{
		pArray[i - 1]  = pArray[i];
	}
	len--;
	return 0;
}

template <typename T>
int SeqList<T>::get(int pos,T &t)
{
	int i = 0;
	if(pos < 0)
	{
		return -1;
	}

	t = pArray[pos];
	return 0;
}

template <typename T>
int SeqList<T>::getLen()
{
	return this->len;
}

template <typename T>
int SeqList::getCapacity()
{
	return this->capacity;
}
