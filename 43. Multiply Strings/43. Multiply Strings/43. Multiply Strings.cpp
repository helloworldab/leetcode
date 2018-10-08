// 43. Multiply Strings.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

int string_to_array(string &s, long int *p) {//小端存储
	int i = s.size() - 1;
	int j = 0;
	while (i > 2) {   //最大值 99999999
		p[j] = s[i] - '0'
			+ (s[i - 1] - '0') * 10
			+ (s[i - 2] - '0') * 100
			+ (s[i - 3] - '0') * 1000;
		i -= 4;
		j++;
	}
	//p[j] = 0;
	for (int k = 0; k <= i; k++) {
		p[j] = p[j] * 10 + s[k] - '0';
	}
	return j; //数组的长度
}
string array_to_string(long int *p, int i) {
	string s;
	int temp[4];
	int k;
	while (i >= 0 && p[i] == 0)
		i--;
	if (i == -1)
		return "0";
	for (k = 0; k < 4; k++) {
		temp[k] = p[i] % 10;
		p[i] /= 10;
	}
	for (k = 3; k >= 0 && temp[k] == 0; k--);//滤除前面的0
	while (k >= 0)
		s.push_back(temp[k--] + '0');
	i--;
	while (i >= 0) {
		s.push_back((p[i] / 1000)%10 + 48);
		s.push_back((p[i] / 100)%10 + 48);
		s.push_back((p[i] / 10)%10 + 48);
		s.push_back(p[i]%10 + 48);
		i--;
	}
	return s;
}

string multiply(string num1, string num2) {
	long int a[30] = { 0 };
	long int b[30] = { 0 };
	long int c[60] = { 0 }; // c = a * b
	int a_size = string_to_array(num1, a);
	int b_size = string_to_array(num2, b);
	for(int i = 0; i <= a_size; i++)
		for (int j = 0; j <= b_size; j++) {
			int k = i + j;
			c[k] += a[i] * b[j];
			while (c[k] > 9999) {
				c[k + 1] += c[k] / 10000;
				c[k] = c[k] % 10000;
				k++;
			}
		}
	return array_to_string(c,a_size + b_size + 3);
}
int main()
{
	string s1("123456789");
	string s2("987654321");
	long int a[60] = { 5269, 1263, 6311, 1932, 12, 0};

	cout << multiply(s1, s2);

	//string_to_array(s1,a);
	s2 = array_to_string(a,5);

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
