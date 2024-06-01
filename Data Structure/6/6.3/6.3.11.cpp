/*
 * 有 n 个城市通过一些航班连接。
 * 给你一个数组 flights ，其中 flights[i] = [fromi, toi, pricei] ，表示该航班从城市 fromi 开始，以价格 pricei 抵达 toi。
 * 现在给定所有的城市和航班，以及出发城市 src 和目的地 dst，
 * 你的任务是找到一条最多经过 k 站中转的路线，使得从 src 到 dst 的 价格最便宜 ，并返回该价格。
 * 如果不存在这样的路线，则输出 -1。
 */

#include <iostream>
#include <vector>

class Solution
{
public:
    int findCheapestPrice(int nCity, const std::vector<std::vector<int>> &flights, int src, int dst, int k)
    {
        // 动态规划
        const int INF = 0x3f3f3f3f;
        std::vector<std::vector<int>> dp(k + 2, std::vector<int>(nCity, INF));
        dp[0][src] = 0;
        for (int i = 1; i <= k + 1; i++)
        {
            for (const auto &flight : flights)
            {
                int from = flight[0], to = flight[1], price = flight[2];
                dp[i][to] = std::min(dp[i][to], dp[i - 1][from] + price); // 状态转移方程
            }
        }
        int ans = INF;
        for (int i = 1; i <= k + 1; i++)
            ans = std::min(ans, dp[i][dst]);
        return ans == INF ? -1 : ans;
    }
};

int main()
{
    int nCity, nFlight, src, dst, k;
    std::cin >> nCity >> nFlight;
    std::vector<std::vector<int>> flights(nFlight, std::vector<int>(3));
    for (int i = 0; i < nFlight; i++)
        std::cin >> flights[i][0] >> flights[i][1] >> flights[i][2];
    std::cin >> src >> dst >> k;
    std::cout << Solution().findCheapestPrice(nCity, flights, src, dst, k);
    return 0;
}