/*
使用数组编程：
有两个集合，求其并集并输出。
要求：先输入集合A，再输入集合B，然后将B中（不属于集合A）的元素按顺序插入到A的后面（保持在B中的顺序），最后输出集合A（结果）的内容
*/

#include <iostream>
using namespace std;

bool isInArray(int *array, int len, int elem)
{
    int i;
    for (i = 0; i < len; ++i)
    {
        if (array[i] == elem)
            return true;
    }
    return false;
}

int main()
{
    int m, n, i;

    cin >> m;
    int *arrayM = new int[m];
    for (i = 0; i < m; ++i)
        cin >> arrayM[i];

    cin >> n;
    int *arrayN = new int[n];
    for (i = 0; i < n; ++i)
        cin >> arrayN[i];

    int *arrayNew = new int[m + n];
    int length = m;

    for (i = 0; i < m; ++i)
        arrayNew[i] = arrayM[i];
    for (i = 0; i < n; ++i)
    {
        if (!isInArray(arrayM, m, arrayN[i]))
        {
            arrayNew[length] = arrayN[i];
            ++length;
        }
    }

    cout << arrayNew[0];
    for (i = 1; i < length; ++i)
        cout << " " << arrayNew[i];

    delete[] arrayM;
    delete[] arrayN;
    delete[] arrayNew;
    return 0;
}