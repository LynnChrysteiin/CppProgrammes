/*
 * 给定一组 n 人（编号为 1, 2, ..., n）， 我们想把每个人分进任意大小的两组。
 * 每个人都可能不喜欢其他人，那么他们不应该属于同一组。
 * 给定整数 n 和数组 dislikes ，其中 dislikes[i] = [ai, bi] ，表示不允许将编号为 ai 和 bi 的人归入同一组。
 * 当可以用这种方法将所有人分进两组时，返回 true；否则返回 false。
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <functional>

class Solution
{
public:
    bool possibleBipartition(int n, std::vector<std::vector<int>> &dislikes)
    {
        std::unordered_map<int, std::vector<int>> g;
        for (auto &e : dislikes)
        {
            int a = e[0] - 1, b = e[1] - 1;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        std::vector<int> color(n);
        std::function<bool(int, int)> dfs = [&](int i, int c) -> bool
        {
            color[i] = c;
            for (int j : g[i])
            {
                if (!color[j] && !dfs(j, 3 - c))
                    return false;
                if (color[j] == c)
                    return false;
            }
            return true;
        };
        for (int i = 0; i < n; ++i)
        {
            if (!color[i] && !dfs(i, 1))
                return false;
        }
        return true;
    }
};

int main()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> dislikes(m, std::vector<int>(2));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < 2; j++)
            std::cin >> dislikes[i][j];
    std::cout << (Solution().possibleBipartition(n, dislikes) ? "true" : "false");
    return 0;
}