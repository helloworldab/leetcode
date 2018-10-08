// 36. Valid Sudoku.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
// 标号   x  y
const int ps[9][2] = {     
	{3,3},{6,3},{9,3},
	{3,6},{6,6},{9,6},
	{3,9},{6,9},{9,9}
};
bool isValidSudoku(vector<vector<char>>& board) {
	vector<bool> hash(128, 0);
	vector<bool> hash_temp(128, 0);
	
	for (vector<char> v1 : board) {  //行扫描
		for (char c : v1) {
			if (hash_temp[c] == 1 && c != '.')
				return false;
			hash_temp[c] = 1;
		}
		hash_temp = hash; //hash数组恢复数据
	}
	
	for (int i = 0; i < 9; i++) {	//列扫描
		for (int j = 0; j < 9; j++) {
			if (hash_temp[board[j][i]] == 1 && board[j][i] != '.')
				return false;
			hash_temp[board[j][i]] = 1;
		}
		hash_temp = hash; //hash数组恢复数据
	}

	for (int i = 0; i < 9; i++) {
		for (int x = ps[i][0] - 3; x < ps[i][0]; x++) { //行扫描
			for (int y = ps[i][1] - 3; y < ps[i][1]; y++) { //列扫描
				if (hash_temp[board[x][y]] == 1 && board[x][y] != '.')
					return false;
				hash_temp[board[x][y]] = 1;
			}
		}
		hash_temp = hash;
	}
	return true;
}
char map[9][9] = {
	{'8','3','.','.','7','.','.','.','.'},
	{'6','.','.','1','9','5','.','.','.'},
	{'.','9','8','.','.','.','.','6','.'},
	{'8','.','.','.','6','.','.','.','3'},
	{'4','.','.','8','.','3','.','.','1'},
	{'7','.','.','.','2','.','.','.','6'},
	{'.','6','.','.','.','.','2','8','.'},
	{'.','.','.','4','1','9','.','.','5'},
	{'.','.','.','.','8','.','.','7','9'}
};
int main()
{
	vector<vector<char>> vec(9, vector<char>(9));
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			vec[i][j] = map[i][j];

	cout << isValidSudoku(vec);
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
