#include <stdio.h>
#include <iostream>

int main() {
    int n;
    scanf("%d", &n);
    int tmp=0;
    for (int i=1; i<=n; i++) {
        for (int j=n-i; j>0; j--) printf(" ");
        for (int k=1; k<=2*i-1; k++) {
            printf("%d", tmp);
            tmp += 1;
            if (tmp==10) tmp = 0;
        }
        printf("\n");
    }
    system("pause");
    return 0;
}