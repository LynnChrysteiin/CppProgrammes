#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int array[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &array[i]);
    int isTure = 1;
    for (int i = 0; i < n / 2; i++)
    {
        if (array[i] != array[n - i - 1])
        {
            isTure = 0;
        }
    }
    if (isTure)
        printf("yes");
    else
        printf("no");
    return 0;
}