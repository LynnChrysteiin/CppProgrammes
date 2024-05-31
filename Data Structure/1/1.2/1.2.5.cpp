/*
给你一个单链表，链表中每个结点的值不是 0 就是 1。已知此链表是一个整数数字的二进制表示形式。
请你返回该链表所表示数字的 十进制值 。
*/

#include <iostream>
using namespace std;

typedef struct ListNode
{
    int val;
    ListNode *next;
} ListNode;

ListNode *create_by_tail()
{
    int len;
    cin >> len;
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
    return head;
}

int main()
{
    ListNode *head = create_by_tail();
    int res = 0;
    ListNode *p = head->next;
    while (p)
    {
        res = res * 2 + p->val;
        p = p->next;
    }
    cout << res << endl;
    return 0;
}