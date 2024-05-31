/*
给你链表的头指针 head 和一个整数 k 。
交换 链表正数第 k 个节点和倒数第 k 个节点的值后，输出该链表（链表的下标 从 1 开始索引）。
*/

#include <iostream>
using namespace std;

typedef struct ListNode
{
    int val;
    ListNode *next;
} ListNode;

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

void swapNodes(ListNode *head, int k, int len)
{
    ListNode *p = head;
    for (int i = 0; i < k - 1; i++)
        p = p->next;
    ListNode *q = head;
    for (int i = 0; i < len - k; i++)
        q = q->next;
    int temp = p->val;
    p->val = q->val;
    q->val = temp;
}

int main()
{
    int len, k;
    cin >> len;
    ListNode *head = createByTail(len);
    cin >> k;
    swapNodes(head, k, len);
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