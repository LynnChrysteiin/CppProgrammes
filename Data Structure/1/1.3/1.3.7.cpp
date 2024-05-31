/*
用单链表解决约瑟夫问题。
约瑟夫问题为：n个人围成一圈，从第一个人开始报数1, 2, …, m，数到m的人出圈，
然后从出圈的下一个人(m+1)开始重复此过程，直到全部人出圈，于是得到一个出圈序列，
如当n=8，m=4时，则得到的出圈序列为4, 8, 5, 2, 1, 3, 7, 6。
*/

#include <iostream>
#include <vector>
using namespace std;

typedef struct ListNode
{
    int val;
    ListNode *next;
} ListNode;

ListNode *addByTail(ListNode *head, int val)
{
    ListNode *newNode = new ListNode;
    newNode->val = val;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
        head->next = head;
    }
    else
    {
        ListNode *p = head;
        while (p->next != head)
        {
            p = p->next;
        }
        p->next = newNode;
        newNode->next = head;
    }
    return head;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> res;
    ListNode *head = NULL;
    for (int i = 0; i < n; i++)
        head = addByTail(head, i + 1);
    ListNode *p = head;
    while (p->next != p)
    {
        for (int i = 1; i < m - 1; i++)
            p = p->next;
        ListNode *q = p->next;
        p->next = q->next;
        res.push_back(q->val);
        delete q;
        p = p->next;
    }
    res.push_back(p->val);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i];
        if (i != res.size() - 1)
            cout << " ";
    }
    return 0;
}