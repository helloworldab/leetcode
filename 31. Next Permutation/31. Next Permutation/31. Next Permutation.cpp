// 31. Next Permutation.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;
void my_swap(vector<int> &nums, int i, int j) {
	int temp = nums[i];
	nums[i] = nums[j];
	nums[j] = temp;
}
void nextPermutation(vector<int>& nums) {
	int i, j;
	if (nums.size() < 2)
		return;
	for (i = nums.size() - 2; i >= 0; i--) {
		if (nums[i] < nums[i + 1])
			break;
		else if (i == 0) {
			int k = nums.size() - 1;
			while (k > i)
				swap(nums[k--], nums[i++]);
			return;
		}
	}
	for (j = nums.size() - 1; j > i; j--)
		if (nums[i] < nums[j])
			break;
	my_swap(nums,i,j);
	i++;
	for (j = nums.size() - 1; i < j; i++, j--)
		my_swap(nums, j, i);
}
int main()
{
	vector<int> vec({ 1,2,3 });
	nextPermutation(vec);
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
