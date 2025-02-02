#include <stdio.h>

#define N 100

int main()
{
    char str[N];
    scanf("%s", &str);
    int n;
    scanf("%d", &n);
    char *ptr = str;
    int len = 0;
    for (; (*ptr) && (*ptr == '*'); *ptr++)
        len++;
    if (len > n)
        for (int i = 0; i < n; i++)
            printf("*");
    else
        ptr -= len;
    while (*ptr)
        printf("%c", *ptr++);
    return 0;
}