/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
static int flag =0;
class Solution {
public:
int add(int a, int b )
{
    int temp = a + b;
    if (flag)
        temp++;
    if (temp >= 10)
    {
        temp -= 10;
        flag=1;
    }
    else
        flag=0;
    return temp;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *l = NULL, *head;
    l = head = new ListNode(0);
    while (l1->next != NULL && l2->next != NULL)
    {
        l->val = add(l1->val , l2->val);
        l->next = new ListNode(0);

        l = l->next;
        l1 = l1->next;
        l2 = l2->next;
    }
    l->val = add(l1->val , l2->val);

 //   print_list(head);
    if(l1->next != NULL)
    {
        l->next = new ListNode(0);
        l = l->next;

        l1 = l1->next;
        //l->val = add(l1->val , 0);
        while(l1->next != NULL)
        {
            l->val = add(l1->val , 0 );
            l->next = new ListNode(0);
            l = l->next;
            l1 = l1->next;
        }
        l->val = add(l1->val , 0);
    }

    if(l2->next != NULL)
    {
        l->next = new ListNode(0);
        l = l->next;

        l2 = l2->next;
       // l->val = add(l2->val , 0);
        while(l2->next != NULL)
        {
            l->val = add(l2->val , 0 );
            l->next = new ListNode(0);
            l = l->next;
            l2 = l2->next;
        }
        l->val = add(l2->val , 0 );
    }
    if(flag)
        l->next = new ListNode(1);
    flag=0;
    return head;
}
};
