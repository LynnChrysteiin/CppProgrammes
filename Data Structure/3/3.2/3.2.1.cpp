/*
有效括号字符串为空 ""、"(" + A + ")" 或 A + B ，其中 A 和 B 都是有效的括号字符串，+ 代表字符串的连接。
例如，""，"()"，"(())()" 和 "(()(()))" 都是有效的括号字符串。
如果有效字符串 s 非空，且不存在将其拆分为 s = A + B 的方法，
我们称其为原语（primitive），其中 A 和 B 都是非空有效括号字符串。

给出一个非空有效字符串 s，考虑将其进行原语化分解，
使得：s = P_1 + P_2 + ... + P_k，其中 P_i 是有效括号字符串原语。
对 s 进行原语化分解，删除分解中每个原语字符串的最外层括号，返回 s 。
*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

string removeOuterParentheses(string str)
{
    stack<char> s;
    string res;
    char c;
    for (int i = 0; i < str.size(); ++i)
    {
        c = str[i];
        if (c == '(')
        {
            s.push(c);
            if (s.size() > 1)
                res += c;
        }
        else
        {
            s.pop();
            if (s.size() > 0)
                res += c;
        }
    }
    return res;
}

int main()
{
    string str;
    cin >> str;
    cout << removeOuterParentheses(str) << endl;
    return 0;
}