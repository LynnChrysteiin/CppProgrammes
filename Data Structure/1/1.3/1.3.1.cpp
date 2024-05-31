/*
给定链表头结点 head，该链表上的每个结点都有一个唯一的整型值 。
同时给定列表 G，该列表是上述链表中整型值的一个子集。
返回列表 G 中组件的个数，这里对组件的定义为：链表中一段极长连续结点的值（该值必须在列表 G 中）构成的集合。
极长的含义是：这段连续结点的前面或后面结点不属于G。
*/

#include <iostream>
#include <vector>
#include <algorithm>
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
    int numComponents(ListNode *head, vector<int> &G)
    {
        ListNode *p = head;
        int res = 0;
        while (p)
        {
            if (find(G.begin(), G.end(), p->val) != G.end() && (!p->next || find(G.begin(), G.end(), p->next->val) == G.end()))
                res++;
            p = p->next;
        }
        return res;
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
    vector<int> G;
    int m, data, res;
    ListNode *head = createByTail();
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> data;
        G.push_back(data);
    }
    res = Solution().numComponents(head, G);
    cout << res << endl;
    return 0;
}
