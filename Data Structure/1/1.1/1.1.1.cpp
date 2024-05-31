/*
使用数组编程：
一个有序的整数序列，其中有重复元素，请删除重复元素。
注意：本题的序列是有序的，要利用到这个特性，从而降低时间复杂度。
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int *array = new int[n];
    int i;
    for (i = 0; i < n; ++i)
        cin >> array[i];
    int tmp = array[0];
    cout << tmp;
    for (i = 1; i < n; ++i)
    {
        if (array[i] != tmp)
        {
            cout << " " << array[i];
            tmp = array[i];
        }
    }
    delete[] array;
    return 0;
}