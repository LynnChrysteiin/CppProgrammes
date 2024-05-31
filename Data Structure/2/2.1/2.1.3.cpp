/*
目的：使用自行设计的顺序表ADT或STL的vector模板设计并实现顺序表应用场合的一些简单算法设计。
应用7：试设计一个算法，找出有序顺序表A（顺序表A中的数据元素的数据类型为int型，非空表，且无重复值）中两个元素和为给定值sum的所有元素对，并保持原顺序表不变。

（1）顺序表ADT版本
参考函数原型：
template<class ElemType>
void Search_Pairs( const SqList<ElemType> &A, int sum )；

（2）vector版本
参考函数原型：
template<class ElemType>
void Search_Pairs( const vector<ElemType> &A, int sum )；
*/

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <map>
using namespace std;

template <class Iter>
void Search_Pairs(const vector<Iter> &A, int sum)
{
    map<Iter, bool> hash_table;
    vector<int> result;
    for (int i = 0; i < A.size(); ++i)
        hash_table[A[i]] = true;
    for (int i = 0; i < A.size(); ++i)
        if (hash_table[sum - A[i]] && A[i] != sum - A[i])
        {
            hash_table[A[i]] = false;
            result.push_back(A[i]);
            result.push_back(sum - A[i]);
        }
    if (result.size() == 0)
        cout << "NULL";
    else
    {
        cout <<  "(" << result[0] << "," << result[1] << ")";
        for (int i = 2; i < result.size(); i += 2)
            cout << "," << "(" << result[i] << "," << result[i + 1] << ")";
    }
}

int main()
{
    vector<int> A;
    int sum;
    int temp;
    string line;
    stringstream ss;
    getline(cin, line);
    ss << line;
    while (ss >> temp)
        A.push_back(temp);
    cin >> sum;
    cout << A[0];
    for (int i = 1; i < A.size(); ++i)
        cout << "," << A[i];
    cout << endl
         << endl;
    Search_Pairs(A, sum);
    return 0;
}