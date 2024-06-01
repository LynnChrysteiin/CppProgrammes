/*
 * 你在一个城市里，城市由 n 个路口组成，路口编号为 0 到 n - 1 ，某些路口之间有 双向 道路。
 * 输入保证你可以从任意路口出发到达其他任意路口，且任意两个路口之间最多有一条路。
 * 给你一个整数 n 和二维整数数组 roads ，其中 roads[i] = [ui, vi, timei] 表示在路口 ui 和 vi 之间有一条需要花费 timei 时间才能通过的道路。
 * 你想知道花费 最少时间 从路口 0 出发到达路口 n - 1 的方案数。
 * 请返回花费最少时间到达目的地的路径数目。
 * 由于答案可能很大，将结果对 10^9 + 7 取余 后返回。
 */

#include <iostream>
#include <vector>

class Solution
{
public:
    int countCheapestPaths(int nVertex, const std::vector<std::vector<int>> &roads)
    {
        const int INF = 0x3f3f3f3f;
        const int MOD = 1e9 + 7;
        std::vector<std::vector<int>> graph(nVertex, std::vector<int>(nVertex, INF));
        for (const auto &road : roads)
        {
            graph[road[0]][road[1]] = road[2];
            graph[road[1]][road[0]] = road[2];
        }
        std::vector<int> dist(nVertex, INF);
        std::vector<int> path(nVertex, 0);
        std::vector<bool> visited(nVertex, false);
        dist[0] = 0;
        path[0] = 1;
        for (int i = 0; i < nVertex; i++)
        {
            int u = -1;
            for (int j = 0; j < nVertex; j++)
            {
                if (!visited[j] && (u == -1 || dist[j] < dist[u]))
                    u = j;
            }
            visited[u] = true;
            for (int v = 0; v < nVertex; v++)
            {
                if (graph[u][v] != INF)
                {
                    if (dist[u] + graph[u][v] < dist[v])
                    {
                        dist[v] = dist[u] + graph[u][v];
                        path[v] = path[u];
                    }
                    else if (dist[u] + graph[u][v] == dist[v])
                    {
                        path[v] = (path[v] + path[u]) % MOD;
                    }
                }
            }
        }
        return path[nVertex - 1];
    }
};

int main()
{
    int nVertex, nEdge;
    scanf("%d %d", &nVertex, &nEdge);
    std::vector<std::vector<int>> roads(nEdge, std::vector<int>(3));
    for (int i = 0; i < nEdge; i++)
        scanf("%d %d %d", &roads[i][0], &roads[i][1], &roads[i][2]);
    printf("%d", Solution().countCheapestPaths(nVertex, roads));
    return 0;
}