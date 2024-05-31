/*
目的：
使用C++模板设计顺序栈的抽象数据类型（ADT）。并在此基础上，使用顺序栈ADT的基本操作，设计并实现简单应用的算法设计。
内容：
（1）请参照顺序表的ADT模板，设计顺序栈的抽象数据类型。
    （由于该环境目前仅支持单文件的编译，故将所有内容都集中在一个源文件内。
    在实际的设计中，推荐将抽象类及对应的派生类分别放在单独的头文件中。
    参考教材、课件，以及网盘中的顺序表ADT原型文件，自行设计顺序栈的ADT。）
 
（2）ADT的简单应用：使用该ADT设计并实现若干应用顺序栈的算法设计。
 
应用1：要求设计一个算法，使用顺序栈，实现键盘输入字符序列逆置输出的算法设计。
比如，从键盘上输入：tset a si sihT；算法将输出：This is a test。

要求：输入的字符串长度在所建的顺序栈的有效空间范围内是可变的。
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

template <class Iter>
void Invert_Input(stack<Iter> &S)
{
    string input;
    getline(cin, input);
    for (int i = 0; i < input.size(); i++)
        S.push(input[i]);
}

int main()
{
    stack<char> S;
    Invert_Input(S);
    while (!S.empty())
    {
        cout << S.top();
        S.pop();
    }
    return 0;
}