#include <stdio.h>
#include <iostream>

#define n 100

void cat(char *srcStr, char *dstStr)
{
    while (*srcStr != 0)
    {
        if (*dstStr != 0)
            dstStr++;
        else
        {
            while (*srcStr != 0)
                *dstStr++ = *srcStr++;
        }
    }
    *dstStr = 0;
}

int main()
{
    char a[n], b[n];
    scanf("%s%s", a, b);
    cat(a, b);
    printf("%s", b);
    system("pause");
    return 0;
}