/* GHIȚĂ Andrei-Iulian - 324CB */
#include "../include/tasks.h"
#include "../include/functions.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void showTrain(TList train, TList current, FILE* fout) {
    TList wagon = train->next; 
    while (wagon->info != *"\0") {
        if (wagon == current) {
            fprintf(fout, "|%c|", wagon->info);
        } else {
            fprintf(fout, "%c", wagon->info);
        }
        wagon = wagon->next;
    }
    fprintf(fout, "\n");
}

int execute(char *line) {
    return calculateStringValue(line);
}

void moveRight(TList train, TList* t) {
    if ((*t)->next->info == *"\0") {
        TList aux = allocNode("#");
        aux->next = (*t)->next;
        aux->next->prev = aux;
        aux->prev = (*t);
        (*t)->next = aux;
    }
    (*t) = (*t)->next;
}

void moveLeft(TList train, TList* t) {
    if ((*t)->prev->info != *"\0") {
        (*t) = (*t)->prev;
    } else {
        (*t) = (*t)->prev->prev;
    }
}

void clearCell(TList* t) {
    if ((*t)->prev == (*t)->next) {
        (*t)->info = *"#";
    } else {
        TList aux = (*t);
        (*t)->prev->next = (*t)->next;
        (*t)->next->prev = (*t)->prev;
        if ((*t)->prev->info == *"\0") {
            (*t) = (*t)->prev->prev;
        } else {
            (*t) = (*t)->prev;
        }
        free(aux);
    }
}

void clearAll(TList train, TList* t) {
    TList aux;
    (*t) = train->prev;
    while ((*t) != train->next) {
        aux = (*t);
        (*t)->next->prev = (*t)->prev;
        (*t)->prev->next = (*t)->next;
        (*t) = (*t)->prev;
        free(aux);
    }
    (*t)->info = *"#";
}

int insertLeft(TList* t, char *str) {
    if ((*t)->prev->info == *"\0") {
        return 0;
    }
    TList aux = allocNode(str);
    aux->next = (*t);
    aux->prev = (*t)->prev;
    (*t)->prev->next = aux;
    (*t)->prev = aux;
    (*t) = (*t)->prev;
    return 1;
}

void insertRight(TList* t, char *str) {
    TList aux = allocNode(str);
    aux->prev = (*t);
    aux->next = (*t)->next;
    (*t)->next->prev = aux;
    (*t)->next = aux;
    (*t) = (*t)->next;
}

int search(TList* t, char *str) {
    TList aux = (*t);
    do {
        if (aux->info == str[0]) {
            TList pos = aux;
            int k = 1;
            for (int i = 1; i < strlen(str); i++) {
                pos = pos->next;
                if (pos->info == *"\0") {
                    i--; continue;
                }
                if (pos->info != str[i]) {
                    k = 0;
                    break;
                }
            }
            if (k == 1) {
                (*t) = aux;
                return 1;
            }
        }
        aux = aux->next;
    } while (aux != (*t));
    return 0;
}

int searchLeft(TList* t, char *str) {
    TList aux = (*t);
    while (aux->info != *"\0") {
        if (aux->info == str[0]) {
            int k = 1;
            TList pos = aux;
            for (int i = 1; i < strlen(str); i++) {
                pos = pos->prev;
                if (pos->info != str[i]) {
                    k = 0;
                    break;
                }
            }
            if (k == 1) {
                (*t) = pos;
                return 1;
            }
        }
        aux = aux->prev;
    }
    return 0;
}

int searchRight(TList* t, char *str) {
    TList aux = (*t);
    while (aux->info != *"\0") {
        if (aux->info == str[0]) {
            int k = 1;
            TList pos = aux;
            for (int i = 1; i < strlen(str); i++) {
                pos = pos->next;
                if (pos->info != str[i]) {
                    k = 0;
                    break;
                }
            }
            if (k == 1) {
                (*t) = pos;
                return 1;
            }
        }
        aux = aux->next;
    }
    return 0;
}
