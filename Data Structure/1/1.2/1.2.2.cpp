/*
使用带头结点的单链表编程：
有两个有序序列，分别表示两个集合。
求它们的交集并输出。
注意：这里要利用到“有序”的特性。
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
    ListNode *head1 = create_by_tail();
    ListNode *head2 = create_by_tail();
    ListNode *p1 = head1->next;
    ListNode *p2 = head2->next;
    cout << "head";
    while (p1 && p2)
    {
        if (p1->val == p2->val)
        {
            cout << "-->" << p1->val;
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->val < p2->val)
        {
            p1 = p1->next;
        }
        else
        {
            p2 = p2->next;
        }
    }
    cout << "-->tail";
    return 0;
}