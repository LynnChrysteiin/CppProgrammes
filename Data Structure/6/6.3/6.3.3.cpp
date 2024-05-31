/*
 * ����һ������ n ����ʾһ��������ĳ�����Ŀ�����б��Ϊ 0 �� n - 1 ��
 * ����һ����ά�������� roads ������ roads[i] = [ai, bi] ��ʾ���� ai �� bi ֮����һ��˫���·��
 * ����Ҫ��ÿ�����а���һ���� 1 �� n ֮�������ֵ����ÿ��ֵֻ�ܱ�ʹ�� һ�� ��
 * ��·�� ��Ҫ�� ����Ϊ������·���ӵ�����������ֵ ֮�� ��
 * ���㷵�������Ű����£����е�·��Ҫ��֮�����Ϊ���١�
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