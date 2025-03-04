#include <cstdlib>
#include <iostream>
using namespace std;

int strlen(const char *s)
{
    int i = 0;
    for (; s[i]; ++i)
        ;
    return i;
}
void strcpy(char *d, const char *s)
{
    int i = 0;
    for (i = 0; s[i]; ++i)
        d[i] = s[i];
    d[i] = 0;
}
int strcmp(const char *s1, const char *s2)
{
    for (int i = 0; s1[i] && s2[i]; ++i)
    {
        if (s1[i] < s2[i])
            return -1;
        else if (s1[i] > s2[i])
            return 1;
    }
    return 0;
}
void strcat(char *d, const char *s)
{
    int len = strlen(d);
    strcpy(d + len, s);
}
class MyString
{
    // --- fill in your code here ---
private:
    char* str;
    int len;

public:
    MyString()
    {
        len = 0;
        str = new char[1];
        str[0] = 0;
    }
    MyString(const char *s)
    {
        len = strlen(s);
        str = new char[len + 1];
        strcpy(str, s);
    }
    ~MyString()
    {
        delete[] str;
    }
    MyString(const MyString &s)
    {
        len = s.len;
        str = new char[len + 1];
        strcpy(str, s.str);
    }
    MyString &operator=(const MyString &s)
    {
        if (this == &s)
            return *this;
        delete[] str;
        len = s.len;
        str = new char[len + 1];
        strcpy(str, s.str);
        return *this;
    }
    MyString operator+(const MyString &s)
    {
        MyString temp;
        temp.len = len + s.len;
        temp.str = new char[temp.len + 1];
        strcpy(temp.str, str);
        strcat(temp.str, s.str);
        return temp;
    }
    MyString operator+(const char *s)
    {
        MyString temp;
        temp.len = len + strlen(s);
        temp.str = new char[temp.len + 1];
        strcpy(temp.str, str);
        strcat(temp.str, s);
        return temp;
    }
    friend MyString operator+(const char *s, const MyString &s1)
    {
        MyString temp;
        temp.len = strlen(s) + s1.len;
        temp.str = new char[temp.len + 1];
        strcpy(temp.str, s);
        strcat(temp.str, s1.str);
        return temp;
    }
    MyString &operator+=(const MyString &s)
    {
        len += s.len;
        char *temp = new char[len + 1];
        strcpy(temp, str);
        strcat(temp, s.str);
        delete[] str;
        str = temp;
        return *this;
    }
    bool operator<(const MyString &s)
    {
        return strcmp(str, s.str) < 0;
    }
    bool operator==(const MyString &s)
    {
        return strcmp(str, s.str) == 0;
    }
    bool operator>(const MyString &s)
    {
        return strcmp(str, s.str) > 0;
    }
    char &operator[](int i)
    {
        return str[i];
    }
    friend ostream &operator<<(ostream &os, const MyString &s)
    {
        os << s.str;
        return os;
    }
    MyString operator()(int begin, int length)
    {
        MyString temp;
        temp.len = length;
        temp.str = new char[temp.len + 1];
        for (int i = 0; i < length; ++i)
            temp.str[i] = str[begin + i];
        temp.str[length] = 0;
        return temp;
    }
    // ---
};

int CompareString(const void *e1, const void *e2)
{
    MyString *s1 = (MyString *)e1;
    MyString *s2 = (MyString *)e2;
    if (*s1 < *s2)
        return -1;
    else if (*s1 == *s2)
        return 0;
    else if (*s1 > *s2)
        return 1;
}
int main()
{
    MyString s1("abcd-"), s2, s3("efgh-"), s4(s1);
    MyString SArray[4] = {"big", "me", "about", "take"};
    cout << "1. " << s1 << s2 << s3 << s4 << endl;
    s4 = s3;
    s3 = s1 + s3;
    cout << "2. " << s1 << endl;
    cout << "3. " << s2 << endl;
    cout << "4. " << s3 << endl;
    cout << "5. " << s4 << endl;
    cout << "6. " << s1[2] << endl;
    s2 = s1;
    s1 = "ijkl-";
    s1[2] = 'A';
    cout << "7. " << s2 << endl;
    cout << "8. " << s1 << endl;
    s1 += "mnop";
    cout << "9. " << s1 << endl;
    s4 = "qrst-" + s2;
    cout << "10. " << s4 << endl;
    s1 = s2 + s4 + " uvw " + "xyz";
    cout << "11. " << s1 << endl;
    qsort(SArray, 4, sizeof(MyString), CompareString);
    for (int i = 0; i < 4; i++)
        cout << SArray[i] << endl;
    // s1的从下标0开始长度为4的子串
    cout << s1(0, 4) << endl;
    // s1的从下标5开始长度为10的子串
    cout << s1(5, 10) << endl;
    return 0;
}