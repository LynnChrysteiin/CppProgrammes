/*
设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。

实现 MinStack 类:
MinStack() 初始化堆栈对象。
void push(int val) 将元素val推入堆栈。
void pop() 删除堆栈顶部的元素。
int top() 获取堆栈顶部的元素。
int getMin() 获取堆栈中的最小元素。

输入若干行
每行输入为push, pop, top,或者getMin
如果指令为push，后面需要输入一个整数
-2^31 <= 输入值val <= 2^31 - 1
pop、top 和 getMin 操作总是在 非空栈 上调用
push, pop, top, and getMin最多被调用 3 * 10^4 次

输出若干行
每行为一个整数，为getMin和top指令的返回值
每行都不包含多余空格
*/

#include <iostream>
#include <string>
using namespace std;

class MinStack
{
private:
    int *data;
    int *min;
    int size;

public:
    MinStack()
    {
        data = new int[30000];
        min = new int[30000];
        min[0] = 0x7fffffff;
        size = 0;
    }
    void push(int val)
    {
        data[size] = val;
        if (size == 0)
            min[size] = val;
        else
            min[size] = min[size - 1] < val ? min[size - 1] : val;
        size++;
    }
    void pop() { size--; }
    int top() { return data[size - 1]; }
    int getMin() { return min[size - 1]; }
    ~MinStack()
    {
        delete[] data;
        delete[] min;
    }
};

int main()
{
    MinStack myStack;
    string op;
    int val;
    while (cin >> op)
    {
        if (op == "push")
        {
            cin >> val;
            myStack.push(val);
        }
        else if (op == "getMin")
            cout << myStack.getMin() << endl;
        else if (op == "top")
            cout << myStack.top() << endl;
        else if (op == "pop")
            myStack.pop();
    }
    return 0;
}