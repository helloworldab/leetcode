// 17. Letter Combinations of a Phone Number.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>	
using namespace std;
const char  date[8][5] = {
	{'a','b','c',' ','3'},  //2
	{'d','e','f',' ','3'},  //3
	{'g','h','i',' ','3'},  //4
	{'j','k','l',' ','3'},  //5
	{'m','n','o',' ','3'},  //6
	{'p','q','r','s','4'},	//7
	{'t','u','v',' ','3'},  //8
	{'w','x','y','z','4'},	//9
};
vector<string> letterCombinations(string digits) 
{
	vector<string> vec;
	if (digits.size() == 0)
		return vec;
	int num = 0;
	string str;
	while (num < date[digits[0] - '2'][4] - '0')
	{
		str.push_back(date[digits[0] - '2'][num++]);
		vec.push_back(str); //date[digits[0] - '2'][num++]
		str.clear();
	}
	int z = num;
	for(char *p = &digits[1]; *p != '\0'; p++)
	{
		int c = *p - '2';
		int size = date[c][4] - '0';
		for (int k = 0; k < num; k++)
		{
			for (int i = 1; i < size; i++)
			{
				vec.push_back(vec[k]);
				vec[z++].push_back(date[c][i]);
				
			}
			vec[k] += date[c][0];
		}
		num *= size;
	}
	return vec;
}

int main()
{
	string str;
	vector<string> vec;
	vec = letterCombinations("23");
	for (string c : vec)
		cout << c << endl;
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
