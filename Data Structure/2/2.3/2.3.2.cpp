/*
目的：
使用C++模板设计单链表的抽象数据类型（ADT）。
并在此基础上，稍加改动，针对一元多项式建立相应的稀疏多项式ADT，
使用单链表ADT的基本操作，设计并实现稀疏一元多项式的加法计算的算法设计。

内容：
（1）请参照单链表的ADT模板，设计稀疏一元多项式的抽象数据类型。
    （由于该环境目前仅支持单文件的编译，故将所有内容都集中在一个源文件内。
    在实际的设计中，推荐将抽象类及对应的派生类分别放在单独的头文件中。
    参考网盘中的单链表ADT原型文件，自行设计稀疏一元多项式的ADT。）
（2）ADT的简单应用：使用该ADT设计并实现稀疏一元多项式的加法计算的算法设计。
    应用1：假设2个稀疏一元多项式分别由带头结点的有序单链表A和B存储。
    现要求设计一个算法，实现稀疏一元多项式的加减法计算。要求使用A和B的原存储空间，且计算后B不再单独存在。
    输入中的单链表的长度不得在计算算法中利用，仅作为建表使用。

假定：系数项的数据类型为double，指数项的数据类型为int，指数项递增有序，多项式至少有1项，系数项均不为0。

注意：加/减法计算后，如某一项的结果系数为0，则该项要从多项式链表中删除。
*/

#include <iostream>
#include <list>
#include <sstream>
using namespace std;

template <class ElemType1, class ElemType2>
struct polyNode
{
    ElemType1 coef;
    ElemType2 expn;
    polyNode(){};
};

template <class Iter>
void Add_Poly(list<Iter> &A, list<Iter> &B, int op)
{
    auto itA = A.begin(), itB = B.begin();
    if (op == 1)
        for (auto it = B.begin(); it != B.end(); ++it)
            it->coef *= -1;
    while (itA != A.end() && itB != B.end())
    {
        if (itA->expn == itB->expn)
        {
            itA->coef += itB->coef;
            if (itA->coef == 0)
                itA = A.erase(itA);
            else
                ++itA;
            itB = B.erase(itB);
        }
        else if (itA->expn < itB->expn)
            ++itA;
        else
        {
            A.insert(itA, *itB);
            itB = B.erase(itB);
        }
    }
    while (itB != B.end())
    {
        A.push_back(*itB);
        itB = B.erase(itB);
    }
}

template <class Iter>
void Print_Poly(list<Iter> A)
{
    if (A.empty() || A.begin()->coef == 0 && A.size() == 1)
    {
        cout << "0";
        return;
    }
    if (A.size() == 1 && A.begin()->expn == 0)
    {
        cout << A.begin()->coef;
        return;
    }
    for (auto it = A.begin(); it != A.end(); ++it)
    {
        if (it->coef > 1 && it != A.begin())
            cout << "+" << it->coef;
        else if (it->coef == 1 && it != A.begin())
            cout << "+";
        else if (it->coef == -1)
            cout << "-";
        else if (it->coef < 0 || it->coef > 1 || it->coef == 1 && it->expn == 0)
            cout << it->coef;
        if (it->expn != 0 && it->expn != 1)
            cout << "x^" << it->expn;
        else if (it->expn == 1)
            cout << "x";
    }
}

int main()
{
    int op;
    cin >> op;
    getchar();
    list<polyNode<double, int>> A, B;
    stringstream ss;
    string str;
    getline(cin, str);
    ss << str;
    while (ss)
    {
        polyNode<double, int> temp;
        if (!(ss >> temp.coef))
            break;
        A.push_back(temp);
    }
    ss.clear();
    getline(cin, str);
    ss << str;
    list<polyNode<double, int>>::iterator it = A.begin();
    while (ss && it != A.end())
    {
        if (!(ss >> it->expn))
            break;
        ++it;
    }
    ss.clear();
    getline(cin, str);
    ss << str;
    while (ss)
    {
        polyNode<double, int> temp;
        if (!(ss >> temp.coef))
            break;
        B.push_back(temp);
    }
    ss.clear();
    getline(cin, str);
    ss << str;
    it = B.begin();
    while (ss && it != B.end())
    {
        if (!(ss >> it->expn))
            break;
        ++it;
    }
    Print_Poly(A);
    cout << endl;
    Print_Poly(B);
    cout << endl
         << endl;
    Add_Poly(A, B, op);
    Print_Poly(A);
    return 0;
}