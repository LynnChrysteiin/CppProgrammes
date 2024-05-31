#include <stdio.h>
#include <math.h>
#include <iostream>

int main() {
    int n;
    scanf("%d", &n);
    int isPrime[n+1];
    for (int i=1; i<=n; i++){
        isPrime[i] = 1;
    }
    isPrime[0] = isPrime[1] = 0;
    for (int i=2; i<=sqrt(n); i++) {
        if (isPrime[i]) {
            for (int j=2*i; j<=n; j+=i)
                isPrime[j] = 0;
        }
    }
    int total = 0;
    for (int i=1; i<=n; i++) if (isPrime[i]) total += i;
    printf("%d", total);
    system("pause");
    return 0;
}