// 45. Jump Game II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

int jump(vector<int>& nums) {
	int steps = 0;
	int max_size = nums.size() - 1;
	if (max_size < 1)
		return 0;
	int i = 0;
	while(i< nums.size()) {
		int max_p = i + nums[i];
		steps++;
		if (max_p >= max_size)
			return steps;
		int max_temp = max_p;
		int max_sum = max_temp + nums[max_temp];
		for (max_p--; max_p > i; max_p--) {
			if (max_p + nums[max_p] > max_sum) {
				max_temp = max_p;
				max_sum = max_p + nums[max_p];
			}
		}
		i = max_temp;
	}
	return steps;
}
int main()
{
	vector<int> vec({ 2,3,1,1,4 });
	cout << jump(vec);
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
