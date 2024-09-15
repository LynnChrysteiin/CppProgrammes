#include <stdio.h>

int find_ancestor(int *tree, int n, int i, int j)
{
    if (i > n || j > n || i < 0 || j < 0)
        return -1;
    while (i != j)
    {
        if (i > j)
            i = (i - 1) / 2;
        else
            j = (j - 1) / 2;
    }
    return tree[i];
}

int main()
{
    int tree[15] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    /*
     *           0
     *     1           2
     *  3    4      5      6
     * 7 8  9 10  11 12  13 14
     */
    int res = find_ancestor(tree, 15, 1, 14);
    printf("%d\n", res);
    return 0;
}