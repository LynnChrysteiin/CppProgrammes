#include <iostream>
using namespace std;
class MyInt
{
    int nVal;

public:
    MyInt(int n) { nVal = n; }
    operator int() { return nVal; }
    MyInt &operator-(int n)
    {
        nVal -= n;
        return *this;
    }
};
int Inc(int n)
{
    return n + 1;
}
int main()
{
    int n;
    while (cin >> n)
    {
        MyInt objInt(n);                //nVal = n
        objInt - 2 - 1 - 3;             //nVal = n-2-1-3 = n-6
        cout << Inc(objInt);            //cout << nVal+1 = n-5
        cout << ",";
        objInt - 2 - 1;                 //nval = n-2-1-3-2-1 = n-9
        cout << Inc(objInt) << endl;    //cout << nVal+1 = n-8
    }
    return 0;
}