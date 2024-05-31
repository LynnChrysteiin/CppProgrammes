/*
 * ��һ�� n ������Ϊʵ����󣬴� 0 �� n - 1 ��ţ�����ÿ���˶��в�ͬ��Ŀ��Ǯ���Լ���ͬ�̶ȵİ���ֵ��quietness����
 * Ϊ�˷�����������ǽ����Ϊ x ���˼��Ϊ "person x "��
 * ����һ������ richer ������ richer[i] = [ai, bi] ��ʾ person ai �� person bi ����Ǯ��
 * �����һ���������� quiet ������ quiet[i] �� person i �İ���ֵ��
 * richer �������������� �߼���Ǣ��Ҳ����˵���� person x �� person y ����Ǯ��ͬʱ��������� person y �� person x ����Ǯ����� ����
 * ���ڣ�����һ���������� answer ��Ϊ�𰸣����� answer[x] = y ��ǰ���ǣ�������ӵ�е�Ǯ�϶������� person x �����У�person y ��������ˣ�Ҳ���ǰ���ֵ quiet[y] ��С���ˣ���
 */

#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<int> getAnswer(std::vector<int> quiet, std::vector<std::pair<int, int>> richer)
    {
        int n = quiet.size();
        std::vector<std::vector<int>> graph(n);
        for (auto i : richer)
            graph[i.second].push_back(i.first);
        std::vector<int> answer(n, -1);
        for (int i = 0; i < n; i++)
            dfs(graph, quiet, answer, i);
        return answer;
    }
    void dfs(std::vector<std::vector<int>> &graph, std::vector<int> &quiet, std::vector<int> &answer, int i)
    {
        if (answer[i] != -1)
            return;
        answer[i] = i;
        for (auto j : graph[i])
        {
            dfs(graph, quiet, answer, j);
            if (quiet[answer[j]] < quiet[answer[i]])
                answer[i] = answer[j];
        }
    }
};

int main()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<int> quiet(n);
    for (int i = 0; i < n; i++)
        std::cin >> quiet[i];
    std::vector<std::pair<int, int>> richer(m);
    for (int i = 0; i < m; i++)
        std::cin >> richer[i].first >> richer[i].second;
    auto answer = Solution().getAnswer(quiet, richer);
    for (int i = 0; i < answer.size(); i++)
    {
        std::cout << answer[i];
        if (i != answer.size() - 1)
            std::cout << " ";
    }
    return 0;
}