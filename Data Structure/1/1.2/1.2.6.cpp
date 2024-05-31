/*
使用带头结点的单链表编程：
一群学生排成一行，输入一个位置，将该位置的学生移除。
第一个学生的位置为1，第n个学生的位置为n。
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

void pop_this(ListNode *head, int pos)
{
    ListNode *p = head;
    for (int i = 0; i < pos; ++i)
        p = p-> next;
    ListNode *q = p->next;
    p->next = q->next;
    delete q;
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
    int len;
    cin >> len;
    ListNode *head = create_by_tail(len);
    int pos, val;
    while (cin >> pos)
    {
        if (pos < 1 || pos > len)
            cout << "invalid" << endl;
        else
        {
            pop_this(head, pos - 1);
            len--;
            print_linkedList(head);
        }
    }
    return 0;
}