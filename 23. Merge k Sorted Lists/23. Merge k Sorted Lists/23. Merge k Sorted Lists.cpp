// 23. Merge k Sorted Lists.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL) {}
};

struct mylist {
	ListNode *p;
	mylist *next;
	mylist(ListNode *p	): p(p),next(NULL){}
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
	mylist list(NULL	);
	mylist *my = &list;
	for(ListNode *c:lists)   //创建单向链表便于删除空链表
		if (c != NULL) {
			my->next = new mylist(c);
			my = my->next;
		}

	ListNode head(0); //头指针，存储结果用
	ListNode *p = &head;
	
	while (list.next) { //外循环判断链表是否为空
		int min_num = list.next->p->val;
		mylist *p1 = list.next, *p2 = list.next->next;
		mylist *max_list = &list;
		while (p2) {   //内循环查找最小数  遍历mylist 主链
			if (p2->p->val < min_num) {
				max_list = p1;
				min_num = p2->p->val;
			}
			p1 = p1->next;
			p2 = p2->next;
		}
		p->next = max_list->next->p;  //存储节点   
		if (p->next->next == NULL) {         //删除主链上的空子链
			p2 = max_list->next;
			max_list->next = max_list->next->next;
			delete p2;
		}
		else
			max_list->next->p = p->next->next; //删除子链节点
		p = p->next;   //更新结果链指针
	}
	return head.next;
}

int main()
{
	ListNode head1(0);
	ListNode *p = &head1;
	for (int i = 0; i <= 3; i++) {
		p->next = new ListNode(i);
		p = p->next;
	}
	ListNode head2(0);
	p = &head2;
	for (int i = 0; i <= 4; i++) {
		p->next = new ListNode(i);
		p = p->next;
	}
	ListNode head3(0);
	p = &head3;
	for (int i = 0; i <= 5; i++) {
		p->next = new ListNode(i);
		p = p->next;
	}
	vector<ListNode *> vec({ head1.next,head2.next,head3.next });
	ListNode *head;
	head = mergeKLists(vec);
	while (head) {
		cout << head->val << " ";
		head = head->next;
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
