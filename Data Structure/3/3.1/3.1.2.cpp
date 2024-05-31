/*
目的：
使用C++模板设计顺序栈的抽象数据类型（ADT）。
并在此基础上，使用顺序栈ADT的基本操作，设计并实现简单应用的算法设计。

内容：
（1）请参照顺序表的ADT模板，设计顺序栈的抽象数据类型。
    （由于该环境目前仅支持单文件的编译，故将所有内容都集中在一个源文件内。
    在实际的设计中，推荐将抽象类及对应的派生类分别放在单独的头文件中。
    参考教材、课件，以及网盘中的顺序表ADT原型文件，自行设计顺序栈的ADT。）

（2）ADT的简单应用：使用该ADT设计并实现若干应用顺序栈的算法设计。

应用：
近期科学家们在熬夜写论文报告，可是不争气的键盘出现了一系列的问题，有的时候点一下键盘往外出两个字符，有的时候只出一个。
恰巧键盘的退格键坏了。你知道科学家们都是有怪脾气的，他自己打出一篇文章，他就想恢复成原来的。

科学家满意的字符串是这样的，如果字符串中有相临的两个字符相同就消除这两个字符，形成一个新的字符串，
如果新的字符串还有相邻的字符并且相同，再消除。一直到没有相邻的两个字符相同为止
*/

#include <iostream>
#include <stack>
#include <sstream>
using namespace std;

int main()
{
    stack<char> S;
    char c;
    stringstream ss;
    string str;
    getline(cin, str);
    ss << str;
    ss >> c;
    S.push(c);
    while (ss >> c)
    {
        if (c == S.top())
            S.pop();
        else
            S.push(c);
    }
    stack<char> S1;
    while (!S.empty())
    {
        S1.push(S.top());
        S.pop();
    }
    while (!S1.empty())
    {
        cout << S1.top();
        S1.pop();
    }
    return 0;
}