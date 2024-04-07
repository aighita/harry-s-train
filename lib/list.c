/* GHIȚĂ Andrei-Iulian - 324CB */
#include "../include/list.h"

TList allocNode(char *info) {
    TList node = (TList) malloc(sizeof(TNode));
    if (node) {
        node->info = *info;
        node->next = NULL;
    }
    return node;
}

TList initList() {
    TList node = (TList) malloc(sizeof(TNode));
    if (node) {
        node->info = *"\0";
        node->next = allocNode("#");
        node->prev = node->next;
        node->next->next = node;
        node->next->prev = node;
    }
    return node;
}

void destroyList(TList* train) {
    TList current = (*train)->next;
    TList aux = current;
    while (current->info != *"\0") {
        aux = current;
        current = current->next;
        free(aux);
    }
    free(*train);
}
