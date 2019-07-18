#include "stdio.h"
#include "stdlib.h"
#include "I_linkstack.h"
/*
 *Date:2019-07-18 16:02
 *Author:null
 *Project:后缀表达式
 *
*/

int isLeft(char c)
{
	int ret = 0;
	switch(c)
	{
		case '<':
		case '(':
		case '[':
		case '{':
		case '\'':
		case '\"':
			ret = 1;
			break;
		default:
			ret = 0;
			break;
	}
	return ret;
}

int isRight(char c)
{
	int ret = 0;
	switch(c)
	{
		case '>':
		case ')':
		case ']':
		case '}':
		case '\'':
		case '\"':
			ret = 1;
			break;
		default:
			ret = 0;
			break;
	}
	return ret;
}

int mach(char left,char right)
{
	int ret = 0;
	switch(left)
	{
		case '<':
		ret = (right == '>');
		break;

		case '(':
		ret = (right == ')');
		break;

		case '[':
		ret = (right == ']');
		break;

		case '{':
		ret = (right == '}');
		break;

		case '\'':
		ret = (right == '\'');
		break;

		case '\"':
		ret = (right == '\"');
		break;

		default:
		ret = 0;
		break;
	}
	return ret;
}

int scanner(const char* code)
{
	LinkStack* stack = LinkStack_Create();
	int ret = 0;
	int i = 0;

	while(code[i] != '\0')
	{
		if(isLeft(code[i]))
		{
			LinkStack_Push(stack,(void*)(code + i));//&code[i]
		}

		if(isRight(code[i]))
		{
			char* c = (char*)LinkStack_Pop(stack);

			if((c == NULL) || !match(*c,code[i]))
			{
				printf("%s dose not match!\n",code[i]);
				ret = 0;
				break;
			}
		}

		i++;
	}

	if((LinkStack_Size(stack) == 0) && (code[i] == '\0'))
	{
		printf("Success!\n");
		ret = 1;
	}
	else
	{
		printf("Invalide code\n");
		ret = 0;	
	}

	LinkStack_Destroy(stack);
	return ret;
}


void main()
{
	const char* code = "#include <stdio.h> int main() { int a[4][4]; int (*p)[4]; p = a[0]; return 0; ";

	scanner(code);

	system("pause");

	return ;
}
