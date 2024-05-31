/*
目的：
使用C++模板设计顺序队列的抽象数据类型（ADT）。
并在此基础上，使用顺序队列ADT的基本操作，设计并实现简单应用的算法设计。
内容：
（1）请参照顺序栈的ADT模板，设计顺序队列的抽象数据类型。
    （由于该环境目前仅支持单文件的编译，故将所有内容都集中在一个源文件内。
    在实际的设计中，推荐将抽象类及对应的派生类分别放在单独的头文件中。参考教材、课件，以及网盘中的顺序栈ADT原型文件，自行设计顺序队列的ADT。）

（2）ADT的简单应用：使用该ADT设计并实现若干应用顺序队列的算法设计。

应用1：要求设计一个算法，使用顺序队列，设计并实现打印输出杨辉三角形前N行元素的算法。

参考函数原型：
template<class ElemType>
void YangHuiTriangle(SqQueue<ElemType> &Q, int N);
*/

#include <iostream>
#include <queue>
using namespace std;

template <class Iter>
void YangHuiTriangle(queue<Iter> &Q, int N)
{
    queue<Iter> preQ;
    for (int i = 1; i <= N; ++i)
    {
        if (i == 1)
        {
            Q.push(1);
            cout << Q.front() << endl;
            preQ = Q;
            Q.pop();
        }
        else
        {
            Q.push(1);
            for (int j = 3; j <= i; ++j)
            {
                Iter a = preQ.front();
                preQ.pop();
                Iter b = preQ.front();
                Q.push(a + b);
            }
            Q.push(1);
            preQ = Q;
            cout << Q.front();
            Q.pop();
            while (!Q.empty())
            {
                cout << " " << Q.front();
                Q.pop();
            }
            cout << endl;
        }
    }
}

int main()
{
    int N;
    cin >> N;
    queue<int> Q;
    YangHuiTriangle(Q, N);
    return 0;
}