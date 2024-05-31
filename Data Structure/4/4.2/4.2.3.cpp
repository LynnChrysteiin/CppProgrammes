/*
请你仅使用两个栈实现先入先出队列MyQueue类（即内部的存储结构不能使用数组或链表之类，而是要用两个栈）。
队列应当支持一般队列支持的所有操作（push、pop、peek、empty）。
请再实现main函数，读入测试数据中的指令，调用MyQueue类中的相应操作以获得结果。

MyQueue 类至少包含以下操作：
void push(int x) 将元素 x 推到队列的末尾
int pop() 从队列的开头移除并返回元素
int peek() 返回队列开头的元素
boolean empty() 如果队列为空，返回 true ；否则，返回 false

说明：
你只能使用标准的栈操作 —— 也就是只有 push to top, peek/pop from top, size, 和 is empty 操作是合法的。
*/

#include <iostream>
#include <stack>
#include <string>

template <class Iter>
class MyQueue
{
private:
    std::stack<Iter> s1;
    std::stack<Iter> s2;

public:
    MyQueue()
    {
        s1 = std::stack<Iter>();
        s2 = std::stack<Iter>();
    }
    void push(Iter x) { s1.push(x); }
    bool empty() { return s1.empty(); }
    Iter pop();
    Iter peek();
};

template <class Iter>
Iter MyQueue<Iter>::pop()
{
    while (!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }
    Iter res = s2.top();
    s2.pop();
    while (!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }
    return res;
}

template <class Iter>
Iter MyQueue<Iter>::peek()
{
    while (!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }
    Iter res = s2.top();
    while (!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }
    return res;
}

int main()
{
    MyQueue<int> Q;
    std::string op;
    while (std::cin >> op)
    {
        if (op == "push")
        {
            int x;
            std::cin >> x;
            Q.push(x);
        }
        else if (op == "pop")
        {
            std::cout << Q.pop() << std::endl;
        }
        else if (op == "peek")
        {
            std::cout << Q.peek() << std::endl;
        }
        else if (op == "empty")
        {
            Q.empty() ? std::cout << "true" : std::cout << "false";
            std::cout << std::endl;
        }
    }
    return 0;
}