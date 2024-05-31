/*
 * ����һ�������� n ������ʾһ�� �����޻�ͼ �нڵ����Ŀ���ڵ���Ϊ 0 �� n - 1 ���������ߣ���
 * ����һ����ά�������� edges ������ edges[i] = [fromi, toi] ��ʾͼ��һ���� fromi �� toi �ĵ���ߡ�
 * ���㷵��һ������ answer������ answer[i]�ǵ� i ���ڵ������ ���� ����Щ���Ƚڵ� ���� ����
 * ��� u ͨ��һϵ�бߣ��ܹ����� v ����ô���ǳƽڵ� u �ǽڵ� v �� ���� �ڵ㡣
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