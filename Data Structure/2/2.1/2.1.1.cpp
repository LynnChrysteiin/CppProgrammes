/*
目的：使用自行设计的顺序表ADT或STL中的vector模板，设计并实现顺序表应用场合的一些简单算法设计。
应用3：试设计一个算法，删除非空顺序表L中的冗余元素，即使得操作之后的顺序表中只保留操作之前表中所有值都不相同的元素（提纯）。

参考函数原型：

（1）顺序表ADT版本
template<class ElemType>
void Purge_Sq( Sqlist<ElemType> &L )；

（2）vector版本
template<class ElemType>
void Purge_Sq( vector<ElemType> &L )；
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

template <class Iter>
void Purge_Sq(std::vector<Iter> &L)
{
    for (int i = 0; i < L.size(); ++i)
        for (int j = i + 1; j < L.size(); ++j)
            if (L[i] == L[j])
                L.erase(L.begin() + j--);
}

template <class Iter>
void doAll()
{
    std::vector<Iter> L;
    std::string line;
    std::getline(std::cin, line);
    std::stringstream ss(line);
    Iter temp;
    while (ss >> temp)
        L.push_back(temp);
    std::cout << L[0];
    for (int i = 1; i < L.size(); i++)
        std::cout << "," << L[i];
    Purge_Sq(L);
    std::cout << std::endl
              << std::endl
              << L[0];
    for (int i = 1; i < L.size(); i++)
        std::cout << "," << L[i];
}

int main()
{
    int type;
    std::cin >> type;
    getchar();
    if (type == 0)
        doAll<int>();
    else if (type == 1)
        doAll<double>();
    else if (type == 2)
        doAll<char>();
    else if (type == 3)
        doAll<std::string>();
    else
        std::cout << "err";
    return 0;
}