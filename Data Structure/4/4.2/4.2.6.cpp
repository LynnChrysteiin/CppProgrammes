/*
写一个 RecentCounter 类来计算特定时间范围内最近的请求。
请你实现 RecentCounter 类并实现main函数，读入测试数据中的指令，调用RecentCounter类中的相应操作以获得结果。

RecentCounter 类至少包含以下操作：
RecentCounter() ：
    构造函数，初始化计数器，请求数为 0 。
int ping(int t)：
    在时间 t 添加一个新请求，其中 t 表示以毫秒为单位的某个时间，
    并返回过去 3000 毫秒内发生的所有请求数（包括新请求）。确切地说，返回在 [t-3000, t] 内发生的请求数。

保证每次对 ping 的调用都使用比之前更大的 t 值。
*/

#include <iostream>
#include <queue>
using namespace std;

class RecentCounter
{
private:
    queue<int> requests;

public:
    RecentCounter()
    {
        while (!requests.empty())
            requests.pop();
    }
    int Ping(int t)
    {
        requests.push(t);
        while (requests.front() < t - 3000)
            requests.pop();
        return requests.size();
    }
};

class Solution
{
public:
    void solve(int *t, int n)
    {
        if (n == 0)
        {
            cout << 0;
            return;
        }
        RecentCounter rc;
        for (int i = 0; i < n; i++)
        {
            cout << rc.Ping(t[i]);
            if (i != n - 1)
                cout << endl;
        }
    }
};

int main()
{
    int n;
    cin >> n;
    int *t = new int[n];
    for (int i = 0; i < n; i++)
        cin >> t[i];
    Solution s;
    s.solve(t, n);
}