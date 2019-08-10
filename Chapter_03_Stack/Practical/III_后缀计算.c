#include "stdio.h"
#include "stdlib.h"
#include "I_linkstack.h"
/*
 *Date:2019-08-10 16：40
 *Author:null
 *Project:后缀计算
 *
*/

/*

遍历后缀表达式中的数字和符号
对于数字：进栈
对于符号：
从栈中弹出右操作数
从栈中弹出左操作数
根据符号进行运算
将运算结果压入栈中
遍历结束：栈中的唯一数字为计算结果

 */
int isNumber(char c)
{
	return ('0' <= c) && (c <= '9');
}

int isOperator(char c)
{
	return (c == '+') || (c == '-') || (c == '*') || (c == '/');
}

int value(char c)
{
	return (c - '0');
}

int express(int left,int right,char op)
{
	int ret = 0;

	switch(op)
	{
		case '+':
		ret = left + right;
		break;

		case '-':
		ret = left - right;
		break;

		case '*':
		ret = left * right;
		break;

		case '/':
		ret = left / right;
		break;

		default:
		break;
	}

	return ret;
}

int calculate(const char* exp)
{
	LinkStack* stack = LinkStack_Create();

	int ret = 0;
	int i = 0;

	while( exp[i] != '\0')
	{
		if( isNumber(exp[i]))
		{
			LinkStack_Push(stack,(void*)value(exp[i]));
		}
		else if( isOperator(exp[i]))
		{
			int right = (int)LinkStack_Pop(stack);
			int left = (int)LinkStack_Pop(stack);
			int result = express(left,right,exp[i]);

			LinkStack_Push(stack,(void*)result);
		}
		else
		{
			printf("Invalid expression!");
			break;
		}

		i++;
	}

	if( (LinkStack_Size(stack) == 1) && (exp[i] == '\0'))
	{
		ret = (int)LinkStack_Pop(stack);	
	}
	else
	{
		printf("Invalid expression!");
	}

	LinkStack_Destory(stack);

	return ret;
}

int main()
{
	printf("8 + (3 - 1) * 5  = %d\n", calculate("831-5*+"));
	system("pause");
	return 0;	
}