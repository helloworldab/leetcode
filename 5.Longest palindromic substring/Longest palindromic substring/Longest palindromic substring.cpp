// Longest palindromic substring.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;


string longestPalindrome(string s)
{
	int start = 0;
	int index = 0, i, j;
	int length = 1;
	if (s.size() == 0)
		return "";
	while (index < s.size()-1)
	{
		if (s[index] == s[index + 1])
		{
			i = index;
			j = index + 1;
			while (s[i] == s[j])
			{
				i--;
				j++;
				if (i < 0 || s[j] == 0)
					break;
			}
			if (j - i > length + 1)
			{
				start = i + 1;
				length = j - i - 1;
			}
		}
		if (index > 0 && s[index - 1] == s[index + 1])
		{
			i = index - 1;
			j = index + 1;
			while (s[i] == s[j])
			{
				i--;
				j++;
				if (i < 0 || s[j] == 0)
					break;
			}
			if (j - i > length + 1)
			{
				start = i + 1;
				length = j - i - 1;
			}
		}
		index++;
	}
	return s.substr(start, length);
}

int main()
{
	string s = "babad";
	s = longestPalindrome(s);
	cout << s << endl;
	
    std::cout << "Hello World!\n"; 
}
