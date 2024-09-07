#ifndef _CIR_D_LINK_LIST_H_
#define _CIR_D_LINK_LIST_H_

#include <stdio.h>
#include <stdlib.h>

// Ñ­»·Ë«Á´±í

typedef struct CDLNode
{
    int data;
    CDLNode *prev;
    CDLNode *next;
} CDLNode;

typedef CDLNode *CDLinkList;

void init_list(CDLinkList &L)
{
    L = (CDLNode *)malloc(sizeof(CDLNode));
    L->prev = L;
    L->next = L;
}

void add_node_by_head(CDLinkList &L, int x)
{
    CDLNode *p = (CDLNode *)malloc(sizeof(CDLNode));
    p->data = x;
    p->prev = L;
    L->next->prev = p;
    p->next = L->next;
    L->next = p;
}

CDLinkList create_list(int *L, int n)
{
    CDLinkList list;
    init_list(list);
    for (int i = n - 1; i >= 0; i--)
        add_node_by_head(list, L[i]);
    return list;
}

void print_list(CDLinkList L)
{
    CDLNode *p = L->next;
    printf("HEAD->");
    while (p != L)
    {
        printf("%d->", p->data);
        p = p->next;
    }
    printf("HEAD\n");
}

#endif // !_CIR_D_LINK_LIST_H_