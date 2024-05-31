/*
 * 有 n 个房间，房间按从 0 到 n - 1 编号。最初，除 0 号房间外的其余所有房间都被锁住。
 * 你的目标是进入所有的房间。然而，你不能在没有获得钥匙的时候进入锁住的房间。
 * 当你进入一个房间，你可能会在里面找到一套不同的钥匙，每把钥匙上都有对应的房间号，即表示钥匙可以打开的房间。
 * 你可以拿上所有钥匙去解锁其他房间。给你一个数组 rooms 其中 rooms[i] 是你进入 i 号房间可以获得的钥匙集合。
 * 如果能进入 所有 房间返回 true，否则返回 false。
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