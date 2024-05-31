/*
给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right 。
请你反转从位置 left 到位置 right 的链表节点，返回 反转后的链表 。
*/

#include <iostream>
using namespace std;

typedef struct ListNode
{
    int val;
    ListNode *next;
} ListNode;

ListNode *reverseBetween(ListNode *head, int left, int right)
{
    ListNode *begin = new ListNode;
    begin->next = head;
    ListNode *p = begin;
    for (int i = 0; i < left - 1; i++)
        p = p->next;
    ListNode *q = p->next;
    for (int i = 0; i < right - left; i++)
    {
        ListNode *temp = q->next;
        q->next = temp->next;
        temp->next = p->next;
        p->next = temp;
    }
    return begin->next;
}

ListNode *createByTail(int len)
{
    ListNode *head = new ListNode;
    head->next = NULL;
    ListNode *p1 = head;
    for (int i = 0; i < len; ++i)
    {
        ListNode *p2 = new ListNode;
        cin >> p2->val;
        p1->next = p2;
        p1 = p2;
    }
    p1->next = NULL;
    return head->next;
}

int main()
{
    int len;
    cin >> len;
    ListNode *head = createByTail(len);
    int left, right;
    cin >> left >> right;
    head = reverseBetween(head, left, right);
    ListNode *p = head;
    cout << "head-->";
    while (p)
    {
        cout << p->val << "-->";
        p = p->next;
    }
    cout << "tail" << endl;
    return 0;
}