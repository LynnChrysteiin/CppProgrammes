/*
 * 给定一个由表示变量之间关系的字符串方程组成的数组，每个字符串方程 equations[i] 的长度为 4，
 * 并采用两种不同的形式之一："a==b" 或 "a!=b"。在这里，a 和 b 是小写字母（不一定不同），表示单字母变量名。
 * 只有当可以将整数分配给变量名，以便满足所有给定的方程时才返回 true，否则返回 false。
 */

#include <iostream>
#include <string>
#include <vector>

class Solution
{
private:
    struct UnionFind // 并查集
    {
        std::vector<int> parent; // parent[i]表示i的父节点
        std::vector<int> rank;   // rank[i]表示i的秩, 即以i为根的树的高度

        UnionFind(int n) : parent(n), rank(n, 1)
        {
            for (int i = 0; i < n; i++)
                parent[i] = i;
        }
        int find(int x)
        {
            if (x != parent[x])
                parent[x] = find(parent[x]); // 路径压缩
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
