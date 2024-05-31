/*
给定 S 和 T 两个字符串，当它们分别被输入到空白的文本编辑器后，判断二者是否相等，并返回结果。 
# 代表退格字符。
要求使用 O(N) 的时间复杂度解决该问题。

注意：如果对空文本输入退格字符，文本继续为空。
*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool txt_cmp(string S, string T)
{
    stack<char> s1, s2;
    for (int i = 0; i < S.size(); i++)
    {
        if (S[i] == '#')
            if (!s1.empty())
                s1.pop();
        else
            s1.push(S[i]);
    }
    for (int i = 0; i < T.size(); i++)
    {
        if (T[i] == '#')
            if (!s2.empty())
                s2.pop();
        else
            s2.push(T[i]);
    }
    if (s1.size() != s2.size())
        return false;
    while (!s1.empty())
    {
        if (s1.top() != s2.top())
            return false;
        s1.pop();
        s2.pop();
    }
    return true;
}

int main()
{
    string S, T;
    cin >> S >> T;
    txt_cmp(S, T) ? cout << "true" : cout << "false";
    return 0;
}