/*
 * output:
 * destructor B
 * destructor A
 */

#include <iostream>
using namespace std;

class A
{
public:
    A() {}
    // --- fill in your code here ---
    virtual ~A() { cout << "destructor A" << endl; }
    // ---
};
class B : public A
{
public:
    ~B() { cout << "destructor B" << endl; }
};
int main()
{
    A *pa;
    pa = new B;
    delete pa;
    return 0;
}