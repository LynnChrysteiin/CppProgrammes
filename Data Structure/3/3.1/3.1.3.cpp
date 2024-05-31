/*
目的：使用C++模板设计顺序栈的抽象数据类型（ADT）。

并在此基础上，使用顺序栈ADT的基本操作，设计并实现简单应用的算法设计。
内容：
（1）请参照顺序表的ADT模板，设计顺序栈的抽象数据类型。
    （由于该环境目前仅支持单文件的编译，故将所有内容都集中在一个源文件内。
    在实际的设计中，推荐将抽象类及对应的派生类分别放在单独的头文件中。参考教材、课件，以及网盘中的顺序表ADT原型文件，自行设计顺序栈的ADT。）

（2）ADT的简单应用：使用该ADT设计并实现若干应用顺序栈的算法设计。

应用3：假设表达式允许有两种括号：圆括号和方括号，其嵌套顺序随意。
要求设计一个算法，使用顺序栈，实现括弧匹配检验的算法设计。

括弧匹配：检验函数返回true；反之，返回false
*/

#include <iostream>
#include <stack>
#include <sstream>
using namespace std;

template <class Iter>
bool Matching(stack<Iter> &S)
{
    stringstream ss;
    string str;
    getline(cin, str);
    ss << str;
    Iter c;
    ss >> c;
    S.push(c);
    while (ss >> c)
    {
        if (c == '(' || c == '[')
            S.push(c);
        else if (c == ')' && S.top() == '(')
            S.pop();
        else if (c == ']' && S.top() == '[')
            S.pop();
    }
    return S.empty();
}

int main()
{
    stack<char> S;
    Matching(S) ? cout << "Correct" : cout << "Wrong";
    return 0;
}