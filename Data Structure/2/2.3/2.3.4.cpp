/*
目的：
使用自行设计的顺序表ADT或STL的vector模板设计并实现顺序表应用场合的一些简单算法设计。

应用8：
假设有一个整数类型的顺序表（假定为非空表），元素取值可能是1~N（10<=N<=100000）中的任意一个数，
相同数值不会重复出现。试设计一个算法，用O(n)的时间复杂度将找出顺序表中符合条件的数对的个数，满足数对中两数的和等于N+1。
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

template <class Iter>
int getCount(vector<Iter> &A, int N)
{
    unordered_map<Iter, int> hash_map;
    int count = 0;
    for (auto it = A.begin(); it != A.end(); it++)
    {
        if (hash_map.find(N + 1 - *it) != hash_map.end())
            count += hash_map[N + 1 - *it];
        hash_map[*it]++;
    }
    return count;
}

int main()
{
    int N;
    cin >> N;
    vector<int> A;
    int temp;
    while (cin >> temp)
        A.push_back(temp);
    auto it = A.begin();
    cout << *it++;
    for (it; it != A.end(); it++)
        cout << "," << *it;
    cout << endl
         << endl
         << getCount(A, N);
    return 0;
}