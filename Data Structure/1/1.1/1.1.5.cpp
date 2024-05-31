/*
使用数组编程：
有两个非递减有序序列，将它们合并成一个非递减有序序列。
注意：编程时要利用到“有序”这个条件，从而降低时间复杂度。
*/

#include <iostream>
using namespace std;

int main()
{
    int m, n, i, j;

    cin >> m;
    int *arrayM = new int[m];
    for (i = 0; i < m; ++i)
        cin >> arrayM[i];

    cin >> n;
    int *arrayN = new int[n];
    for (j = 0; j < n; ++j)
        cin >> arrayN[j];

    int *arrayNew = new int[m + n];

    for (i = 0, j = 0; (i < m) && (j < n);)
    {
        if ((arrayM[i] <= arrayN[j]))
            arrayNew[i + j] = arrayM[i++];
        else if ((arrayM[i] > arrayN[j]))
            arrayNew[i + j] = arrayN[i++];
    }
    if (i == m)
        for (; j < n; ++j)
            arrayNew[i + j] = arrayN[j];
    else if (j == n)
        for (; i < m; ++i)
            arrayNew[i + j] = arrayM[i];

    cout << arrayNew[0];
    for (i = 1; i < m + n; ++i)
        cout << " " << arrayNew[i];
    cout << endl;

    delete[] arrayM;
    delete[] arrayN;
    delete[] arrayNew;
    return 0;
}