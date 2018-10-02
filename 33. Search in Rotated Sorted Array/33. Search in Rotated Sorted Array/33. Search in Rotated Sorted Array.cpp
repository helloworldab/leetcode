// 33. Search in Rotated Sorted Array.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>& nums, int target) {
	int min = 0;
	int max = nums.size() - 1;
	int k;
	bool flag = false; //数据有序标志位
	while (min <= max) {
		if (target > nums[max] && target < nums[min])
			return -1;
		k = (min + max) >> 1;
		if (flag == false) {                        
			if (target <= nums[max]) {           //数据在前端
				if (target >= nums[min])//数据有序？
					flag = true;
				else if (target == nums[k])
					return k;
				else if (target > nums[k] || nums[k] > nums[max])
					min = k + 1;
				else if(target < nums[k])
					max = k - 1;
			}
			else {                         //数据在后端
				if (target <= nums[max])	   //数据有序？
					flag = true;
				else if (target == nums[k])
					return k;
				else if (target < nums[k] || nums[k] < nums[min])
					max = k - 1;
				else if(target > nums[k])
					min = k + 1;
			}
		}
		else {        //数据已经有序，2分查找
			if (target < nums[k])
				max = k - 1;
			else if (target > nums[k])
				min = k + 1;
			else
				return k;
		}
	}
	return -1;
}

int main()
{
	vector<int> vec({ 4, 5, 6, 7, 8, 1, 2, 3 });
	cout<<search(vec, 8);
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
