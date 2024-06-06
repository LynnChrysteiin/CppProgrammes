#include <iostream>
using namespace std;

int main()
{
    int a, b, x;
    cin >> a >> b >> x;
    int tmpMin = 0;
    int totalMin = (b - a) * 60;
    for (int i = 1; tmpMin + x <= totalMin; tmpMin += x, i++)
    {
        int hour = tmpMin / 60 + a;
        int minute = tmpMin % 60;
        cout << i << " ";
        if (hour < 10)
            cout << "0";
        else
            ;
        cout << hour << ":";
        if (minute < 10)
            cout << "0";
        else
            ;
        cout << minute << endl;
    }
    system("pause");
    return 0;
}