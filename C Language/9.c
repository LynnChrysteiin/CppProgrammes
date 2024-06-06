#include <stdio.h>

int main()
{
    char ch;
    while (scanf("%c", &ch) != EOF)
    {
        if ((int)ch <= (12 + (int)'a'))
            printf("%c", (char)((int)ch + 1));
        else
            printf("%c\n", (char)((int)ch - 1));
    }
    return 0;
}