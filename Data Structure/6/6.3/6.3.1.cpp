/*
 * ��һ��С������� 1 �� N ����� N ���ˡ����Գƣ���Щ������һ����С���ϵ����ܷ��١�
 * ���С��ķ�����Ĵ��ڣ���ô��
 * С��ķ��ٲ������κ��ˡ�
 * ÿ���ˣ�����С�򷨹��⣩������С��ķ��١�
 * ֻ��һ����ͬʱ�������� 1 ������ 2 ��
 * �������� trust�������������ζ� trust[i] = [a, b] ��ɣ���ʾ���Ϊ a �������α��Ϊ b ���ˡ�
 * ���С��������ܷ��ٲ��ҿ���ȷ��������ݣ��뷵�ظ÷��ٵı�ǡ����򣬷��� -1��
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