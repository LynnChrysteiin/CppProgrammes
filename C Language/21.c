#include <stdio.h>
#include <iostream>

int main() {
    int n;
    scanf("%d", &n);
    int array[n];
    for (int i=0; i<n; i++)
        scanf("%d", array+i);
    for (int i=n-1; i>0; i--) {
        for (int j=0; j<i; j++) {
            int tmp;
            if (array[j]>array[j+1]) {
                tmp = array[j];
                array[j] = array[j+1];
                array[j+1] = tmp;
            }
        }
    }
    for (int i=0; i<n; i++) {
        (i==n-1) ? printf("%d", array[i]) : printf("%d ", array[i]);
    }
    system("pause");
    return 0;
}