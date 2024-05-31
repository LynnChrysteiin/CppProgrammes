/*
给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

示例 1:
给定链表 1->2->3->4, 重新排列为 1->4->2->3.
示例 2:
给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.

*/

#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    void reorderList(ListNode *head)
    {
        if (head == NULL) return;
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast->next != NULL && fast->next->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *head1 = slow->next;
        slow->next = NULL;
        ListNode *head2 = reverseList(head1);
        mergeList(head, head2);
    }

private:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *thisNode = head;
        ListNode *preNode = NULL;
        ListNode *nextNode = NULL;
        while (thisNode)
        {
            nextNode = thisNode->next;
            thisNode->next = preNode;
            preNode = thisNode;
            thisNode = nextNode;
        }
        return preNode;
    }
    void mergeList(ListNode *l1, ListNode *l2)
    {
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        while (p1 && p2)
        {
            ListNode *tmp1 = p1->next;
            ListNode *tmp2 = p2->next;
            p1->next = p2;
            p2->next = tmp1;
            p1 = tmp1;
            p2 = tmp2;
        }
    }
};
ListNode *createByTail()
{
    ListNode *head;
    ListNode *p1, *p2;
    int n = 0, num;
    int len;
    cin >> len;
    head = NULL;
    while (n < len && cin >> num)
    {
        p1 = new ListNode(num);
        n = n + 1;
        if (n == 1)
            head = p1;
        else
            p2->next = p1;
        p2 = p1;
    }
    return head;
}

void displayLink(ListNode *head)
{
    ListNode *p;
    p = head;
    cout << "head-->";
    while (p != NULL)
    {
        cout << p->val << "-->";
        p = p->next;
    }
    cout << "tail\n";
}
int main()
{
    ListNode *head = createByTail();
    Solution().reorderList(head);
    displayLink(head);
    return 0;
}