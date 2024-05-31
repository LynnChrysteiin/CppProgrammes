#include <stdio.h>

int main() {
    int a;
    while(scanf("%d", &a)!=EOF) {
        int tmp, total=0;
        while(a>0) {
            tmp = a/10;
            total += a-tmp*10;
            a = tmp;
        }
        printf("%d", total);
    }
    return 0;
}