#include <iostream>
using namespace std;

int main()
{
    int *a[] = {
        NULL,
        new int(0),
        new int(0),
        new int[6]
    };
    *a[2] = 123;
    a[3][5] = 456;
    if (!a[0])
    {
        cout << *a[2] << "," << a[3][5];
    }
    system("pause");
    return 0;
}