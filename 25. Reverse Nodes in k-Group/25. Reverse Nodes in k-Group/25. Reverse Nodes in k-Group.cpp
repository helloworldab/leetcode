// 25. Reverse Nodes in k-Group.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};



ListNode* reverseKGroup(ListNode* head, int k) {
	
	int i = k;
	ListNode *man_p = head;
	ListNode list_head(0);
	list_head.next = head;
	ListNode *sub_p = &list_head;
	ListNode *sub_fir = head, *sub_sec, *temp;
	if (head == NULL || k == 1)
		return head;

	while (man_p){
		while (man_p != NULL && i > 0) { //检测余链是否充足
			man_p = man_p->next;
			i--;
		}
		if (i > 0)
			return list_head.next;

		sub_sec = sub_fir->next;
		ListNode *start = sub_fir; //排序后的尾指针
		sub_fir->next = man_p;
		while (sub_sec != man_p) { //链表重新排序
			temp = sub_sec->next;
			sub_sec->next = sub_fir;
			sub_fir = sub_sec;
			sub_sec = temp;
		}
	
		sub_p->next = sub_fir;//重新排序后的链表加入结果链表
		sub_p = start;  //更新变换好的链表的尾指针

		sub_fir = man_p;
		i = k;
	}
	return list_head.next;
}



int main()
{
	ListNode head(0);
	ListNode *p = &head;
	for (int i = 1; i < 10; i++) {
		p->next = new ListNode(i);
		p = p->next;
	}
	p = reverseKGroup(head.next, 3);
	while (p) {
		cout << p->val << " ";
		p = p->next;
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
