/*
给你两个 非空 链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表，输出该链表。
你可以假设除了数字 0 之外，这两个数字都不会以零开头。
*/

#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *head = new ListNode;
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        ListNode *p = head;
        int carry = 0;
        while (p1 || p2)
        {
            int sum = (p1 ? p1->val : 0) + (p2 ? p2->val : 0) + carry;
            carry = sum / 10;
            p->next = new ListNode(sum % 10);
            p = p->next;
            if (p1)
                p1 = p1->next;
            if (p2)
                p2 = p2->next;
        }
        if (carry)
            p->next = new ListNode(carry);
        return head->next;
    }
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
};

int main()
{
    Solution s;
    ListNode *l1 = s.createByTail();
    ListNode *l2 = s.createByTail();
    ListNode *l3 = s.addTwoNumbers(s.reverseList(l1), s.reverseList(l2));
    ListNode *p = s.reverseList(l3);
    cout << "head-->";
    while (p)
    {
        cout << p->val << "-->";
        p = p->next;
    }
    cout << "tail" << endl;
    return 0;
}