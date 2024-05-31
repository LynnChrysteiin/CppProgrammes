/*
给定一个无头结点的非空单链表，头指针为 head，请返回链表的中间结点的值。
如果有两个中间结点，则返回第二个中间结点。

示例 1：
输入：[1,2,3,4,5]
输出：3

示例 2：
输入：[1,2,3,4,5,6]
输出： 4

由于该列表有两个中间结点，值分别为 3 和 4，我们返回第二个结点。
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
    int middleNode(ListNode *head)  // 快慢指针法
    {
        ListNode *sp = head;
        ListNode *fp = head;
        while (fp != NULL && fp->next != NULL)
        {
            sp = sp->next;
            fp = fp->next->next;
        }
        return sp->val;
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

int main()
{
    ListNode *head = createByTail();
    int result = Solution().middleNode(head);
    cout << result << endl;
    return 0;
}