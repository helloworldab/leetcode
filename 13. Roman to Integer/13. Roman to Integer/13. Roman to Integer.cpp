// 13. Roman to Integer.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
using namespace std;

const int num_tab[13] = { 1000,900,500,400,100,90,50,40,10,9,5,4,1 };
const string str[13] = { "M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I" };

int romanToInt(string s)
{
	int num = 0;
	char *p = &s[0];
	while (*p != '\0')
	{
		switch (*p)
		{
		case 'M':
			p++;
			num += 1000;
			break;
		case 'D':
			p++;
			num += 500;
			break;
		case 'L':
			p++;
			num += 50;
			break;
		case 'V':
			p++;
			num += 5;
			break;
		case 'C':
			p++;
			switch (*p)
			{
			case 'M':
				num += 900;
				p++;
				break;
			case 'D':
				num += 400;
				p++;
				break;
			default:
				num += 100;
				break;
			}
			break;
		case 'X':
			p++;
			switch (*p)
			{
			case 'C':
				num += 90;
				p++;
				break;
			case 'L':
				num += 40;
				p++;
				break;
			default:
				num += 10;
				break;
			}
			break;
		case 'I':
			p++;
			switch (*p)
			{
			case 'X':
				num += 9;
				p++;
				break;
			case 'V':
				num += 4;
				p++;
				break;
			default:
				num += 1;
				break;
			}
			break;
		}//end of switch (*p)5
	}//end of while(p != nullptr)
	return num;
}

int main()
{
	string s = "III";
	cout << romanToInt(s);
    std::cout << "Hello World!\n";
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
