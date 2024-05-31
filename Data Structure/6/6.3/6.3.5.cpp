/*
 * 给你一个正整数 n ，它表示一个 有向无环图 中节点的数目，节点编号为 0 到 n - 1 （包括两者）。
 * 给你一个二维整数数组 edges ，其中 edges[i] = [fromi, toi] 表示图中一条从 fromi 到 toi 的单向边。
 * 请你返回一个数组 answer，其中 answer[i]是第 i 个节点的所有 祖先 ，这些祖先节点 升序 排序。
 * 如果 u 通过一系列边，能够到达 v ，那么我们称节点 u 是节点 v 的 祖先 节点。
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges)
    {
        vector<unordered_set<int>> anc(n);
        vector<vector<int>> e(n);
        vector<int> indeg(n);
        for (const auto &edge : edges)
        {
            e[edge[0]].push_back(edge[1]);
            ++indeg[edge[1]];
        }
        queue<int> q;
        for (int i = 0; i < n; ++i)
        {
            if (!indeg[i])
            {
                q.push(i);
            }
        }
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int v : e[u])
            {
                anc[v].insert(u);
                for (int i : anc[u])
                {
                    anc[v].insert(i);
                }
                --indeg[v];
                if (!indeg[v])
                {
                    q.push(v);
                }
            }
        }
        vector<vector<int>> res(n);
        for (int i = 0; i < n; ++i)
        {
            for (int j : anc[i])
            {
                res[i].push_back(j);
            }
            sort(res[i].begin(), res[i].end());
        }
        return res;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(m);
    for (int i = 0; i < m; i++)
    {
        int from, to;
        cin >> from >> to;
        edges[i] = {from, to};
    }
    auto answer = Solution().getAncestors(n, edges);
    for (int i = 0; i < answer.size(); i++)
    {
        if (answer[i].size() == 0)
            std::cout << "-1";
        for (int j = 0; j < answer[i].size(); j++)
        {
            std::cout << answer[i][j];
            if (j != answer[i].size() - 1)
                std::cout << " ";
        }
        if (i != answer.size() - 1)
            std::cout << std::endl;
    }
    return 0;
}