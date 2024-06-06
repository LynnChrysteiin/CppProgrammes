#include <stdio.h>

int main()
{
    int score[10];
    double total = 0;
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &score[i]);
        total += score[i];
    }
    double avg = total / 10;
    int stu = 0;
    for (int i = 0; i < 10; i++)
        if (score[i] > avg)
            stu++;
    printf("%d", stu);
    return 0;
}