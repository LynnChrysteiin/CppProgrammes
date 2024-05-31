/*
使用带头结点的单链表编程：
有两个序列，分别表示两个集合。
求它们的交集并输出。
*/

#include <iostream>
using namespace std;

typedef struct ListNode
{
    int val;
    ListNode *next;
} ListNode;

ListNode *create_by_tail(int len)
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
    return head;
}

ListNode *intersection(ListNode *head1, ListNode *head2)
{
    ListNode *head = new ListNode;
    head->next = NULL;
    ListNode *p1 = head1->next;
    ListNode *tail = head;
    while (p1)
    {
        ListNode *p2 = head2->next;
        while (p2)
        {
            if (p1->val == p2->val)
            {
                ListNode *p = new ListNode;
                p->val = p1->val;
                p->next = NULL;
                tail->next = p;
                tail = p;
                break;
            }
            p2 = p2->next;
        }
        p1 = p1->next;
    }
    return head;
}

void print_linkedList(ListNode *head)
{
    cout << "head";
    while (head->next)
    {
        cout << "-->" << head->next->val;
        head = head->next;
    }
    cout << "-->tail" << endl;
}

int main()
{
    int len1, len2;
    cin >> len1;
    ListNode *head1 = create_by_tail(len1);
    cin >> len2;
    ListNode *head2 = create_by_tail(len2);
    ListNode *head = intersection(head1, head2);
    print_linkedList(head);
    return 0;
}