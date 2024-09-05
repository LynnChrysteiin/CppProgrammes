#include <stdio.h>
#include <math.h>

int find_min_dist(int *L1, int *L2, int *L3, int l1, int l2, int l3, int *ans)
{
    int min = 0x7fffffff;
    int dist;
    for (int i = 0; i < l1; i++)
    {
        for (int j = 0; j < l2; j++)
        {
            for (int k = 0; k < l3; k++)
            {
                dist = abs(L1[i] - L2[j]) + abs(L2[j] - L3[k]) + abs(L3[k] - L1[i]);
                if (dist < min)
                {
                    min = dist;
                    ans[0] = L1[i];
                    ans[1] = L2[j];
                    ans[2] = L3[k];
                }
            }
        }
    }
    return min;
}

int main()
{
    int L1[3] = {-1, 0, 9};
    int L2[4] = {-25, -10, 10, 11};
    int L3[5] = {2, 9, 17, 30, 41};
    int ans[3] = {0};
    int res = find_min_dist(L1, L2, L3, 3, 4, 5, ans);
    printf("%d\n", res);
    for (int i = 0; i < 3; i++)
        printf("%d ", ans[i]);
    printf("\n");
    return 0;
}