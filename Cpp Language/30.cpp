#include <iostream>
using namespace std;
class MyCin
{
private:
    bool fail = false;

public:
    MyCin() = default;
    ~MyCin() = default;

    template <class ElmeType>
    MyCin &operator>>(ElmeType &elem)
    {
        cin >> elem;
        if (elem == -1)
            fail = true;
        return *this;
    }
    operator bool() const
    {
        return !fail;
    }
};
int main()
{
    MyCin m;
    int n1, n2;
    while (m >> n1 >> n2)
        cout << n1 << " " << n2 << endl;
    return 0;
}