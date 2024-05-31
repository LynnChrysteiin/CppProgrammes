/*
目的：使用自行设计的顺序表ADT或STL中的vector模板，设计并实现顺序表应用场合的一些简单算法设计。

应用6：假设以两个元素依值递增有序排列的线性表A和B分别表示两个集合，现要求设计一个算法，另辟空间构成一个线性表C，其元素为A和B中元素的交集，且C中的元素也依值递增有序排列，且互不相同。

参考函数原型：

（1）顺序表ADT版本
template<class ElemType>
void Intersect_Sq_OL_C( const SqList<ElemType> &A, const SqList<ElemType> &B, SqList<ElemType> &C )；

（2）vector版本
template<class ElemType>
void Intersect_Sq_OL_C( const vector<ElemType> &A, const vector<ElemType> &B, vector<ElemType> &C )；
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

template <class Iter>
void Intersect_Sq_OL_C(const vector<Iter> &A, const vector<Iter> &B, vector<Iter> &C)
{
    int i = 0, j = 0;
    while (i < A.size() && j < B.size())
    {
        if (A[i] < B[j])
            ++i;
        else if (A[i] > B[j])
            ++j;
        else
        {
            C.push_back(A[i]);
            ++i;
            ++j;
        }
    }
}

template <class Iter>
void printList(vector<Iter> &L)
{
    cout << L[0];
    for (int i = 1; i < L.size(); i++)
        cout << "," << L[i];
    cout << endl;
}

template <class Iter>
void doAll()
{
    vector<Iter> A, B, C;
    string line;
    Iter temp;
    getline(cin, line);
    stringstream ssa(line);
    while (ssa >> temp)
        A.push_back(temp);
    getline(cin, line);
    stringstream ssb(line);
    while (ssb >> temp)
        B.push_back(temp);
    printList(A);
    printList(B);
    cout << endl;
    Intersect_Sq_OL_C(A, B, C);
    printList(C);
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