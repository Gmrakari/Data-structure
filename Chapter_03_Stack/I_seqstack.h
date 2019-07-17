/*
 * date:2019-07-17 10:30
 * Author:null
 * Project:SeqStack
*/

#ifndef _MY_SEQSTACK_H
#define _MY_SEQSTACK_H

typedef void SeqStack;

SeqStack* SeqStack_Create(int capacity);

void SeqStack_Destroy(SeqStack* stack);

void SeqStack_Clear(SeqStack* stack);

int SeqStack_Push(SeqStack* stack,void* item);

void* SeqStack_Pop(SeqStack* stack);

void* SeqStack_Top(SeqStack* stack);

int SeqStack_Size(SeqStack* stack);

int SeqStack_Capacity(SeqStack* stack);

#endif
