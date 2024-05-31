#include <iostream>
#include <cstring>
using namespace std;

class Array2
{
private:
    int **p;
    int row, column;

public:
    Array2() {p = NULL; row = 0; column = 0;}
    Array2(int r, int c) : row(r), column(c) {
        p = new int *[row];
        for (int i = 0; i < row; i++)
            p[i] = new int[column];
    }
    ~Array2()
    {
        if (p)
        {
            for (int i = 0; i < row; i++)
                delete[] p[i];
            delete[] p;
        }
    }
    int *operator[](int i) { return p[i]; }
    int &operator()(int i, int j) { return p[i][j]; }
    Array2 &operator=(const Array2 &a)
    {
        if (p)
        {
            for (int i = 0; i < row; i++)
                delete[] p[i];
            delete[] p;
        }
        row = a.row;
        column = a.column;
        p = new int *[row];
        for (int i = 0; i < row; i++)
        {
            p[i] = new int[column];
            memcpy(p[i], a.p[i], column * sizeof(int));
        }
        return *this;
    }
};

int main()
{
    Array2 a(3, 4);
    int i, j;
    for (i = 0; i < 3; ++i)
        for (j = 0; j < 4; j++)
            a[i][j] = i * 4 + j;
    for (i = 0; i < 3; ++i)
    {
        for (j = 0; j < 4; j++)
        {
            cout << a(i, j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b;
    b = a;
    for (i = 0; i < 3; ++i)
    {
        for (j = 0; j < 4; j++)
        {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}