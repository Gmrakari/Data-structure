#include <iostream>
using namespace std;

//#include "SeqList.h"
#include "SeqList.cpp"

/*
Date:2019-08-16 16:30
Author:null
 */
struct Teacher
{
	char name[64];
	int age;	
};

void SeqList_main_run()
{
	Teacher t1,t2,t3;
	Teacher *p1,*p2,*p3;

	t1.age = 31;
	t2.age = 32;
	t3.age = 33;

	p1 = &t1;
	p2 = &t2;
	p3 = &t3;

	Teacher *tmp = NULL;

	SeqList<Teacher *> list(10);

	list.insert(p1,0);

	list.insert(p2,0);

	list.insert(p3,0);

	//遍历
	for(int i = 0;i < list.getLen();i++)
	{
		list.get(i,tmp);
		cout<<tmp->age<<" ";
	}

	//链表销毁
	while(list.getLen() > 0)
	{
		list.del(0,tmp);

		cout<<tmp->age<<" ";
	}

	return ;
}

int main(int argc, char const *argv[])
{
	SeqList_main_run();
	cout<<"hello world"<<endl;
	system("pause");
	return ;
}