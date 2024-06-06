#include <stdio.h>
#include <iostream>

#define N 100

int main()
{
    char str1[N], str2[N], str3[N];
    scanf("%s\n%s", &str1, &str2);
    char *ptr1 = str1, *ptr2 = str2;
    int len1, len2;
    len1 = len2 = 0;
    for (int i = 0; str1[i]; i++)
    {
        str3[i] = str1[i];
        len1++;
    }
    for (int i = 0; str2[i]; i++)
    {
        str3[len1 + i] = str2[i];
        len2++;
    }
    str3[len1 + len2] = 0;
    printf("%s", str3);
    system("pause");
    return 0;
}