#include <stdio.h>
#include <iostream>

int main() {
    int n;
    scanf("%d", &n);
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (i*j < 10) printf(" ");
            printf("  %d", i*j);
        }
        printf("\n");
    }
    printf("\n");

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=i; j++) {
            if (i*j < 10) printf(" ");
            printf("  %d", i*j);
        }
        printf("\n");
    }
    printf("\n");

    for (int i=1; i<=n; i++) {
        for (int j=2; j<=i; j++) {
            printf("    ");
        }
        for (int k=i; k<=n; k++) {
            if (i*k < 10) printf(" ");
            printf("  %d", i*k);
        }
        printf("\n");
    }
    printf("\n");

    system("pause");
    return 0;
}