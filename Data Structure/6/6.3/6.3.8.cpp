/*
 * �� n �����У�����һЩ�˴���������һЩû��������������� a ����� b ֱ���������ҳ��� b ����� c ֱ����������ô���� a ����� c ���������
 * ʡ�� ��һ����У�����ֱ�ӻ������������ڲ�������û�������ĳ��С�
 * ����һ�� n x n �ľ��� isConnected ������ isConnected[i][j] = 1 ��ʾ�� i �����к͵� j ������ֱ���������� isConnected[i][j] = 0 ��ʾ���߲�ֱ��������
 * ���ؾ����� ʡ�� ��������
 */

#include <iostream>
#include <vector>
#include <queue>

class Solution
{
public:
    int countProvinces(const std::vector<std::vector<int>> &isConnected)
    {
        // ����ͨ��������
        int n = isConnected.size();
        std::vector<bool> visited(n, false);
        int ans = 0;
        // BFS
        std::queue<int> Q;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                ans++;
                Q.push(i);
                while (!Q.empty())
                {
                    int cur = Q.front();
                    Q.pop();
                    visited[cur] = true;
                    for (int j = i + 1; j < n; j++)
                    {
                        if (isConnected[cur][j] && !visited[j])
                            Q.push(j);
                    }
                }
            }
        }
        return ans;
    }
};

int main()
{
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> isConnected(n, std::vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            std::cin >> isConnected[i][j];
    int ans = Solution().countProvinces(isConnected);
    std::cout << ans;
    return 0;
}