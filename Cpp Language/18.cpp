#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;
const int MAX = 110;
class CHugeInt
{
    // --- fill in your code here ---
private:
    char value[210];

public:
    CHugeInt(const char *s)
    {
        strcpy(value, s);
    }
    CHugeInt(int n)
    {
        sprintf(value, "%d", n);
    }
    ~CHugeInt() = default;
    CHugeInt operator+(const CHugeInt &a) const
    {
        int len1 = strlen(this->value);
        int len2 = strlen(a.value);
        int len = len1 > len2 ? len1 : len2;
        int carry = 0;
        char *result = new char[len + 2];
        result[len + 1] = '\0';
        for (int i = 0; i < len; i++)
        {
            int num1 = i < len1 ? this->value[len1 - i - 1] - '0' : 0;
            int num2 = i < len2 ? a.value[len2 - i - 1] - '0' : 0;
            int sum = num1 + num2 + carry;
            carry = sum / 10;
            result[len - i] = sum % 10 + '0';
        }
        if (carry)
        {
            result[0] = carry + '0';
            return CHugeInt(result);
        }
        else
        {
            return CHugeInt(result + 1);
        }
    }
    CHugeInt operator+(int n)
    {
        CHugeInt a(n);
        return *this + a;
    }
    friend CHugeInt operator+(int n, CHugeInt &a)
    {
        CHugeInt b(n);
        return b + a;
    }
    CHugeInt operator+=(int n)
    {
        CHugeInt a(n);
        *this = *this + a;
        return *this;
    }
    CHugeInt &operator++()
    {
        *this += 1;
        return *this;
    }
    CHugeInt operator++(int)
    {
        CHugeInt temp = *this;
        *this += 1;
        return temp;
    }
    friend ostream &operator<<(ostream &os, const CHugeInt &a)
    {
        os << a.value;
        return os;
    }
    // ---
};
int main()
{
    char s[210];
    int n;

    while (cin >> s >> n)
    {
        CHugeInt a(s);
        CHugeInt b(n);

        cout << a + b << endl;
        cout << n + a << endl;
        cout << a + n << endl;
        b += n;
        cout << ++b << endl;
        cout << b++ << endl;
        cout << b << endl;
    }
    return 0;
}