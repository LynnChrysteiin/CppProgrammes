/*
应用：假设某国特工收到一串事先经过加密处理的密码数字（每位数字的范围为0-9），
要求按照预先设定的规则将其解码，恢复到原始的状态，方可使用。
解码规则如下：首先将第1位数删除，紧接着将第2位数放到这串数的末尾，
再将第3位数删除，再将第4位数放到这串数的末尾，再将第5位数删除……
直到剩下最后一位数，将最后一位数也删除。
最后，按照刚才删除的顺序，把所有这些删除的数，按照删除的顺序重新连在一起就是原始的密码数字。

例如：给定的一串数字是“631758924”， 经过解码处理后，得到原始的密码数字为“615947283”。
接收到的数字串内如存在空格，空格不计入位数。

要求设计一个算法，使用顺序队列，设计并实现按照以上规则进行解码的算法。
为简单起见，解码结果直接输出即可，无需保存。

参考函数原型：
template<class ElemType>
void decode(SqQueue<ElemType> &S, string &code);
*/

#include <iostream>
#include <queue>
#include <string>

template<class Iter>
void decode(std::string &code)
{
    std::queue<Iter> Q;
    for (int i = 0; i < code.size(); i++)
        if (code[i] != ' ')
            Q.push(code[i]);
    while(Q.size() > 1)
    {
        std::cout << Q.front();
        Q.pop();
        Q.push(Q.front());
        Q.pop();
    }
    std::cout << Q.front() << std::endl;
}

int main()
{
    std::string code;
    getline(std::cin, code);
    decode<char>(code);
    return 0;
}