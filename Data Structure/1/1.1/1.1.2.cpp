/*
使用数组编程：
一群学生排成一行，输入一个位置，将该位置的学生移除。
第一个学生的位置为1，第n个学生的位置为n。
*/

#include <iostream>
using namespace std;

void output(int *num, int len, int n)
{
    int i;
    if (len <= 0)
    {
        cout << "empty" << endl;
        return;
    }
    cout << num[0];
    for (i = 1; i < n; ++i)
    {
        if (num[i] != -1)
            cout << " " << num[i];
    }
    cout << endl;
    return;
}

int main()
{
    int n;
    cin >> n;
    int len = n;
    int *num = new int[n];
    int i, index;
    for (i = 0; i < n; ++i)
    {
        cin >> num[i];
    }
    while (cin >> index)
    {
        index--;
        if ((index < 0) || (index >= n) || (num[index] == -1))
            cout << "invalid" << endl;
        else
        {
            num[index] = -1;
            len--;
            output(num, len, n);
        }
    }
    delete[] num;
    return 0;
}