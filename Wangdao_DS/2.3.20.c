#include "link_list.h"

void rearrange_list(LinkList L)
{
    if (L == NULL || L->next == NULL)
        return;

    // ʹ�ÿ���ָ���ҵ��е�
    LNode *slow = L, *fast = L;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // �ָ�����
    LNode *secondHalf = slow->next;
    slow->next = NULL;

    // ��ת�ڶ�������
    LNode *prev = NULL, *current = secondHalf;
    while (current != NULL)
    {
        LNode *nextTemp = current->next;
        current->next = prev;
        prev = current;
        current = nextTemp;
    }
    secondHalf = prev;

    // �ϲ���������
    LNode *firstHalf = L->next;
    while (firstHalf != NULL && secondHalf != NULL)
    {
        LNode *temp1 = firstHalf->next;
        LNode *temp2 = secondHalf->next;

        firstHalf->next = secondHalf;
        secondHalf->next = temp1;

        firstHalf = temp1;
        secondHalf = temp2;
    }
}

int main()
{
    int n = 10;
    int A[n] = {0, 2, 4, 6, 8, 9, 7, 5, 3, 1};
    LinkList L = create_list(A, n);
    rearrange_list(L);
    print_list(L);
    return 0;
}