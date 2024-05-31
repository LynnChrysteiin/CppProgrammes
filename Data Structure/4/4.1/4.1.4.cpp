/*
应用：猴子选大王是一个小游戏，
其规则是：假设n个猴子围成一堆，取数字m为将要被淘汰的数字，
从第一个猴子开始数，数到数字m时，则该猴子出列，被淘汰，
然后从被淘汰的猴子的下一个开始数，再数到数字m时，这个猴子也被淘汰，
从下一个开始数，依次进行，直到剩下一个猴子结束。该猴子即猴子大王。

要求设计一个算法，使用链队列，设计并实现按照以上规则进行选择猴王的算法。
为简单起见，直接输出猴王的序号即可，无需保存。

参考函数原型：
template<class ElemType>
void monkey_king(LinkQueue<ElemType> S, int n, int m);
*/

#include <iostream>
#include <queue>

template<class Iter>
void monkey_king(std::queue<Iter> S, int n, int m)
{
    while (S.size() > 1)
    {
        for (int i = 1; i < m; ++i)
        {
            S.push(S.front());
            S.pop();
        }
        S.pop();
    }
    std::cout << S.front();
}

int main()
{
    int n, m;
    std::cin >> n >> m;
    std::queue<int> S;
    for (int i = 1; i <= n; i++)
        S.push(i);
    monkey_king(S, n, m);
    return 0;
}