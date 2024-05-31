/*
先输入一个数，此数字为“停止数字”。
之后输入一系列数字，遇到“停止数字”时结束输入。
要求使用链表实现，并从小到大排序输出。
*/

#include <iostream>
using namespace std;

typedef struct ListNode
{
    int val;
    ListNode *next;
} ListNode;

ListNode *sortedInsert(ListNode *head, int val)
{
    ListNode *p = head;
    ListNode *q = new ListNode;
    q->val = val;
    q->next = NULL;
    while (p->next != NULL)
    {
        if (val > p->next->val)
            p = p->next;
        else
        {
            q->next = p->next;
            p->next = q;
            return head;
        }
    }
    p->next = q;
    return head;
}

int main()
{
    int stop;
    cin >> stop;
    ListNode *head = new ListNode;
    head->next = NULL;
    int val;
    while (cin >> val)
    {
        if (val == stop)
            break;
        head = sortedInsert(head, val);
    }
    ListNode *p = head->next;
    while (p != NULL)
    {
        cout << p->val << endl;
        p = p->next;
    }
    return 0;
}