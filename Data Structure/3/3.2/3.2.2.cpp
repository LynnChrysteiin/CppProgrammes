/*
你现在是一场采用特殊赛制棒球比赛的记录员。这场比赛由若干回合组成，过去几回合的得分可能会影响以后几回合的得分。
比赛开始时，记录是空白的。
你会得到一个记录操作的字符串列表 ops，其中 ops[i] 是你需要记录的第 i 项操作，ops 遵循下述规则：
    整数 x - 表示本回合新获得分数 x
    "+" - 表示本回合新获得的得分是前两次得分的总和。题目数据保证记录此操作时前面总是存在两个有效的分数。
    "D" - 表示本回合新获得的得分是前一次得分的两倍。题目数据保证记录此操作时前面总是存在一个有效的分数。
    "C" - 表示前一次得分无效，将其从记录中移除。题目数据保证记录此操作时前面总是存在一个有效的分数。
请你返回记录中所有得分的总和。

提示：
（1）1 <= ops.length <= 1000
（2）ops[i] 为 "C"、"D"、"+"，或者一个表示整数的字符串。整数范围是 [-3 * 104, 3 * 104]
（3）对于 "+" 操作，题目数据保证记录此操作时前面总是存在两个有效的分数
（4）对于 "C" 和 "D" 操作，题目数据保证记录此操作时前面总是存在一个有效的分数
*/

#include <iostream>
#include <vector>
#include <stack>

int callPoints(std::vector<std::string> &ops)
{
    std::stack<int> s;
    for (int i = 0; i < ops.size(); ++i)
    {
        if (ops[i][0] == '+')
        {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.push(a);
            s.push(a + b);
        }
        else if (ops[i][0] == 'D')
            s.push(s.top() * 2);
        else if (ops[i][0] == 'C')
            s.pop();
        else
            s.push(std::stoi(ops[i]));
    }
    int sum = 0;
    while (!s.empty())
    {
        sum += s.top();
        s.pop();
    }
    return sum;
}

int main()
{
    std::string str;
    std::vector<std::string> ops;
    while (std::cin >> str)
        ops.push_back(str);
    std::cout << callPoints(ops);
    return 0;
}
