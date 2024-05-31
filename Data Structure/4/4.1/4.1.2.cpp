/*
应用：某部队进行新兵队列训练，将新兵从一开始按顺序依次编号，并排成一行横队，
训练的规则如下：从头开始一至二报数，凡报到二的出列，剩下的向小序号方向靠拢，
再从头开始进行一至三报数，凡报到三的出列，剩下的向小序号方向靠拢，继续从头开始进行一至二报数，
以后从头开始轮流进行一至二报数、一至三报数直到剩下的人数不超过三人为止。
要求设计一个算法，使用链队列或顺序队列（只能使用1个队列），设计并实现打印输出剩下的新兵最初的编号的算法。
注意：本题允许有多个测试数据组，新兵总人数不超过5000。
由于士兵可能的总人数较多，顺序队列需预先申请的存储空间较大，建议使用链队列。（样例程序使用的是链队列。）

参考函数原型：
template<class ElemType>
void queuetraining(SqQueue<ElemType> &S, int T); //T为测试数据的组数
*/

#include <iostream>
#include <list>
using namespace std;

void queueTraining(list<int> &S, int T)
{
    for (int i = 1; i <= T; ++i)
        S.push_back(i);
    while (S.size() > 3)
    {
        auto it = S.begin();
        ++it;
        while (it != S.end())
        {
            it = S.erase(it);
            if (it != S.end())
                ++it;
        }
        if (S.size() <= 3)
            break;
        it = S.begin();
        advance(it, 2);
        while (it != S.end())
        {
            it = S.erase(it);
            for (int i = 0; i < 2; ++i)
                if (it != S.end())
                    ++it;
        }
    }
    auto it = S.begin();
    while (it != S.end())
    {
        cout << *it++;
        if (it != S.end())
            cout << ",";
    }
}

int main()
{
    int N, T;
    list<int> S;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> T;
        queueTraining(S, T);
        S.clear();
        if (i != N - 1)
            cout << endl;
    }
    return 0;
}