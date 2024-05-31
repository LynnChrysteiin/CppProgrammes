/*
 * 有一组 n 个人作为实验对象，从 0 到 n - 1 编号，其中每个人都有不同数目的钱，以及不同程度的安静值（quietness）。
 * 为了方便起见，我们将编号为 x 的人简称为 "person x "。
 * 给你一个数组 richer ，其中 richer[i] = [ai, bi] 表示 person ai 比 person bi 更有钱。
 * 另给你一个整数数组 quiet ，其中 quiet[i] 是 person i 的安静值。
 * richer 中所给出的数据 逻辑自洽（也就是说，在 person x 比 person y 更有钱的同时，不会出现 person y 比 person x 更有钱的情况 ）。
 * 现在，返回一个整数数组 answer 作为答案，其中 answer[x] = y 的前提是，在所有拥有的钱肯定不少于 person x 的人中，person y 是最安静的人（也就是安静值 quiet[y] 最小的人）。
 */

#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<int> getAnswer(std::vector<int> quiet, std::vector<std::pair<int, int>> richer)
    {
        int n = quiet.size();
        std::vector<std::vector<int>> graph(n);
        for (auto i : richer)
            graph[i.second].push_back(i.first);
        std::vector<int> answer(n, -1);
        for (int i = 0; i < n; i++)
            dfs(graph, quiet, answer, i);
        return answer;
    }
    void dfs(std::vector<std::vector<int>> &graph, std::vector<int> &quiet, std::vector<int> &answer, int i)
    {
        if (answer[i] != -1)
            return;
        answer[i] = i;
        for (auto j : graph[i])
        {
            dfs(graph, quiet, answer, j);
            if (quiet[answer[j]] < quiet[answer[i]])
                answer[i] = answer[j];
        }
    }
};

int main()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<int> quiet(n);
    for (int i = 0; i < n; i++)
        std::cin >> quiet[i];
    std::vector<std::pair<int, int>> richer(m);
    for (int i = 0; i < m; i++)
        std::cin >> richer[i].first >> richer[i].second;
    auto answer = Solution().getAnswer(quiet, richer);
    for (int i = 0; i < answer.size(); i++)
    {
        std::cout << answer[i];
        if (i != answer.size() - 1)
            std::cout << " ";
    }
    return 0;
}