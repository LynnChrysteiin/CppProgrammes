/*
 * 对于一个具有树特征的无向图，我们可选择任何一个节点作为根。
 * 图因此可以成为树，在所有可能的树中，具有最小高度的树被称为最小高度树。
 * 给出这样的一个图，写出一个函数找到所有的最小高度树并返回他们的根节点。
 * 该图包含 n 个节点，标记为 0 到 n - 1。给定数字 n 和一个无向边 edges 列表（每一个边都是一对标签）。
 * 你可以假设没有重复的边会出现在 edges 中。
 * 由于所有的边都是无向边， [0, 1]和 [1, 0] 是相同的，因此不会同时出现在 edges 里。
 */

#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    std::vector<int> findMinHeightTrees(int nVertex, const std::vector<std::vector<int>> &edges)
    {
        std::vector<int> degree(nVertex, 0);
        std::vector<std::vector<int>> graph(nVertex); // 邻接表
        for (int i = 0; i < edges.size(); i++)
        {
            degree[edges[i][0]]++;
            degree[edges[i][1]]++;
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        std::vector<int> leaves;
        for (int i = 0; i < nVertex; i++)
            if (degree[i] == 1)
                leaves.push_back(i);
        while (nVertex > 2)
        {
            nVertex -= leaves.size();
            std::vector<int> newLeaves;
            for (auto leaf : leaves)
            {
                for (auto neighbor : graph[leaf])
                {
                    degree[neighbor]--;
                    if (degree[neighbor] == 1)
                        newLeaves.push_back(neighbor);
                }
            }
            leaves = newLeaves;
        }
        return leaves;
    }
};

int main()
{
    int n;
    std::vector<std::vector<int>> edges;
    std::cin >> n;
    int p1, p2;
    for (int i = 0; i < n - 1; i++)
    {
        std::cin >> p1 >> p2;
        std::vector<int> edge;
        edge.push_back(p1);
        edge.push_back(p2);
        edges.push_back(edge);
    }
    std::vector<int> res = Solution().findMinHeightTrees(n, edges);
    sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++)
        std::cout << res[i] << " ";
}