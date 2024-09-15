#include "link_list.h"
#include "seq_stack.h"

bool check_symmetry(LinkList L, int n)
{
    SeqStack S;
    init_stack(S);
    LNode *p = L->next;
    for (int i = 0; i < n / 2 ; i++) //ǰ������ѹջ
    {
        push(S, p->data);
        p = p->next;
    }
    if (n % 2 != 0) // �� n Ϊ����, �������м���
        p = p->next;
    int tmp;
    for (int i = 0; i < n / 2; i++) // ������������鲢��ջ
    {
        pop(S, tmp);
        if (tmp != p->data)
            return false;
        else
            p = p->next;
    }
    return true;
}

int main()
{
    int m = 9;
    int n = 10;
    int A[m] = {0, 1, 2, 3, 4, 3, 2, 1, 0};
    int B[n] = {0, 1, 2, 3, 4, 4, 3, 2, 1, 0};
    LinkList LA = create_list(A, m);
    LinkList LB = create_list(B, n);
    bool resA = check_symmetry(LA, m);
    bool resB = check_symmetry(LB, n);
    printf(resA ? "TRUE!\n" : "FALSE!\n");
    printf(resB ? "TRUE!\n" : "FALSE!\n");
    return 0;
}