/*
给你一个无头结点的单链表的头指针 head。链表中每个结点的值是16进制数的一位，但是顺序为倒置的，即最低位在第一个结点，最高位在最后一个结点。
请你返回该链表所表示数字的十进制值。

示例：
输入链表：2->3->A->1
输出：因为对应的16进制数字为1A32，所以返回6706
说明：16进制的数码为0-9，ABCDEF（本题只使用大写字母），且转换得到的10进制数字不超出32位int型数的表示范围。
*/

#include <iostream>
#include <math.h>
using namespace std;

struct ListNode
{
    char val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(char x) : val(x), next(NULL) {}
    ListNode(char x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    int getDecimalValue(ListNode *head)
    {
        int res = 0;
        int i = 0;
        while (head)
        {
            res += pow(16, i++) * (head->val >= 'A' ? head->val - 'A' + 10 : head->val - '0');
            head = head->next;
        }
        return res;
    }
};

ListNode *createByTail()
{
    ListNode *head;
    ListNode *p1, *p2;
    int n = 0;
    char num;
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
    int n;
    n = Solution().getDecimalValue(head);
    cout << n << endl;
    return 0;
}
