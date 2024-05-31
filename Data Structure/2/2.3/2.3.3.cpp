/*
内容：在指定范围[m,n]的所有整数中，试设计一算法找出所有的Armstrong数。

Armstrong数：如果一个k位正整数等于其各位数字的k次方之和,则称该数为阿姆斯特朗数。
例如，在三位(k=3)的整数中，153可以满足1^3 + 5^3 + 3^3 = 153，这样的数称之为Armstrong数。

参考函数原型：
void findArmstrong(int m, int n, vector<int> &Armstrong);

约定：
1<=m<=n<=100000
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

inline int getDigits(int num) { return floor(log10(num)) + 1; }

void findArmstrong(int m, int n, vector<int> &Armstrong)
{
    for (int i = m; i <= n; ++i)
    {
        int sum = 0;
        int tmp = i;
        while (tmp)
        {
            sum += pow(tmp % 10, getDigits(i));
            tmp /= 10;
        }
        if (sum == i)
            Armstrong.push_back(i);
    }
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<int> Armstrong;
    findArmstrong(m, n, Armstrong);
    if (Armstrong.empty())
    {
        cout << "null";
        return 0;
    }
    cout << Armstrong[0];
    for (int i = 1; i < Armstrong.size(); ++i)
        cout << "," << Armstrong[i];
    return 0;
}