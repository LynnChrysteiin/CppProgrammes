#include <iostream>
#include <string.h>

#define N 10

typedef struct
{
    int id;
    int score;
} stu;

int select_highest(stu src[], stu res[])
{
    int max = 0;
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        if (src[i].score >= max)
        {
            max = src[i].score;
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (src[i].score == max)
        {
            res[count].id = src[i].id;
            res[count++].score = src[i].score;
        }
    }
    return count;
}

int main()
{
    stu srcData[N] = {0};
    stu resData[N] = {0};
    for (int i = 0; i < N; i++)
        scanf("%d%d", &srcData[i].id, &srcData[i].score);
    int num = select_highest(srcData, resData);
    for (int i = 0; i < num; i++)
        printf("%d  %4d\n", resData[i].id, resData[i].score);
    system("pause");
    return 0;
}