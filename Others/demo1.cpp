#include <iostream>

class MyClass
{
public:
    ~MyClass()
    {
        std::cout << "Destructor called" << std::endl;
    }
};

int main()
{
    MyClass *p1 = new MyClass[2];
    MyClass *p2 = new MyClass;
    MyClass obj;
    delete[] p1;
    return 0;
}
