/*
输入
多组数据，每组一行，是两个不带空格的字符�??
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
    // --- fill in the blank ---
    void Copy(char *s)
    {
        if (p)
            delete[] p;
        p = new char[strlen(s) + 1];
        strcpy(p, s);
    }
    char *get() const
    {
        return p;
    }
    MyString(const MyString &s)
    {
        p = new char[strlen(s.get()) + 1];
        strcpy(p, s.get());
    }
    MyString &operator=(MyString &s)
    {
        if (p)
            delete[] p;
        p = new char[strlen(s.get()) + 1];
        strcpy(p, s.get());
        return *this;
    }
    MyString &operator=(const char *s)
    {
        if (p)
            delete[] p;
        p = new char[strlen(s) + 1];
        strcpy(p, s);
        return *this;
    }
    operator char *()
    {
        return p;
    }
    // ---
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