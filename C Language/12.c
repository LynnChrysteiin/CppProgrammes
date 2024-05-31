#include <stdio.h>

int main() {
    int n, total=1;
    while (scanf("%d", &n)!=EOF) {
        for (int i=1; i<=n; i++) {
            total *= i;
        }
        printf("%d", total);
    }
    return 0;
}