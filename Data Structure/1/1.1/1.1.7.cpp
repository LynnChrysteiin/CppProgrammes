/*
输出删除重复元素后的序列。数字之间以一个空格分隔。
如果有多个元素相同，则保留第一个，删除后面所有的重复的元素。
*/

#include <iostream>
using namespace std;

bool isInArray(int *array, int len, int elem)
{
    int i;
    for (i = 0; i < len; ++i)
        if (array[i] == elem)
            return true;
    return false;
}

int main()
{
    int n, i;
    cin >> n;
    int *array = new int[n];
    int *newArray = new int[n];
    int count = 0;
    for (i = 0; i < n; ++i)
    {
        cin >> array[i];
    }
    for (i = 0; i < n; ++i)
        if (!isInArray(newArray, count, array[i]))
            newArray[count++] = array[i];

    cout << newArray[0];
    for (int i = 1; i < count; ++i)
        cout << " " << newArray[i];
    return 0;
}