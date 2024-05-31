/*
有 n 个人前来排队买票，其中第 0 人站在队伍最前方 ，第 (n - 1) 人站在队伍 最后方 。
给你一个下标从 0 开始的整数数组 tickets ，数组长度为 n ，其中第 i 人想要购买的票数为 tickets[i] 。
每个人买票都需要用掉恰好 1 秒 。
一个人一次只能买一张票 ，如果需要购买更多票，他必须走到队尾 重新排队（瞬间发生，不计时间）。
如果一个人没有剩下需要买的票，那他将会 离开 队伍。

返回位于位置 k（下标从 0 开始）的人完成买票需要的时间（以秒为单位）。
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct buyer
{
    int id;
    int num;
};

class Solution
{
public:
    int buyTicket(vector<int> &tickets, int k)
    {
        int time = 0;
        queue<buyer> Q;
        for (int i = 0; i < tickets.size(); i++)
        {
            buyer temp;
            temp.id = i;
            temp.num = tickets[i];
            Q.push(temp);
        }
        int remnant = tickets[k];
        while (remnant > 0)
        {
            if (Q.front().id == k)
                remnant--;
            if (Q.front().num > 1)
            {
                buyer temp = Q.front();
                temp.num--;
                Q.push(temp);
            }
            Q.pop();
            time++;
        }
        return time;
    }
};

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> tickets;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        tickets.push_back(temp);
    }
    Solution s;
    cout << s.buyTicket(tickets, k) << endl;
    return 0;
}