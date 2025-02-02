#include <stdio.h>

int get_amount(int array[], int n, int result[])
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (array[i] < 60)
        {
            result[count] = array[i];
            count++;
        }
    }
    return count;
}

int main()
{
    int m;
    scanf("%d", &m);
    int num[m];
    for (int i = 0; i < m; i++)
        scanf("%d", num + i);
    int result[m];
    int count = get_amount(num, m, result);
    for (int i = 0; i < count; i++)
        printf("%d ", result[i]);
    return 0;
}