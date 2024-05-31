/*
目的：使用自行设计的顺序表ADT或STL的vector模板设计并实现顺序表应用场合的一些简单算法设计。
应用8：试设计一个算法，找出顺序表A中最大和最小的元素（输出在屏幕上），并保持原顺序表不变。

（1）顺序表ADT版本
参考函数原型：
template<class ElemType>
bool Search_Max_Min( const SqList<ElemType> &A, ElemType &max, ElemType &min );

（2）vector版本
参考函数原型：
template<class ElemType>
bool Search_Max_Min( const vector<ElemType> &A, ElemType &max, ElemType &min );
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

template <class Iter>
bool Search_Max_Min(const vector<Iter> &A, Iter &max, Iter &min)
{
    max = A[0];
    min = A[0];
    for (int i = 0; i < A.size(); ++i)
    {
        if (A[i] > max)
            max = A[i];
        if (A[i] < min)
            min = A[i];
    }
    return true;
}

template <class Iter>
void doAll()
{
    vector<Iter> L;
    string line;
    getline(cin, line);
    stringstream ss(line);
    Iter temp;
    while (ss >> temp)
        L.push_back(temp);
    cout << L[0];
    for (int i = 1; i < L.size(); i++)
        cout << "," << L[i];
    Iter max, min;
    Search_Max_Min(L, max, min);
    cout << endl
         << max << endl
         << min;
}

int main()
{
    int type;
    cin >> type;
    getchar();
    if (type == 0)
        doAll<int>();
    else if (type == 1)
        doAll<double>();
    else if (type == 2)
        doAll<char>();
    else if (type == 3)
        doAll<string>();
    else
        cout << "err";
    return 0;
}