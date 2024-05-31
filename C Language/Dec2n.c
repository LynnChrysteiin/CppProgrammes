#include <stdio.h>
#include <string.h>
#include <iostream>
#define N 20

int main() {
    int num, n;
    while (scanf("%d %d", &num, &n) != EOF) {
        int result[N];
        int i = 0;
        while (num/n > 0) {
            int div = num/n;
            int rem = num%n;
            result[i] = rem;
            num = div;
            i++;
        }
        result[i] = num;
        for (int j = i; j >= 0; j--) {
            (result[j] < 10) ? printf("%d", result[j]) : printf("%c", result[j] - 10 + 'A');
        }
        printf("\n");
    }
    system("pause");
    return 0;
}