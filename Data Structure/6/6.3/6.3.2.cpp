/*
 * �� n �����䣬���䰴�� 0 �� n - 1 ��š�������� 0 �ŷ�������������з��䶼����ס��
 * ���Ŀ���ǽ������еķ��䡣Ȼ�����㲻����û�л��Կ�׵�ʱ�������ס�ķ��䡣
 * �������һ�����䣬����ܻ��������ҵ�һ�ײ�ͬ��Կ�ף�ÿ��Կ���϶��ж�Ӧ�ķ���ţ�����ʾԿ�׿��Դ򿪵ķ��䡣
 * �������������Կ��ȥ�����������䡣����һ������ rooms ���� rooms[i] ������� i �ŷ�����Ի�õ�Կ�׼��ϡ�
 * ����ܽ��� ���� ���䷵�� true�����򷵻� false��
 */

#include <iostream>
#include <vector>
#include <sstream>
#include <queue>

class Solution
{
public:
    Solution() = default;
    ~Solution() = default;
    bool canVisitAllRooms(std::vector<std::vector<int>> rooms) // BFS
    {
        int n = rooms.size();
        std::vector<bool> visited(n, 0);
        visited[0] = 1;
        std::queue<int> keys;
        for (auto key : rooms[0])
            keys.push(key);
        while (!keys.empty())
        {
            int key = keys.front();
            keys.pop();
            if (!visited[key])
            {
                visited[key] = 1;
                for (auto next_key : rooms[key])
                    keys.push(next_key);
            }
        }
        for (auto v : visited)
        {
            if (!v)
                return false;
        }
        return true;
    }
};

int main()
{
    int n;
    std::cin >> n;
    getchar();
    std::vector<std::vector<int>> rooms(n);
    int a;
    for (int i = 0; i < n; ++i)
    {
        std::string str;
        getline(std::cin, str);
        std::stringstream ss(str);
        while (ss >> a)
            rooms[i].push_back(a);
    }
    std::cout << (Solution().canVisitAllRooms(rooms) ? "true" : "false") << std::endl;
    return 0;
}