/*
 * ����һ������������������ͼ�����ǿ�ѡ���κ�һ���ڵ���Ϊ����
 * ͼ��˿��Գ�Ϊ���������п��ܵ����У�������С�߶ȵ�������Ϊ��С�߶�����
 * ����������һ��ͼ��д��һ�������ҵ����е���С�߶������������ǵĸ��ڵ㡣
 * ��ͼ���� n ���ڵ㣬���Ϊ 0 �� n - 1���������� n ��һ������� edges �б�ÿһ���߶���һ�Ա�ǩ����
 * ����Լ���û���ظ��ı߻������ edges �С�
 * �������еı߶�������ߣ� [0, 1]�� [1, 0] ����ͬ�ģ���˲���ͬʱ������ edges �
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
        std::vector<std::vector<int>> graph(nVertex); // �ڽӱ�
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