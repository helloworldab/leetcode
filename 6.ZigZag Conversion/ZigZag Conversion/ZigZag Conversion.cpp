// ZigZag Conversion.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

string convert(string s, int numRows) 
{
	string s2;
	int num_i = 1;
	int sub_i = 0;
	int man_i = 0;

	int pack = numRows * 2 - 2;
	if (pack == 0)  //numRows 为1时，串不变
		return s;
	int man = s.length() / pack;  //字符串包的个数
	int sub = s.length() % pack;  //剩下的字符串的个数

	int sub_m_i = 1;
	int sub_m = sub / numRows;   //末尾子串第一列字符个数       
	int sub_s = sub % numRows;   //末尾子串第二列字符个数
	if (sub_m == 1)
		sub_m = numRows;
	else
	{
		sub_m = sub_s;
		sub_s = 0;
	}
	
	//添加第1行字符
	for (man_i = 0; man_i < man; man_i++)
		s2.push_back(s.at(man_i * pack));
	if (sub_m > 0)
		s2.push_back(s.at(man * pack));
		
	//添加第2至n-1行字符
	int n = 1;
	while (n < numRows - 1)
	{
		for (man_i = 0; man_i < man; man_i++)
		{
			s2.push_back(s.at(man_i * pack + n));
			s2.push_back(s.at(man_i * pack + pack - n));
		}
		if (sub_m_i < sub_m)
			s2.push_back(s.at(man * pack + sub_m_i++));
		if (sub_s >= numRows - n - 1)
		{
			sub_s--;
			s2.push_back(s.at(man * pack + numRows + sub_s));
		}
		n++;
	}

	//添加第n行字符
	for (man_i = 0; man_i < man; man_i++)
		s2.push_back(s.at(man_i * pack + numRows - 1));
	if (numRows == sub_m	)
		s2.push_back(s.at(man * pack + numRows - 1));
	return s2;
}


int main()
{
	string s("ABCDE");
	string s2;
	s2 = convert(s, 4);
	cout << s2 << endl;

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