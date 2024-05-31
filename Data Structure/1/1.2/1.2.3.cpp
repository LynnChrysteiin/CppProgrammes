/*
使用带头结点的单链表编程：
一群学生排成一行，输入一个位置和一个学号，在该位置插入一个学生。
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

void insert_after(ListNode *head, int pos, int val)
{
    ListNode *p = head;
    for (int i = 0; i < pos; ++i)
        p = p->next;
    ListNode *thisNode = new ListNode;
    thisNode->val = val;
    thisNode->next = p->next;
    p->next = thisNode;
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
    while (cin >> pos >> val)
    {
        if (pos < 1 || pos > len + 1)
            cout << "invalid" << endl;
        else
        {
            insert_after(head, pos - 1, val);
            ++len;
            print_linkedList(head);
        }
    }
    return 0;
}