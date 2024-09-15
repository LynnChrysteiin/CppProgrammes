#include <stdio.h>

bool check_legal_seq(int seq[])
{
    int cnt = 0;
    for (int i = 0; i < sizeof(seq); i++)
    {
        if (seq[i] == 1)
            cnt++;
        else
            cnt--;
        if (cnt < 0)
            return false;
    }
    if (cnt == 0)
        return true;
    else
        return false;
}

int main()
{
    int n = 8;
    int seq[n] = {1, 0, 1, 1, 0, 0, 1, 0};
    printf(check_legal_seq(seq) ? "LEGAL!\n" : "ILLEGAL!\n");
    return 0;
}