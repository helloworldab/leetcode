// 29. Divide Two Integers.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
using namespace std;

int divide(int dividend, int divisor) {
	int flag = 0;
	int result = 1;
	int fir = 1;
	int sec = divisor;

	if (dividend == INT32_MIN) {
		switch (divisor)
		{
		case -1:
			return INT32_MAX;
		case 1:
			return INT32_MIN;
		case -2:
			return 1073741824;
		case 2: 
			return -1073741824;
		case INT32_MIN:
			return 1;
		}
		dividend++;
	}
	else if (dividend == INT32_MAX)
	{
		switch (divisor)
		{
		case -1:
			return -INT32_MAX;
		case 1:
			return INT32_MAX;
		case INT32_MAX:
			return 1;
		}
		dividend--;
	}
	if (divisor == INT32_MIN)
	{
		if (dividend == INT32_MIN)
			return 1;
		else
			return 0;
	}
	if (dividend < 0) flag++;
	if (divisor < 0) flag++;
	fir = abs(dividend);
	sec = abs(divisor);
	int temp = sec;
	if (fir < sec)
		return 0;
	while (fir >= temp << 1 && temp < 0x40000000) {
		temp <<= 1;
		result <<= 1;
	}
	while (fir - sec >= temp) {
		temp += sec;
		result++;
	}
	return flag == 0 || flag == 2 ? result : -result;
}

int main()
{
	cout << divide(2147483647,2147483647);
   // std::cout << "Hello World!\n"; 
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
