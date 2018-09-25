// 22. Generate Parentheses.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> generateParenthesis(int n) {
	//[x][0] ( 和 ) 的逻辑和 （ 为 +1,  ) 为-1
	//[x][1] （  的个数
	vector<vector<int>> flag(1, vector<int>(2,1));
	vector<string> vec(1,"(");
	if (n == 0) {
		vec.clear();
		return vec;
	}
	int size = n * 2;
	int length = 1; //vec 的大小
	for (int i = 1; i < size; i++) {		
		for (int k = 0; k < length; k++) { //扫描 vec 
			//原始字符串
			if (flag[k][0] > 0) { //添加 ）
				vec[k].push_back(')');
				flag[k][0]--;
			}
			else {
				vec[k].push_back('(');
				flag[k][0]++;
				flag[k][1]++;
			}
			//拓展字符串
			if (vec[k][i] == ')') {  //原始字符串添加的是 ')'
				if (flag[k][1] < n) { //添加 '('
					vec.push_back(vec[k]);
					vec[vec.size() - 1][i] = '(';
					flag.push_back({flag[k][0] + 2, flag[k][1] + 1});
				}
			}
			else if (flag[k][0] > 1) {//原始字符串添加的是 '('
				vec.push_back(vec[k]);
				vec[vec.size() - 1][i] =  ')';
				flag.push_back({ flag[k][0] - 2, flag[k][1] - 1});
			}
		}
		length = vec.size();
	}
	return vec;
}

int main()
{
	vector<string> vec;
	vec = generateParenthesis(3);
	for (string c : vec)
		cout << c << endl;


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
