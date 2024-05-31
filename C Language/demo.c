#include <stdio.h>
#include <string.h>
#include <iostream>
#define N 100

void init(int array[26]) {
    for (int i = 0; i < 26; i++)
        array[i] = 0;
}

int main() {
    char str[N];
    int times[26];
    while (scanf("%s", str) != EOF) {
        init(times);
        char *ptr = str;
        while (*ptr!='!') {
            (*ptr>=97) ? times[*ptr-97]++ : times[*ptr-65]++;
            ptr++;
        }
        for (int i = 0; i < 26; i++) {
            if (times[i]) printf("%c:%d\n", i+65, times[i]);
        }
    }
    system("pause");
    return 0;
}