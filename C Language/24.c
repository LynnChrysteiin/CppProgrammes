#include <stdio.h>
#include <iostream>

int main() {
    int m, n, max=-100000000, tmp;
    scanf("%d %d", &m, &n);
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            scanf("%d", &tmp);
            if (tmp>max) max=tmp;
        }
    }
    printf("%d", max);
    system("pause");
    return 0;
}