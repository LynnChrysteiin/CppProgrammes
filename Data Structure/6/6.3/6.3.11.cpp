/*
 * �� n ������ͨ��һЩ�������ӡ�
 * ����һ������ flights ������ flights[i] = [fromi, toi, pricei] ����ʾ�ú���ӳ��� fromi ��ʼ���Լ۸� pricei �ִ� toi��
 * ���ڸ������еĳ��кͺ��࣬�Լ��������� src ��Ŀ�ĵ� dst��
 * ����������ҵ�һ����ྭ�� k վ��ת��·�ߣ�ʹ�ô� src �� dst �� �۸������ �������ظü۸�
 * ���������������·�ߣ������ -1��
 */

#include <iostream>
#include <vector>

class Solution
{
public:
    int findCheapestPrice(int nCity, const std::vector<std::vector<int>> &flights, int src, int dst, int k)
    {
        // ��̬�滮
        const int INF = 0x3f3f3f3f;
        std::vector<std::vector<int>> dp(k + 2, std::vector<int>(nCity, INF));
        dp[0][src] = 0;
        for (int i = 1; i <= k + 1; i++)
        {
            for (const auto &flight : flights)
            {
                int from = flight[0], to = flight[1], price = flight[2];
                dp[i][to] = std::min(dp[i][to], dp[i - 1][from] + price); // ״̬ת�Ʒ���
            }
        }
        int ans = INF;
        for (int i = 1; i <= k + 1; i++)
            ans = std::min(ans, dp[i][dst]);
        return ans == INF ? -1 : ans;
    }
};

int main()
{
    int nCity, nFlight, src, dst, k;
    std::cin >> nCity >> nFlight;
    std::vector<std::vector<int>> flights(nFlight, std::vector<int>(3));
    for (int i = 0; i < nFlight; i++)
        std::cin >> flights[i][0] >> flights[i][1] >> flights[i][2];
    std::cin >> src >> dst >> k;
    std::cout << Solution().findCheapestPrice(nCity, flights, src, dst, k);
    return 0;
}