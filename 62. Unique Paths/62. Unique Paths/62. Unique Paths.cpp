// 62. Unique Paths.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

void myswap(vector<int> &v,int i,int j) {
	int temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

int uniquePaths1(int m, int n) {
	int num = 1;
	vector<int> v(m + n - 2, 1);
	m = m > n ? n - 1 : m - 1;
	for (int i = 0; i < m; i++)
		v[i] = 0;
	while (v.size() > 1) {
		int i, j;
		for (i = v.size() - 1; i > 0; i--) {
			if (v[i - 1] < v[i])
				break;
			else if (i == 1)
				return num;
		}
		num++;
		myswap(v, i, i - 1);
		for (j = v.size() - 1, i++; i < j; i++, j--)
			myswap(v, i, j);
	}
	return num;
}

int uniquePaths(int m, int n) {
	int sum = n + m - 2;
	int result = 1;
	int min = n > m ? m - 1 : n - 1;		//取m，n中较小的值
	for (int i = 1;i <= min; i++,sum--) {
		if (result % i == 0) {
			result /= i;
			result *= sum;
		}
		else {
			result *= sum;
			result /= i;
		}
	}
	return result;
}
//1916797311
int main()
{
	cout << uniquePaths(51, 9);
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
