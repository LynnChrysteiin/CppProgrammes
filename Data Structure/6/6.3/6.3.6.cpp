/*
 * �����Կ�����һ����ͨ�� �޻� �� ���� ͼ��
 * ������һ�� n ���ڵ� (�ڵ�ֵΪ 1��n) ���������һ���ߺ��ͼ��
 * ��ӵıߵ�������������� 1 �� n �м䣬���������ӵı߲����������Ѵ��ڵıߡ�
 * ͼ����Ϣ��¼�ڳ���Ϊ n �Ķ�ά���� edges ��edges[i] = [ai, bi] ��ʾͼ���� ai �� bi ֮�����һ���ߡ�
 * ���ҳ�һ������ɾȥ�ıߣ�ɾ�����ʹ��ʣ�ಿ����һ������ n ���ڵ������
 * ����ж���𰸣��򷵻����� edges �������ֵıߡ�
 */

#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<int> findRedundantConnection(std::vector<std::vector<int>> &edges)
    {
        std::vector<int> parent(edges.size() + 1);
        for (int i = 1; i < parent.size(); i++)
        {
            parent[i] = i;
        }
        for (auto &edge : edges)
        {
            int root1 = find(parent, edge[0]);
            int root2 = find(parent, edge[1]);
            if (root1 == root2)
            {
                return edge;
            }
            parent[root1] = root2;
        }
        return {};
    }
    int find(std::vector<int> &parent, int index)
    {
        if (parent[index] != index)
        {
            parent[index] = find(parent, parent[index]);
        }
        return parent[index];
    }
};

int main()
{
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> edges(n);
    for (int i = 0; i < n; i++)
    {
        edges[i].resize(2);
        std::cin >> edges[i][0] >> edges[i][1];
    }
    auto ans = Solution().findRedundantConnection(edges);
    std::cout << ans[0] << " " << ans[1];
    return 0;
}