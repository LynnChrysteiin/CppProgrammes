/*
 * 在一个小镇里，按从 1 到 N 标记了 N 个人。传言称，这些人中有一个是小镇上的秘密法官。
 * 如果小镇的法官真的存在，那么：
 * 小镇的法官不相信任何人。
 * 每个人（除了小镇法官外）都信任小镇的法官。
 * 只有一个人同时满足属性 1 和属性 2 。
 * 给定数组 trust，该数组由信任对 trust[i] = [a, b] 组成，表示标记为 a 的人信任标记为 b 的人。
 * 如果小镇存在秘密法官并且可以确定他的身份，请返回该法官的标记。否则，返回 -1。
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    Solution() = default;
    ~Solution() = default;
    int findJudge(int n, vector<pair<int, int>> trust)
    {
        vector<int> inDegree(n + 1, 0);
        vector<int> outDegree(n + 1, 0);
        for (auto t : trust)
        {
            inDegree[t.second]++;
            outDegree[t.first]++;
        }
        for (int i = 1; i <= n; i++)
            if (inDegree[i] == n - 1 && outDegree[i] == 0)
                return i;
        return -1;
    }
};

int main()
{
    int n, m;
    vector<pair<int, int>> trust;
    cin >> n >> m;
    int p1, p2;
    for (int i = 0; i < m; i++)
    {
        cin >> p1 >> p2;
        pair<int, int> trustPair(p1, p2);
        trust.push_back(trustPair);
    }
    int res = Solution().findJudge(n, trust);
    cout << res << endl;
}