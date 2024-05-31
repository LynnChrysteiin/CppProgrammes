/*
输入
多组数据，每组一行，是两个不带空格的字符串
输出
对每组数据，先输出一行，打印输入中的第一个字符串三次
然后再输出一行，打印输入中的第二个字符串三次
*/

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class MyString
{
    char *p;

public:
    MyString(const char *s)
    {
        if (s)
        {
            p = new char[strlen(s) + 1];
            strcpy(p, s);
        }
        else
            p = NULL;
    }
    ~MyString()
    {
        if (p)
            delete[] p;
    }
    void Copy(const char *s)
    {
        if (p)
            delete[] p;
        if (s)
        {
            p = new char[strlen(s) + 1];
            strcpy(p, s);
        }
        else
            p = NULL;
    }
    friend ostream &operator<<(ostream &os, const MyString &s)
    {
        if (s.p)
            os << s.p;
        return os;
    }
    MyString &operator=(const char *s)
    {
        if (p != s)
        {
            if (p)
                delete[] p;
            if (s)
            {
                p = new char[strlen(s) + 1];
                strcpy(p, s);
            }
            else
                p = NULL;
        }
        return *this;
    }
    MyString &operator=(const MyString &s)
    {
        if (this != &s)
        {
            if (p)
                delete[] p;
            if (s.p)
            {
                p = new char[strlen(s.p) + 1];
                strcpy(p, s.p);
            }
            else
                p = NULL;
        }
        return *this;
    }
};

int main()
{
    char w1[200], w2[100];
    while (cin >> w1 >> w2)
    {
        MyString s1(w1), s2 = s1;
        MyString s3(NULL);
        s3.Copy(w1);
        cout << s1 << "," << s2 << "," << s3 << endl;

        s2 = w2;
        s3 = s2;
        s1 = s3;
        cout << s1 << "," << s2 << "," << s3 << endl;
    }
}