/*
 * output:
 * tomJackMaryJohn
 * 10
 */

#include <iostream>
#include <string>
using namespace std;

template <class T>
T SumArray(
    // --- fill in your code here ---
    T *begin, T *end)
{
    T total{};
    T *p = begin;
    while (p != end)
    {
        total += *p;
        p++;
    }
    return total;
    // ---
}

int main()
{
    string array[4] = {"Tom", "Jack", "Mary", "John"};
    cout << SumArray(array, array + 4) << endl;
    int a[4] = {1, 2, 3, 4}; // ÌáÊ¾£º1+2+3+4 = 10
    cout << SumArray(a, a + 4) << endl;
    return 0;
}