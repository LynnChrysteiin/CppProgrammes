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
应用：正读与反读都相同的字符序列称为“回文”序列。

请使用顺序栈，设计并实现一个算法，判断依次读入的一个以@为结束符的字符序列是否为形如'序列1&序列2'模式的字符序列。
其中序列1和序列2中都不含有字符‘&’，且序列2是序列1的逆序列。例如，‘a+b&b+a’是属于该模式的字符序列，而‘1+3&3-1’则不是。
*/

#include <iostream>
#include <stack>
using namespace std;

template <class Iter>
bool parlindrome_judge(stack<Iter> &S)
{
    stack<Iter> S1;
    while (!S.empty() && S.top() != '&')
    {
        S1.push(S.top());
        S.pop();
    }
    S.pop();
    while (!S.empty() && !S1.empty())
    {
        if (S.top() != S1.top())
            return false;
        S.pop();
        S1.pop();
    }
    if (S.empty() && S1.empty())
        return true;
    else
        return false;
}

int main()
{
    stack<char> S;
    char ch;
    while (cin >> ch && ch != '@')
        S.push(ch);
    if (parlindrome_judge(S))
        cout << "true"<< endl;
    else
        cout << "false" << endl;
    return 0;
}