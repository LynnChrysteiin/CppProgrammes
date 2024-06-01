/*
 * ����һ���ɱ�ʾ����֮���ϵ���ַ���������ɵ����飬ÿ���ַ������� equations[i] �ĳ���Ϊ 4��
 * ���������ֲ�ͬ����ʽ֮һ��"a==b" �� "a!=b"�������a �� b ��Сд��ĸ����һ����ͬ������ʾ����ĸ��������
 * ֻ�е����Խ�������������������Ա��������и����ķ���ʱ�ŷ��� true�����򷵻� false��
 */

#include <iostream>
#include <string>
#include <vector>

class Solution
{
private:
    struct UnionFind // ���鼯
    {
        std::vector<int> parent; // parent[i]��ʾi�ĸ��ڵ�
        std::vector<int> rank;   // rank[i]��ʾi����, ����iΪ�������ĸ߶�

        UnionFind(int n) : parent(n), rank(n, 1)
        {
            for (int i = 0; i < n; i++)
                parent[i] = i;
        }
        int find(int x)
        {
            if (x != parent[x])
                parent[x] = find(parent[x]); // ·��ѹ��
            return parent[x];
        }
        void unite(int x, int y)
        {
            int rootx = find(x);
            int rooty = find(y);
            if (rootx != rooty)
            {
                if (rank[rootx] < rank[rooty])
                    std::swap(rootx, rooty);
                parent[rooty] = rootx;
                if (rank[rootx] == rank[rooty])
                    rank[rootx]++;
            }
        }
    };

public:
    bool equationsPossible(std::vector<std::string> equations)
    {
        int n = equations.size();
        UnionFind uf(26);
        for (int i = 0; i < n; i++)
        {
            if (equations[i][1] == '=')
            {
                int x = equations[i][0] - 'a';
                int y = equations[i][3] - 'a';
                if (x != y)
                    uf.unite(x, y);
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (equations[i][1] == '!')
            {
                int x = equations[i][0] - 'a';
                int y = equations[i][3] - 'a';
                if (uf.find(x) == uf.find(y))
                    return false;
            }
        }
        return true;
    }
};

int main()
{
    int n;
    std::cin >> n;
    std::vector<std::string> equations(n, "");
    for (int i = 0; i < n; i++)
        std::cin >> equations[i];
    std::cout << (Solution().equationsPossible(equations) ? "true" : "false");
}
