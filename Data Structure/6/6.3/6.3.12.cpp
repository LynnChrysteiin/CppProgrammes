/*
 * ����һ������������� n ��·����ɣ�·�ڱ��Ϊ 0 �� n - 1 ��ĳЩ·��֮���� ˫�� ��·��
 * ���뱣֤����Դ�����·�ڳ���������������·�ڣ�����������·��֮�������һ��·��
 * ����һ������ n �Ͷ�ά�������� roads ������ roads[i] = [ui, vi, timei] ��ʾ��·�� ui �� vi ֮����һ����Ҫ���� timei ʱ�����ͨ���ĵ�·��
 * ����֪������ ����ʱ�� ��·�� 0 ��������·�� n - 1 �ķ�������
 * �뷵�ػ�������ʱ�䵽��Ŀ�ĵص�·����Ŀ��
 * ���ڴ𰸿��ܴܺ󣬽������ 10^9 + 7 ȡ�� �󷵻ء�
 */

#include <iostream>
#include <vector>

class Solution
{
public:
    int countCheapestPaths(int nVertex, const std::vector<std::vector<int>> &roads)
    {
        const int INF = 0x3f3f3f3f;
        const int MOD = 1e9 + 7;
        std::vector<std::vector<int>> graph(nVertex, std::vector<int>(nVertex, INF));
        for (const auto &road : roads)
        {
            graph[road[0]][road[1]] = road[2];
            graph[road[1]][road[0]] = road[2];
        }
        std::vector<int> dist(nVertex, INF);
        std::vector<int> path(nVertex, 0);
        std::vector<bool> visited(nVertex, false);
        dist[0] = 0;
        path[0] = 1;
        for (int i = 0; i < nVertex; i++)
        {
            int u = -1;
            for (int j = 0; j < nVertex; j++)
            {
                if (!visited[j] && (u == -1 || dist[j] < dist[u]))
                    u = j;
            }
            visited[u] = true;
            for (int v = 0; v < nVertex; v++)
            {
                if (graph[u][v] != INF)
                {
                    if (dist[u] + graph[u][v] < dist[v])
                    {
                        dist[v] = dist[u] + graph[u][v];
                        path[v] = path[u];
                    }
                    else if (dist[u] + graph[u][v] == dist[v])
                    {
                        path[v] = (path[v] + path[u]) % MOD;
                    }
                }
            }
        }
        return path[nVertex - 1];
    }
};

int main()
{
    int nVertex, nEdge;
    scanf("%d %d", &nVertex, &nEdge);
    std::vector<std::vector<int>> roads(nEdge, std::vector<int>(3));
    for (int i = 0; i < nEdge; i++)
        scanf("%d %d %d", &roads[i][0], &roads[i][1], &roads[i][2]);
    printf("%d", Solution().countCheapestPaths(nVertex, roads));
    return 0;
}