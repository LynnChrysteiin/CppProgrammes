/*
 * 有 n 个城市，其中一些彼此相连，另一些没有相连。如果城市 a 与城市 b 直接相连，且城市 b 与城市 c 直接相连，那么城市 a 与城市 c 间接相连。
 * 省份 是一组城市，它们直接或间接相连，组内不含其他没有相连的城市。
 * 给你一个 n x n 的矩阵 isConnected ，其中 isConnected[i][j] = 1 表示第 i 个城市和第 j 个城市直接相连，而 isConnected[i][j] = 0 表示二者不直接相连。
 * 返回矩阵中 省份 的数量。
 */

#include <iostream>
#include <vector>
#include <queue>

class Solution
{
public:
    int countProvinces(const std::vector<std::vector<int>> &isConnected)
    {
        // 求连通分量个数
        int n = isConnected.size();
        std::vector<bool> visited(n, false);
        int ans = 0;
        // BFS
        std::queue<int> Q;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                ans++;
                Q.push(i);
                while (!Q.empty())
                {
                    int cur = Q.front();
                    Q.pop();
                    visited[cur] = true;
                    for (int j = i + 1; j < n; j++)
                    {
                        if (isConnected[cur][j] && !visited[j])
                            Q.push(j);
                    }
                }
            }
        }
        return ans;
    }
};

int main()
{
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> isConnected(n, std::vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            std::cin >> isConnected[i][j];
    int ans = Solution().countProvinces(isConnected);
    std::cout << ans;
    return 0;
}