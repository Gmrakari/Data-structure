/*
 *Date:2019-07-17-15:50
 *Author:null
 *Project:linkstack_API
 *
*/ 

#ifndef _MY_LINKSTACK_H_
#define _MY_LINKSTACK_H_

typedef void LinkStack;

LinkStack* LinkStack_Create();

void LinkStack_Destroy(LinkStack* stack);

void LinkStack_Clear(LinkStack* stack);

int LinkStack_Push(LinkStack* stack, void* item);

void* LinkStack_Pop(LinkStack* stack);

void* LinkStack_Top(LinkStack* stack);

int LinkStack_Size(LinkStack* stack);

#endif //_MY_LINKSTACK_H_

