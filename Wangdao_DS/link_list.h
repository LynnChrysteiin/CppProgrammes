#ifndef _LINK_LIST_H_
#define _LINK_LIST_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct LNode
{
    int data;
    LNode *next;
} LNode;

typedef LNode *LinkList;

void init_list(LinkList &L)
{
    L = (LNode *)malloc(sizeof(LNode));
    L->next = NULL;
}

void add_node_by_head(LinkList &L, int x) // �� L �� L->next ֮�����ڵ�, ���� L ָ���²���Ľڵ�
{
    LNode *p = (LNode *)malloc(sizeof(LNode));
    p->data = x;
    p->next = L->next;
    L->next = p;
}

void add_node_by_tail(LNode *&tail, int x) // �� tail ָ��ڵ����ӽڵ�, ���� tail ָ���²���Ľڵ�
{
    LNode *p = (LNode *)malloc(sizeof(LNode));
    p->data = x;
    p->next = NULL;
    tail->next = p;
    tail = p;
}

void delete_node(LNode *pre)
{
    if (pre->next)
    {
        LNode *cur = pre->next;
        pre->next = cur->next;
        free(cur);
    }
}

LinkList create_list(int *L, int n)
{
    LinkList list;
    init_list(list);
    for (int i = n - 1; i >= 0; i--)
        add_node_by_head(list, L[i]);
    return list;
}

void print_list(LinkList L)
{
    LNode *p = L->next;
    printf("HEAD->");
    while (p)
    {
        printf("%d->", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

#endif // !_LINK_LIST_H_
