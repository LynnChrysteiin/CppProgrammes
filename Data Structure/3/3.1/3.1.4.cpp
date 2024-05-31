/*
目的：
使用C++模板设计顺序栈的抽象数据类型（ADT）。
并在此基础上，使用顺序栈ADT的基本操作，设计并实现简单应用的算法设计。

内容：
（1）请参照顺序表的ADT模板，设计顺序栈的抽象数据类型。
    （由于该环境目前仅支持单文件的编译，故将所有内容都集中在一个源文件内。在实际的设计中，推荐将抽象类及对应的派生类分别放在单独的头文件中。参考教材、课件，以及网盘中的顺序表ADT原型文件，自行设计顺序栈的ADT。）

（2）ADT的简单应用：使用该ADT设计并实现若干应用顺序栈的算法设计。

应用2：若按教科书3.1.1节中图3.1(b)所示铁道进行车厢调度（注意：两侧铁道均为单向行驶道）。
假设该火车调度站的入口处有n节硬席或软席车厢（分别以Hi和Sj表示，i、j代表各自的序号。）等待调度。

要求设计一个算法，使用顺序栈，输出对这n节车厢进行调度的结果序列，
使得所有的软席车厢都被调整到硬席车厢的前面，并且软席车厢顺序保持和原来一致，但硬席车厢顺序颠倒。
*/

#include <iostream>
#include <stack>
#include <vector>
#include <sstream>
using namespace std;

template <class Iter>
string Conversion(stack<Iter> &hard, string &train)
{
    istringstream iss(train);
    vector<Iter> soft;
    Iter temp;
    while (getline(iss, temp, ' '))
    {
        if (temp[0] == 'H')
            hard.push(temp);
        else if (temp[0] == 'S')
            soft.push_back(temp);
    }
    string result;
    for (int i = 0; i < soft.size(); i++)
    {
        result += soft[i];
        result += " ";
    }
    while (!hard.empty())
    {
        result += hard.top();
        result += " ";
        hard.pop();
    }
    return result;
}

int main()
{
    string train;
    getline(cin, train);
    stack<string> S;
    cout << Conversion(S, train);
    return 0;
}