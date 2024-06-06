#include <stdio.h>
#include <iostream>

#define n 10

void input(int *a)
{
    int *p = a;
    for (int i = 0; i < n; i++)
        scanf("%d", p++);
}

void sort(int *a)
{
    int idx, tmp;
    for (int i = 0; i < n - 1; i++)
    {
        idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[idx])
                idx = j;
        }
        if (idx != i)
        {
            tmp = a[idx];
            a[idx] = a[i];
            a[i] = tmp;
        }
    }
}

void output(int *a)
{
    int *p = a;
    for (int i = 0; i < n; i++)
        printf("%d ", *p++);
}

int main()
{
    int a[n];
    input(a);
    sort(a);
    output(a);
    system("pause");
    return 0;
}