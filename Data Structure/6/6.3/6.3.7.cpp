/*
 * 给你一个 有向无环图 ， n 个节点编号为 0 到 n-1 ，以及一个边数组 edges ，其中 edges[i] = [fromi, toi] 表示一条从点  fromi 到点 toi 的有向边。
 * 你要选择一些节点，从这些节点出发到达其它节点，现需要到达所有节点，但要尽量选择最少的出发节点。
 * 返回最小的使得从这些点出发能到达图中所有点的点集大小（即点集元素的数目）。
 */

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

class Solution
{
public:
    int countFewestEntry(int n, std::vector<std::vector<int>> &edges)
    {
        // 统计入度为 0 的顶点的个数
        std::unordered_map<int, int> indegree;
        for (const auto &edge : edges)
            ++indegree[edge[1]];
        int ans = 0;
        for (int i = 0; i < n; i++)
            if (!indegree.count(i))
                ++ans;
        return ans;
    }
};

int main()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> edges(m, std::vector<int>(2));
    for (int i = 0; i < m; i++)
        std::cin >> edges[i][0] >> edges[i][1];
    int ans = Solution().countFewestEntry(n, edges);
    std::cout << ans;
    return 0;
}