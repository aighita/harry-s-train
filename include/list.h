/* GHIȚĂ Andrei-Iulian - 324CB */
#ifndef _LIST_H_
#define _LIST_H_

#include <stdlib.h>

/* DOUBLY LINKED LIST */
typedef struct node {
    char info;
    struct node *prev, *next;
}TNode, *TList;

TList allocNode(char *info);
TList initList();
void destroyList(TList* train);

#endif
