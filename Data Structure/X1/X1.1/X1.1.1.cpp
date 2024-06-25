/*
 * 并查集
 * 1. 初始化：每个元素自成一个集合
 * 2. 合并：将两个元素所在的集合合并为一个集合
 * 3. 查找：查找元素所在的集合
 * 4. 路径压缩：在查找的过程中，将路径上的所有节点都直接指向根节点
 * 5. 按秩合并：将秩较小的集合合并到秩较大的集合中
 * 6. 时间复杂度：O(α(n))，其中 α(n) 为阿克曼函数的反函数, 增长极其缓慢, 当 n≤10^600 时，α(n)≤4
 * 7. 空间复杂度：O(n)
 */

#include <cstdio>

const int MAX_N = 100;

typedef struct
{
    int size;
    int parent[MAX_N];
    int rank[MAX_N];

    void Init(int n)
    {
        size = n;
        for (int i = 0; i < size; i++)
        {
            parent[i] = -1;
            rank[i] = 0;
        }
    }
    void Union(int x, int y) // 按秩合并, 小的合并到大的
    {
        if (x == y)
            return;
        if (rank[x] > rank[y])
        {
            parent[y] = x;
            rank[x] += rank[y];
        }
        else
        {
            parent[x] = y;
            rank[y] += rank[x];
        }
    }
    int Find(int x) // 路径压缩
    {
        int root = x;
        while (parent[root] != -1)
            root = parent[root];
        while (x != root)
        {
            int tmp = parent[x];
            parent[x] = root;
            x = tmp;
        }
        return root;
    }
} UnionFind;

int main()
{
    UnionFind uf;
    uf.Init(10);
    uf.Union(0, 1);
    uf.Union(2, 3);
    uf.Union(4, 5);
    uf.Union(6, 7);
    uf.Union(8, 9);
    uf.Union(1, 5);
    uf.Union(3, 7);
    for (int i = 0; i < 10; i++)
        printf("%d -> %d \n", i, uf.Find(i));
    return 0;
}