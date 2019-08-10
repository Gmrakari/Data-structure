#include "stdio.h"
#include "stdlib.h"
#include "I_linkstack.h"
/*
 *Date:2019-08-10 16：00
 *Author:null
 *Project:栈中缀转后缀
 *
*/

/*
只有看不懂的业务
没有看不懂的代码

遍历中缀表达式中的数字和符号
对于数字：直接输出
对于符号：
左括号：进栈  
运算符号：与栈顶符号进行优先级比较
若栈顶符号优先级低：此符合进栈  （默认栈顶若是左括号，左括号优先级最低）
若栈顶符号优先级不低：将栈顶符号弹出并输出，之后进栈
右括号：将栈顶符号弹出并输出，直到匹配左括号
遍历结束：将栈中的所有符号弹出并输出

 */

int isNumber(char c)
{
	return ('0' <= c) && (c <= '9');
}

int isOperator(char c)
{
	return (c == '+') || (c == '-') || (c == '*') || (c == '/');
}

int isLeft(char c)
{
	return (c == '(');
}

int isRight(char c)
{
	return (c == ')');
}

int priority(char c)
{
	int ret = 0;

	if( (c == '+') || (c == '-'))
	{
		ret = 1;
	}

	if( (c == '*') || (c == '/'))
	{
		ret = 2;
	}
	return ret;
}

void output(char c)
{
	if( c != '\0')
	{
		printf("%c",c);
	}
}

void transform(const char* exp)
{
	int i = 0;
	LinkStack* stack = LinkStack_Create();

	while( exp[i] != '\0')
	{
		if( isNumber(exp[i]))
		{
			output(exp[i]);
		}
		else if( isOperator(exp[i]))
		{
			while( priority(exp[i]) <= priority((char)(int)LinkStack_Top(stack)))
			{
				output((char)(int)LinkStack_Pop(stack));
			}

			LinkStack_Push(stack,(void*)(int)exp[i]);
		}
		else if( isLeft(exp[i]))
		{
			LinkStack_Push(stack,(void*)(int)exp[i]);
		}
		else if( isRight(exp[i]))
		{
			while( !isLeft((char)(int)LinkStack_Top(stack)) )
			{
				output((char)(int)LinkStack_Pop(stack));
			}

			LinkStack_Pop(stack);
		}
		else
		{
			printf("Invalid expression!");
			break;
		}

		i++;
	}

	while( (LinkStack_Size(stack) > 0) && (exp[i] == '\0'))
	{
		output((char)(int)LinkStack_Pop(stack));
	}
	LinkStack_Destroy(stack);
}

int main()
{
	transform("8+(3-1)*5");

	printf("\n");
	system("pause");
	return 0;
}