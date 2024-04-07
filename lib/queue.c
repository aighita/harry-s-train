/* GHIȚĂ Andrei-Iulian - 324CB */
#include "../include/queue.h"

TQueue* initQ() {
    TQueue* q;
    q = (TQueue*) malloc(sizeof(TQueue));
    if ( ! q ) return NULL;
    q->head = NULL;
    q->tail = NULL;
    return q;
}

TTask allocPosition(char *line, char *ch) {
    TTask newTask = (TTask) malloc(sizeof(TPosition));
    if ( ! newTask ) return NULL;
    newTask->task = malloc(20 * sizeof(char));
    newTask->s = malloc(20 * sizeof(char));
    return newTask;
}

int enqueueTask(TQueue* q, char *line, char *ch) {
    TTask newTask = allocPosition(line, ch);
    if ( ! newTask ) return 0;
    strcpy(newTask->task, line);
    strcpy(newTask->s, ch);
    newTask->next = NULL;
    newTask->prev = NULL;
    if (q->head == NULL & q->tail == NULL) {
        q->head = newTask;
        q->tail = newTask;
    } else {
        q->tail->next = newTask;
        newTask->prev = q->tail;
        q->tail = q->tail->next;
    }
    return 1;
}

int enqueueTask2(TQueue* q, char *line, char *ch) {
    TTask newTask = allocPosition(line, ch);
    if ( ! newTask ) return 0;
    strcpy(newTask->task, line);
    strcpy(newTask->s, ch);
    newTask->next = NULL;
    newTask->prev = NULL;
    if (q->head == NULL & q->tail == NULL) {
        q->head = newTask;
        q->tail = newTask;
    } else {
        q->head->prev = newTask;
        newTask->next = q->head;
        q->head = q->head->prev;
    }
    return 1;
}

int dequeueTask(TQueue* q, char *line, char *s) {
    if (q->head == NULL) return 0;
    TTask dQ = q->head;
    if (q->head == q->tail) {
        q->head = NULL;
        q->tail = NULL;
    } else {
        q->head = q->head->next;
    }
    strcpy(line, dQ->task);
    strcpy(s, dQ->s);
    free(dQ->task);
    free(dQ->s);
    free(dQ);
    return 1;
}

int dequeueTaskSwitch(TQueue* q, char *line, char *s) {
    if (q->tail == NULL) return 0;
    TTask dQ = q->tail;
    if (q->head == q->tail) {
        q->head = NULL;
        q->tail = NULL;
    } else {
        q->tail = q->tail->prev;
    }
    strcpy(line, dQ->task);
    strcpy(s, dQ->s);
    free(dQ->task);
    free(dQ->s);
    free(dQ);
    return 1;
}

void printQueue(TQueue* q) {
    TTask t = q->head;
    while (t != NULL) {
        printf("[%s :%s]  ", t->task, t->s);
        t = t->next;
    }
    printf("\n");
}

void destroyQueue(TQueue* q) {
    TTask aux = q->head;
    TTask t = q->head;
    while(t != NULL) {
        aux = t;
        t = t->next;
        free(aux->task);
        free(aux->s);
        free(aux);
    }
    q->head = t;
    q->tail = t;
    free(q->head);
    free(q->tail);
    free(q);
}
