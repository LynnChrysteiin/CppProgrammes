/*
使用数组编程：
一群学生排成一行，输入一个学号，请确定该学号学生所在的位置。
*/

#include <iostream>
using namespace std;

void search(int *num, int n, int token)
{
    int i;
    for (i = 0; i < n; ++i)
    {
        if (num[i] == token)
        {
            cout << i + 1 << endl;
            return;
        }
    }
    cout << "no" << endl;
    return;
}

int main()
{
    int n;
    cin >> n;
    int *num = new int[n];
    for (int i = 0; i < n; ++i)
        cin >> num[i];
    int token;
    while (cin >> token)
    {
        search(num, n, token);
    }
    delete[] num;
    return 0;
}