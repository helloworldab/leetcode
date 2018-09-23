// 18. 4Sum.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

void quick_sort(vector<int> &nums, int head, int end) {
	if (head >= end)
		return;
	int l = head;
	int h = end;
	int data = nums[head];
	while (h > l) {
		while (h > l && nums[h] >= data) h--;
		nums[l] = nums[h];
		while (h > l && nums[l] <= data) l++;
		nums[h] = nums[l];
	}
	nums[h] = data;
	quick_sort(nums, head, h - 1);
	quick_sort(nums, h + 1, end);
}


vector<vector<int>> fourSum(vector<int>& nums, int target) {
	vector<vector<int>> vec;
	int size = nums.size();
	if (size < 4)
		return vec;
	quick_sort(nums, 0, size - 1);
	for (int i = 0; 4 * nums[i] <= target; i++){ //第一个数字
		if(i > 0)
		if (nums[i] == nums[i - 1])
			continue;
		for (int j = i + 1; j < size - 2; j++) {//第二个数字
			if (nums[j] == nums[j - 1] && j > i + 1) 
				continue;
			for (int k = j + 1; k < size - 1; k++) {//第三个数字
				if (nums[k] == nums[k - 1] && k > j + 1)
					continue;
				int k1 = k + 1;
				int k3 = size - 1;
				int sum = nums[i] + nums[j] + nums[k];
				if (sum + nums[k1] > target || sum + nums[k3] < target) //第四个数字在区域外
					continue;
				while (k1 <= k3) {
					int k2 = (k1 + k3) / 2;
					if (sum + nums[k2] > target)
						k3 = k2 - 1;
					else if (sum + nums[k2] < target)
						k1 = k2 + 1;
					else {
						vec.push_back({ nums[i], nums[j], nums[k], nums[k2] });
						break;
					}
				}
			}
		}
	}
	return vec;
}
int main()
{
	vector<int> vec = { 0, 0, 4, -2, -3, -2, -2, -3 };
	quick_sort(vec, 0, vec.size() - 1);
	for (int c : vec)
		cout << c << " ";
	cout << endl;
	vector<vector<int>> vec2;
	vec2 = fourSum(vec, -1);
	for (vector<int> c : vec2) {
		for (int c2 : c)
			cout << c2 << " ";
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
