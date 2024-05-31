/*
 * 给你一个整数 n ，表示一个国家里的城市数目。城市编号为 0 到 n - 1 。
 * 给你一个二维整数数组 roads ，其中 roads[i] = [ai, bi] 表示城市 ai 和 bi 之间有一条双向道路。
 * 你需要给每个城市安排一个从 1 到 n 之间的整数值，且每个值只能被使用 一次 。
 * 道路的 重要性 定义为这条道路连接的两座城市数值 之和 。
 * 请你返回在最优安排下，所有道路重要性之和最大为多少。
 */

#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    size_t getMaxRoadsImportance(int n, std::vector<std::pair<int, int>> roads)
    {
        if (n == 1)
            return 0;
        std::vector<int> degree(n, 0);
        for (auto &road : roads)
        {
            ++degree[road.first];
            ++degree[road.second];
        }
        std::vector<int> cities(n);
        for (int i = 0; i < n; i++)
            cities[i] = i;
        std::sort(cities.begin(), cities.end(), [&](int a, int b) -> bool
                  { return degree[a] < degree[b]; });
        std::vector<int> city_values(n);
        int i = 1;
        for (auto city : cities)
            city_values[city] = i++;
        size_t res = 0;
        for (int i = 0; i < n; i++)
            res += degree[i] * city_values[i];
        return res;
    }
};

int main()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<std::pair<int, int>> roads(m);
    for (int i = 0; i < m; ++i)
        std::cin >> roads[i].first >> roads[i].second;
    std::cout << Solution().getMaxRoadsImportance(n, roads) << std::endl;
    return 0;
}