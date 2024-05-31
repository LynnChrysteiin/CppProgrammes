#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class Complex
{
private:
    double r, i;

public:
    void Print()
    {
        cout << r << "+" << i << "i" << endl;
    }
    Complex() {}
    Complex(const char *s)
    {
        char *str = strcpy(new char[strlen(s) + 1], s);
        r = atoi(strtok(str, "+"));
        i = atoi(strtok(NULL, "i"));
        delete[] str;
    }
};

int main()
{
    Complex a;
    a = "3+4i";
    a.Print();
    a = "5+6i";
    a.Print();
    system("pause");
    return 0;
}