// 42. Trapping Rain Water.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

int trap(vector<int>& height) {
	int i = 0;
	int max_p = 0;
	while (i < height.size()) {
		if (height[i] > height[max_p])
			max_p = i;
		i++;
	}
	if (height.empty() || height[max_p] == 0)
		return 0;
	int p1;
	int sum = 0;
	int sum2 = 0;
	i = 0;
	while (i < max_p && height[i] == 0) i++;//滤除开头连续的零元素
	p1 = i++;
	while (i <= max_p) {  //正向扫描判断
		if (height[i] >= height[p1]) {
			if (i == p1 + 1) {
				p1 = i++;
				continue;
			}
			sum += (i - p1 - 1) * height[p1];
			sum -= sum2;
			p1 = i;
			sum2 = -height[i];
		}
		sum2 += height[i];
		i++;
	}
	sum2 = 0;
	i = height.size() - 1;
	while (i > max_p && height[i] == 0) i--;//滤除开头连续的零元素
	p1 = i--;
	while (i >= max_p) {
		if (height[i] >= height[p1] ) {
			if (i == p1 - 1) {
				p1 = i--;
				continue;
			}
			sum += (p1 - i - 1) * height[p1];
			sum -= sum2;
			p1 = i;
			sum2 = -height[i];
		}
		sum2 += height[i];
		i--;
	}
	return sum;
}

int main()
{
	vector<int> vec({ 1,0,2,1,0,1,3,2,1,2,1 });
	cout << trap(vec);
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
