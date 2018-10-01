// 27. Remove Element.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;


int removeElement(vector<int>& nums, int val) {
	int start = 0;
	int end = nums.size() - 1;
	if (end < 0)
		return 0;
	while (start <= end) {
		while (nums[start] != val && start < end)
			start++;
		while (nums[end] == val && start < end)
			end--;
		nums[start++] = nums[end--];
	}
	return nums[start-1] == val ? start - 1 : start;
}

int main()
{
	vector<int> vec({ 0,1,2,2,3,0,4,2 });
	cout << removeElement(vec, 2) << endl;
	for (int c : vec)
		cout << c << " ";

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
