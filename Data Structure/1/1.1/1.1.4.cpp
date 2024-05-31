/*
使用数组编程：
一群学生排成一行，输入一个位置和一个学号，在该位置插入一个学生。
第一个学生的位置为1，第n个学生的位置为n。
*/

#include <iostream>
using namespace std;

const int MAXN = 100;

void insert(int *stu, int len, int index, int num)
{
    if (index == len)
        stu[len] = num;
    else
    {
        int i;
        for (i = len + 1; i > index; --i)
        {
            stu[i] = stu[i - 1];
        }
        stu[index] = num;
    }
}

int main()
{
    int n;
    cin >> n;
    int *stu = new int[MAXN];
    int i;
    for (i = 0; i < n; ++i)
        cin >> stu[i];
    int index, num;
    int len = n;
    while (cin >> index >> num)
    {
        --index;
        if (index < 0 || index > len)
        {
            cout << "invalid" << endl;
        }
        else
        {
            insert(stu, len, index, num);
            ++len;
            cout << stu[0];
            for (i = 1; i < len; ++i)
                cout << " " << stu[i];
            cout << endl;
        }
    }
    delete[] stu;
    return 0;
}