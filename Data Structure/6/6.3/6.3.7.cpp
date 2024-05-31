/*
 * ����һ�� �����޻�ͼ �� n ���ڵ���Ϊ 0 �� n-1 ���Լ�һ�������� edges ������ edges[i] = [fromi, toi] ��ʾһ���ӵ�  fromi ���� toi ������ߡ�
 * ��Ҫѡ��һЩ�ڵ㣬����Щ�ڵ�������������ڵ㣬����Ҫ�������нڵ㣬��Ҫ����ѡ�����ٵĳ����ڵ㡣
 * ������С��ʹ�ô���Щ������ܵ���ͼ�����е�ĵ㼯��С�����㼯Ԫ�ص���Ŀ����
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
        // ͳ�����Ϊ 0 �Ķ���ĸ���
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