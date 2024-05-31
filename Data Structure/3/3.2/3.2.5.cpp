/*
给你一个字符串表达式 s ，请你实现一个基本计算器来计算并返回它的值。

注意:不允许使用任何将字符串作为数学表达式计算的内置函数，比如 eval() 。

说明：
    1 <= s.length <= 3 * 10^5
    s 由数字、'+'、'-'、'('、')'、和 ' ' 组成
    s 表示一个有效的表达式
    '+' 不能用作一元运算(例如， "+1" 和 "+(2 + 3)" 无效)
    '-' 可以用作一元运算(即 "-1" 和 "-(2 + 3)" 是有效的)
    输入中不存在两个连续的操作符
    每个数字和计算的结果将不超过有符号的32位整数（即int型整数）的表示范围
*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int cal(string equa)
{
    stack<int> num;
    stack<char> op;
    for (int i = 0; i < equa.size(); ++i)
    {
        if (equa[i] == ' ')
            continue;
        else if (equa[i] == '(')
            op.push('(');
        else if (equa[i] == ')')
        {
            while (op.top() != '(')
            {
                int a = num.top();
                num.pop();
                if (op.top() == '+')
                    num.top() += a;
                else if (op.top() == '-')
                    num.top() -= a;
                op.pop();
            }
            op.pop();
            if (!op.empty() && op.top() != '(')
            {
                int a = num.top();
                num.pop();
                int b = num.top();
                num.pop();
                if (op.top() == '+')
                    num.push(b + a);
                else if (op.top() == '-')
                    num.push(b - a);
                op.pop();
            }
        }
        else if (equa[i] == '+')
            op.push('+');
        else if (equa[i] == '-')
        {
            if ((i > 0 && equa[i - 1] == '(') || i == 0)
                num.push(0);
            op.push('-');
        }
        else
        {
            int tmp = 0;
            while (i < equa.size() && equa[i] >= '0' && equa[i] <= '9')
            {
                tmp = tmp * 10 + equa[i] - '0';
                ++i;
            }
            --i;
            num.push(tmp);
            while (!op.empty() && op.top() != '(')
            {
                int a = num.top();
                num.pop();
                int b = num.top();
                num.pop();
                if (op.top() == '+')
                    num.push(b + a);
                else if (op.top() == '-')
                    num.push(b - a);
                op.pop();
            }
        }
    }
    return num.top();
}

int main()
{
    string e;
    cin >> e;
    cout << cal(e);
    return 0;
}