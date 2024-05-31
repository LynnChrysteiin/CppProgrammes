/*
目的：使用自行设计的顺序表ADT或STL中的vector模板，设计并实现顺序表应用场合的一些简单算法设计。
应用5：试设计一个算法，删除有序顺序表L中的冗余元素，即使得操作之后的顺序表中只保留操作之前表中所有值都不相同的元素，并保持其有序性。

参考函数原型：

（1）顺序表ADT版本
template<class ElemType>
void Purge_Sq_OL( SqList<ElemType> &L )；

（2）vector版本
template<class ElemType>
void Purge_Sq_OL( vector<ElemType> &L )；
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

template <class Iter>
void Purge_Sq_OL(vector<Iter> &L)
{
    for (int i = 1; i < L.size(); ++i)
        if (L[i] == L[i - 1])
            L.erase(L.begin() + i--);
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
    Purge_Sq_OL(L);
    cout << endl
         << endl
         << L[0];
    for (int i = 1; i < L.size(); i++)
        cout << "," << L[i];
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