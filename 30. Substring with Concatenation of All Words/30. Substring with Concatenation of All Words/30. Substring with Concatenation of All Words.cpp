// 30. Substring with Concatenation of All Words.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void quick_sort(vector<int> &vec, int min, int max) {
	if (min >= max)
		return;
	int h = max;
	int l = min;
	int data = vec[l];
	while (h > l) {
		while (h > l && vec[h] >= data)h--;
		vec[l] = vec[h];
		while (h > l && vec[l] <= data)l++;
		vec[h] = vec[l];
	}
	vec[h] = data;
	quick_sort(vec, min, l - 1);
	quick_sort(vec, l + 1, max);
}

void getnext(string s, vector<int> &next) {
	int k = -1;
	int i = 0;
	next[0] = -1;
	while (i < s.size())
	{
		if (k == -1 || s[k] == s[i])
			next[++i] = ++k;
		else
			k = next[k];
	}
}

vector<int> kmp(string &s1, string &s2) {
	int i = 0;
	int j = 0;
	vector<int> next(s2.size() + 1, 0);
	vector<int> result;
	getnext(s2, next);
	while (i < s1.size()) {
		if (j == -1 || s1[i] == s2[j]) {
			i++;
			j++;
		}
		else
			j = next[j];
		if (j == s2.size()) {
			i = i - j;
			result.push_back(i);
			i++;
			j = 0;
		}
	}
	return result;
}

void swap(vector<int> &vec, int x, int y) {
	int temp = vec[x];
	vec[x] = vec[y];
	vec[y] = temp;
}
//排列组合产生不重复的组合     递归方式
void permutation(vector<vector<int>> &vec, vector<int> &data, int head, int end) {
	vector<bool> hash(data.size(), 0); //查重用
	if (head == end) 
		vec.push_back(data);
	else {
		for (int i = head; i <= end; i++) {
			if (hash[data[i]] == 1) //滤除重复的项
				continue;
			swap(data, i, head);
			permutation(vec, data, head + 1, end);
			swap(data, i, head);
			hash[data[i]] = 1;
		}
	}
}


void Permutation(vector<int> &a)
{
	int i, j;
	while (1)
	{
		// 打印输出
		for (i = 0; i < a.size(); ++i)
		{
			cout << a[i] << " ";
		}
		cout << endl;
		cin.get();
		// 后->前，找到【Ai<A(i+1)】的[i]位置
		for (i = a.size() - 2; i >= 0; --i)
		{
			if (a[i] < a[i + 1])
				break;
			else if (i == 0) // 找不到升序的数据，全排列结束。
				return;
		}
		// 后->前，找到比【Aj>Ai】的[j]位置
		for (j = a.size() - 1; j > i; --j)
		{
			if (a[j] > a[i])
			{
				break;
			}
		}
		// 交换位置i,j的值
		swap(a, i, j);
		// 【(i+1)至结束位置】的所有数据逆序
		i++;
		j = a.size() - 1;
		for (; i < j; ++i, --j)
		{
			swap(a, i, j);
		}
	}
}

bool wrods_check(string &a, string &b) {
	for (int i = 0; i < a.size(); i++) {
		if (a[i] != b[i])
			return false;
	}
	return true;
}

vector<int> findSubstring(string s, vector<string>& words) {
	vector<int> result;
	vector<int> words_pos(words.size(), -1);//单词的映射表
	vector<vector<int>> que; //排列组合序列
	string str;

	if (s.empty() == true || words.empty() == true)
		return result;
	int max_num = 0;
	int min_num = s.size();
	for (string c : words) {
		vector<int> temp = kmp(s, c);
		if (temp.empty() == true)
			return result;
		if (min_num < temp[0])
			min_num = temp[0];
		if (max_num > temp[temp.size() - 1])
			max_num = temp[temp.size() - 1];	
	}
	if (max_num - min_num < words[0].size() * (words.size()-1))
		return result;




	//建立单词的映射表 映射之后 words[k] == words[wors_pos[k]] 成立 但是words_pos[k] 不一定等于 k
	for (int i = words_pos.size()-1; i >= 0; i--) {
		if (words_pos[i] != -1) //数值发生变化，说明已经与之前的已经重复了，跳过
			continue;
		words_pos[i] = i;
		for (int k = i - 1; k >= 0; k--) {
			if (wrods_check(words[i], words[k]))
				words_pos[k] = i;
		}
	}
	//产生映射表的非重复组合    递归方式
	//permutation(que, words_pos, 0, words_pos.size() - 1);
	//for (vector<int> c : que) {
	//	str.clear();
	//	for (int k : c)
	//		str.append(words[k]);
	//	vector<int> temp = kmp(s, str);
	//	for (int temp1 : temp)
	//		result.push_back(temp1);
	//}
	/*
	字典序变化（1234---->  4321）
	1.从最右边开始比较两两相邻的元素，直至找到右边比左边大的一对，左边那个
	2.就是将要被替换的，再从最右边开始找比这个元素大的第一个，交换他们两个
	3.交换之后，翻转交换元素的后面的所有元素
	*/
	int sum = 0;
	//排列组合产生不重复的组合，  非递归
	quick_sort(words_pos, 0, words_pos.size() - 1);
	while (1) {
		sum++;
		cout << sum << endl;
		str.clear();
		for (int key : words_pos) //加载字符
			str.append(words[key]);
		vector<int> temp = kmp(s, str);  //比较字符串
		for (int temp1 : temp)		//添加结果
			result.push_back(temp1);
		//产生映射表的非重复组合， 非递归方式
		//1   后->前，找到【Ai<A(i+1)】的[i]位置
		int i, j;
		if (words_pos.size() < 2)
			return result;
		for (i = words_pos.size() - 2; i >= 0; i--) {
			if (words_pos[i] < words_pos[i + 1])
				break;
			else if (i == 0)
				return result;
		}
		//2  后->前，找到比【Aj>Ai】的[j]位置
		for (j = words_pos.size() - 1; j > i; j--) {
			if (words_pos[j] > words_pos[i])
				break;
		}
		//3 交换数据
		swap(words_pos, i, j);
		//4  【(i+1)至结束位置】的所有数据逆序
		for (i++, j = words_pos.size() - 1; i < j; i++, j--)
			swap(words_pos, i, j);
	}
}

int main()
{
	string s("pjzkrkevzztxductzzxmxsvwjkxpvukmfjywwetvfnujhweiybwvvsrfequzkhossmootkmyxgjgfordrpapjuunmqnxxdrqrfgkrsjqbszgiqlcfnrpjlcwdrvbumtotzylshdvccdmsqoadfrpsvnwpizlwszrtyclhgilklydbmfhuywotjmktnwrfvizvnmfvvqfiokkdprznnnjycttprkxpuykhmpchiksyucbmtabiqkisgbhxngmhezrrqvayfsxauampdpxtafniiwfvdufhtwajrbkxtjzqjnfocdhekumttuqwovfjrgulhekcpjszyynadxhnttgmnxkduqmmyhzfnjhducesctufqbumxbamalqudeibljgbspeotkgvddcwgxidaiqcvgwykhbysjzlzfbupkqunuqtraxrlptivshhbihtsigtpipguhbhctcvubnhqipncyxfjebdnjyetnlnvmuxhzsdahkrscewabejifmxombiamxvauuitoltyymsarqcuuoezcbqpdaprxmsrickwpgwpsoplhugbikbkotzrtqkscekkgwjycfnvwfgdzogjzjvpcvixnsqsxacfwndzvrwrycwxrcismdhqapoojegggkocyrdtkzmiekhxoppctytvphjynrhtcvxcobxbcjjivtfjiwmduhzjokkbctweqtigwfhzorjlkpuuliaipbtfldinyetoybvugevwvhhhweejogrghllsouipabfafcxnhukcbtmxzshoyyufjhzadhrelweszbfgwpkzlwxkogyogutscvuhcllphshivnoteztpxsaoaacgxyaztuixhunrowzljqfqrahosheukhahhbiaxqzfmmwcjxountkevsvpbzjnilwpoermxrtlfroqoclexxisrdhvfsindffslyekrzwzqkpeocilatftymodgztjgybtyheqgcpwogdcjlnlesefgvimwbxcbzvaibspdjnrpqtyeilkcspknyylbwndvkffmzuriilxagyerjptbgeqgebiaqnvdubrtxibhvakcyotkfonmseszhczapxdlauexehhaireihxsplgdgmxfvaevrbadbwjbdrkfbbjjkgcztkcbwagtcnrtqryuqixtzhaakjlurnumzyovawrcjiwabuwretmdamfkxrgqgcdgbrdbnugzecbgyxxdqmisaqcyjkqrntxqmdrczxbebemcblftxplafnyoxqimkhcykwamvdsxjezkpgdpvopddptdfbprjustquhlazkjfluxrzopqdstulybnqvyknrchbphcarknnhhovweaqawdyxsqsqahkepluypwrzjegqtdoxfgzdkydeoxvrfhxusrujnmjzqrrlxglcmkiykldbiasnhrjbjekystzilrwkzhontwmehrfsrzfaqrbbxncphbzuuxeteshyrveamjsfiaharkcqxefghgceeixkdgkuboupxnwhnfigpkwnqdvzlydpidcljmflbccarbiegsmweklwngvygbqpescpeichmfidgsjmkvkofvkuehsmkkbocgejoiqcnafvuokelwuqsgkyoekaroptuvekfvmtxtqshcwsztkrzwrpabqrrhnlerxjojemcxel");
	string sub("abaababbaba");
	vector<string> words({ "dhvf", "sind", "ffsl", "yekr", "zwzq", "kpeo", "cila", "tfty", "modg", "ztjg", "ybty", "heqg", "cpwo", "gdcj", "lnle", "sefg", "vimw", "bxcb"});
	vector<int> vec;
	//int temp = kmp(s, sub);
	vec = findSubstring(s, words);
	for(int c:vec)
		cout << c << " ";

	//vector<vector<int>> vec1;
	//vector<int> vec2 = {2,2,3,3};
	//Permutation(vec2);
	//permutation(vec1, vec2, 0, vec2.size() - 1);
	//for (vector<int> v1 : vec1) {
	//	for (int c : v1)
	//		cout << c << " ";
	//	cout << endl;
	//}
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
