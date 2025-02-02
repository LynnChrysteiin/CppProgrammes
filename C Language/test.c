#include <stdio.h>
#define N 256

int main()
{
    char str[N];
    while (scanf("%s", str) != EOF)
    {
        int count = 0;
        char *ptr = str;
        while (*ptr)
        {
            if (('0' <= *ptr) && (*ptr <= '9'))
            {
                int num = *ptr - 48;
                for (int i = 0; i <= num; i++)
                {
                    if (count == 3)
                    {
                        printf(" ");
                        count = 0;
                    }
                    printf("%c", *(ptr+1));
                    count++;
                }
                ptr += 2;
            }
            else if (('a' <= *ptr) && (*ptr <= 'z') || (*ptr == '@'))
            {
                if (count == 3)
                {
                    printf(" ");
                    count = 0;
                }
                printf("%c", *ptr++);
                count++;
            }
        }
        printf("\n");
    }
    return 0;
}