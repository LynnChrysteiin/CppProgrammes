/*
 * ����һ�� n �ˣ����Ϊ 1, 2, ..., n���� �������ÿ���˷ֽ������С�����顣
 * ÿ���˶����ܲ�ϲ�������ˣ���ô���ǲ�Ӧ������ͬһ�顣
 * �������� n ������ dislikes ������ dislikes[i] = [ai, bi] ����ʾ���������Ϊ ai �� bi ���˹���ͬһ�顣
 * �����������ַ����������˷ֽ�����ʱ������ true�����򷵻� false��
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