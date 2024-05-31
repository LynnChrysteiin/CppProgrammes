#include <stdio.h>
#include <iostream>

int main() {
    int a, b, x;
    scanf("%d %d %d", &a, &b, &x);
    int tmpMin = 0;
    int totalMin = (b-a)*60;
    for (int i=1; tmpMin<totalMin; tmpMin+=x, i++) { 
        int hour = tmpMin/60 + a;
        int minute = tmpMin%60;
        printf("%d ", i);
        if (hour < 10) printf("0");
        else ;
        printf("%d:", hour);
        if (minute < 10) printf("0");
        else ;
        printf("%d\n", minute);
    }
    system("pause");
    return 0;
}