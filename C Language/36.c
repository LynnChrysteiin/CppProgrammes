#include <stdio.h>
#include <string.h>

#define N 10

typedef struct
{
    char name[10];
    int score;
} stu;

stu search_info(stu dt[], char *qst)
{
    stu res;
    for (int i = 0; i < N; i++)
    {
        if (strcmp(dt[i].name, qst) == 0)
        {
            strcpy(res.name, dt[i].name);
            res.score = dt[i].score;
            return res;
        }
    }
    strcpy(res.name, "");
    res.score = -1;
    return res;
}

int main()
{
    stu data[N] = {0};
    stu result;
    char quest[10];
    for (int i = 0; i < N; i++)
        scanf("%s%d", &data[i].name, &data[i].score);
    scanf("%s", quest);
    result = search_info(data, quest);
    printf("%s  %4d\n", result.name, result.score);
    return 0;
}