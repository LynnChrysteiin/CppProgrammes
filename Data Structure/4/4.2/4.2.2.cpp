/*
请你仅使用两个队列实现一个后入先出（LIFO）的栈MyStack 类（即内部的存储结构不能使用数组或链表之类，而是要用两个队列），并支持普通栈的全部四种操作（push、top、pop 和 empty）。
请再实现main函数，读入测试数据中的指令，调用MyStack类中的相应操作以获得结果。
MyStack 类至少包含以下操作：
void push(int x) 将元素 x 压入栈顶。
int pop() 移除并返回栈顶元素。
int top() 返回栈顶元素。
boolean empty() 如果栈是空的，返回 true ；否则，返回 false 。

注意：
你只能使用队列的基本操作 —— 也就是 push to back、peek/pop from front、size 和 is empty 这些操作。
*/

#include <iostream>
#include <queue>
#include <string>

template <class Iter>
class MyStack
{
private:
    std::queue<Iter> q1;
    std::queue<Iter> q2;

public:
    MyStack()
    {
        q1 = std::queue<Iter>();
        q2 = std::queue<Iter>();
    }
    void push(Iter x) { q1.push(x); }
    bool empty() { return q1.empty(); }
    Iter pop();
    Iter top();
};

template <class Iter>
Iter MyStack<Iter>::pop()
{
    while (q1.size() > 1)
    {
        q2.push(q1.front());
        q1.pop();
    }
    Iter res = q1.front();
    q1.pop();
    std::swap(q1, q2);
    return res;
}

template <class Iter>
Iter MyStack<Iter>::top()
{
    while (q1.size() > 1)
    {
        q2.push(q1.front());
        q1.pop();
    }
    Iter res = q1.front();
    q2.push(q1.front());
    q1.pop();
    std::swap(q1, q2);
    return res;
}

int main()
{
    MyStack<int> s;
    std::string op;
    int x;
    while (std::cin >> op)
    {
        if (op == "push")
        {
            std::cin >> x;
            s.push(x);
        }
        else if (op == "pop")
        {
            std::cout << s.pop() << std::endl;
        }
        else if (op == "top")
        {
            std::cout << s.top() << std::endl;
        }
        else if (op == "empty")
        {
            s.empty() ? std::cout << "true" : std::cout << "false";
            std::cout << std::endl;
        }
    }
    return 0;
}