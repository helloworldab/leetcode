// 74. Search a 2D Matrix.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
	if (matrix.size() == 0 || matrix[0].size() == 0)
		return false;
	int column = matrix[0].size();
	int k1 = 0, k;
	int k2 = matrix.size() * column - 1;
	int temp;
	if (target < matrix[0][0] || target > matrix[matrix.size() - 1][matrix[0].size() - 1])
		return false;
	while (k1 <= k2) {
		k = (k1 + k2) >> 1;
		temp = matrix[k / column][k % column];
		if (temp < target)
			k1 = k + 1;
		else if (temp > target)
			k2 = k - 1;
		else
			return true;
	}
	return false;
}


int main()
{
	vector<vector<int>> v2({
		{}
		//{1,3}
		//{1,   3,  5,  7},
		//  {10, 11, 16, 20},
		//  {23, 30, 34, 50}
		});
	cout << searchMatrix(v2, 3) << endl;
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
