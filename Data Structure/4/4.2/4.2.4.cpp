/*
学校的自助午餐提供圆形和方形的三明治，分别用数字 0 和 1 表示。
所有学生站在一个队列里，每个学生要么喜欢圆形的要么喜欢方形的。

餐厅里三明治的数量与学生的数量相同。所有三明治都放在一个 栈 里，每一轮：
如果队列最前面的学生 喜欢 栈顶的三明治，那么会 拿走它 并离开队列。
否则，这名学生会 放弃这个三明治 并回到队列的尾部。
这个过程会一直持续到队列里所有学生都不喜欢栈顶的三明治为止。

给你两个整数数组 students 和 sandwiches ，
其中 sandwiches[i] 是栈里面第 i 个三明治的类型（i = 0 是栈的顶部），
students[j] 是初始队列里第 j 名学生对三明治的喜好（j = 0 是队列的最开始位置）。

请你返回无法吃午餐的学生数量。
*/

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Solution
{
public:
    int countStudents(vector<int> &vstu, vector<int> &vsan, int n)
    {
        stack<int> san;
        queue<int> stu;
        for (int i = 0; i < n; ++i)
            stu.push(vstu[i]);
        for (int i = n - 1; i >= 0; --i)
            san.push(vsan[i]);
        int count = 0;
        while (!stu.empty() && count < stu.size())
        {
            if (stu.front() == san.top())
            {
                stu.pop();
                san.pop();
                count = 0;
            }
            else
            {
                int temp = stu.front();
                stu.pop();
                stu.push(temp);
                count++;
            }
        }
        return stu.size();
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> students(n), sandwiches(n);
    for (int i = 0; i < n; i++)
        cin >> students[i];
    for (int i = 0; i < n; i++)
        cin >> sandwiches[i];
    Solution S;
    cout << S.countStudents(students, sandwiches, n);
    return 0;
}