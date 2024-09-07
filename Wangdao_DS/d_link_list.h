#ifndef _D_LINK_LIST_H_
#define _D_LINK_LIST_H_

#include <stdio.h>
#include <stdlib.h>

// Ë«Á´±í

typedef struct DLNode
{
    int data;
    DLNode *prev;
    DLNode *next;
    int freq;
} DLNode;

typedef DLNode *DLinkList;

void init_list(DLinkList &H, DLinkList &T)
{
    H = (DLNode *)malloc(sizeof(DLNode));
    T = (DLNode *)malloc(sizeof(DLNode));
    H->prev = NULL;
    H->next = T;
    T->prev = H;
    T->next = NULL;
}

void add_node_by_head(DLinkList &H, int x)
{
    DLNode *p = (DLNode *)malloc(sizeof(DLNode));
    p->data = x;
    p->freq = 0;
    p->prev = H;
    H->next->prev = p;
    p->next = H->next;
    H->next = p;
}

void create_list(DLinkList &H, DLinkList &T, int *L, int n)
{
    init_list(H, T);
    for (int i = n - 1; i >= 0; i--)
        add_node_by_head(H, L[i]);
}

void print_list(DLinkList H, DLinkList T)
{
    DLNode *p = H->next;
    printf("NULL<-HEAD<->");
    while (p != T)
    {
        printf("[%d:%d]<->", p->data, p->freq);
        p = p->next;
    }
    printf("TAIL->NULL\n");
}

#endif // !_D_LINK_LIST_H_
