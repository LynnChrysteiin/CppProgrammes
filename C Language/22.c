#include <stdio.h>
#include <iostream>

int main() {
    int n;
    scanf("%d", &n);
    int array[n], isSame[n];
    for (int i=0; i<n; i++) {
        scanf("%d", array+i);
        isSame[i] = 0;
    }
    int num, len=n;
    scanf("%d", &num);
    for (int i=0; i<n; i++) {
        if (array[i]==num) {
            isSame[i] = 1;
            len--;
        }
    }
    int isEmpty = 1, now=0;
    for (int i=0; i<n; i++) {
        if (isSame[i]!=1) {
            printf("%d", array[i]);
            isEmpty = 0;
            now++;
            if ((now<len)&&(isEmpty!=1))
                printf(" ");
        }
    }
    if (isEmpty) {
        printf("Empty array!");
    }
    system("pause");
    return 0;
}