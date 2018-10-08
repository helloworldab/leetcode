// 46. Permutations.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

void myswap(int a, int b, vector<int> &da) {
	int temp = da[a];
	da[a] = da[b];
	da[b] = temp;
}

void permute1(vector<int> &data, vector<vector<int>> &vec, int n) {
	if (n == data.size() - 1)
		vec.push_back(data);
	else {
		for (int i = n; i < data.size(); i++) {
			myswap(i,n,data);
			permute1(data, vec, n + 1);
			myswap(i, n, data);
		}
	}
}

vector<vector<int>> permute(vector<int>& nums) {
	vector<vector<int>> arry;
	permute1(nums, arry, 0);
	return arry;
}


int main()
{
	vector<int> vec({ 1,2,3 });
	vector<vector<int>> vec2;
	vec2 = permute(vec);
	for (vector<int> v : vec2) {
		for (int i : v)
			cout << i << " ";
		cout << endl;
	}
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
