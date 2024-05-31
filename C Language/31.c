#include <stdio.h>
#include <iostream>

int get_dif(int array[], int n) {
    int max = 0, min = 100000;
    for (int i = 0; i < n; i++) {
        if (array[i] > max)
            max = array[i];
        if (array[i] < min )
            min = array[i];
    }
    return max - min;
}

int main() {
    int m, res;
    scanf("%d", &m);
    int num[m];
    for (int i = 0; i < m; i++)
        scanf("%d", num + i);
    res = get_dif(num, m);
    printf("%d", res);
    system("pause");
    return 0;
}