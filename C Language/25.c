#include <stdio.h>
#include <iostream>

#define N 100

int main()
{
    char str1[N], str2[N];
    scanf("%s", &str1);
    scanf("%s", &str2);
    int i, len1, len2;
    i = len1 = len2 = 0;
    while (str1[i] != '\0')
    {
        len1++;
        i++;
    }
    i = 0;
    while (str2[i] != '\0')
    {
        len2++;
        i++;
    }
    (len1 >= len2) ? printf("%s", str1) : printf("%s", str2);
    system("pause");
    return 0;
}