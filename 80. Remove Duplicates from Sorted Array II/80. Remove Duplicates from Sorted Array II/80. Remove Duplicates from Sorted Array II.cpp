// 80. Remove Duplicates from Sorted Array II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
	int temp = 1, i, j;
	if (nums.size() == 0)
		return 0;
	for(j = 1,i = 1;j < nums.size();j++){
		if (nums[j] != nums[j - 1])
			temp = 1;
		else {
			temp++;
			if (temp == 3) {
				while (++j < nums.size() && nums[j] == nums[j - 1]);
				if (j == nums.size())
					return i;
				temp = 1;
			}

		}
		nums[i++] = nums[j];
	}
	return i;
}

int main()
{
	vector<int> v1({ 1, 1, 1, 2, 2, 2, 3, 3 });
	int n = removeDuplicates(v1);
	for (int i = 0; i < n; i++)
		cout << v1[i] << " ";
	cout << endl;
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
