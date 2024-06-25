/*
 * ���鼯
 * 1. ��ʼ����ÿ��Ԫ���Գ�һ������
 * 2. �ϲ���������Ԫ�����ڵļ��Ϻϲ�Ϊһ������
 * 3. ���ң�����Ԫ�����ڵļ���
 * 4. ·��ѹ�����ڲ��ҵĹ����У���·���ϵ����нڵ㶼ֱ��ָ����ڵ�
 * 5. ���Ⱥϲ������Ƚ�С�ļ��Ϻϲ����Ƚϴ�ļ�����
 * 6. ʱ�临�Ӷȣ�O(��(n))������ ��(n) Ϊ�����������ķ�����, �������仺��, �� n��10^600 ʱ����(n)��4
 * 7. �ռ临�Ӷȣ�O(n)
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
    void Union(int x, int y) // ���Ⱥϲ�, С�ĺϲ������
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
    int Find(int x) // ·��ѹ��
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