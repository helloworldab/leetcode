// 10. Regular Expression Matching.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isMatch(string s, string p) 
{
	char *s_point = &s[0];
	int s_num;
	vector<char *> s_mark;

	char *p_point = &p[0];
	int p_num ;
	int p_flag;
	char p_char;
	vector<char *> p_mark;

	while (s_point != NULL && p_point != NULL)
	{
		s_num = 1;                         
		while (*s_point == *(s_point + 1))  //找主串的连续字符
		{
			s_num++;
			s_point++;
		}

		p_num = 0;                   //找主串的连续字符
		p_flag = 0;
		p_char = *p_point;
		while (p_point != NULL)
		{
			while (p_char == *p_point)
			{
				p_num++;
				p_point++;
			}
			if (*p_point == '#')
			{
				p_num--;
				p_flag = 1;
				p_point++;
			}
			else
				break;
		}
		//  匹配字符
		if (p_char == *(s_point - 1))      //匹配的字符一定不是.
		{
			if (s_num < p_num)    //匹配字符比主串的多
				return false;
			if(p_flag == 1)


		}
		else
		{

		}


	}
	return s_point == NULL && p_point == NULL;
}

int main()
{
	string s("b");
	char *p = &s[0];
	cout << p++ << endl;
	cout << p;

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
