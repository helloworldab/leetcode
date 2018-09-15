// String to Integer.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

int myAtoi(string str) 
{
	int temp = 0;
	int flag = 0;
	char *chr = &str[0];
	while (*chr == ' ')  //过滤掉空格
		chr++;
	if (*chr == '-')
	{
		flag = 1;
		chr++;
	}
	else if (*chr == '+')
	{
		chr++;
	}
	if (*chr > '9' || *chr < '0')				//第一个非空格字符
		return 0;
	else
	{
		temp = *chr - '0';
		chr++;
		if (flag == 1)
		{
			temp = -temp;
			while (*chr <= '9' && *chr >= '0')
			{
				if (temp < INT32_MIN / 10 || (temp == INT32_MIN / 10 && *chr - '0' > 7))
					return INT32_MIN;
				temp *= 10;
				temp -= *chr - '0';
				chr++;
			}
		}
		else
		{
			while (*chr <= '9' && *chr >= '0')
			{
				if (temp > INT32_MAX / 10 ||(temp == INT32_MAX / 10 && *chr - '0' > 6))
					return INT32_MAX;
				temp *= 10;
				temp += *chr - '0';
				chr++;
			}
		}
	}
	return temp;
}

int main()
{
	string s = "2147483648";
	cout << myAtoi(s) << endl;
	cout << INT32_MIN;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
