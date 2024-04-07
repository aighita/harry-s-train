/* GHIȚĂ Andrei-Iulian - 324CB */
#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define _TASKS_QUEUE_

/* DOUBLY LINKED LIST */
typedef struct position {
    char *task;
    char *s;
    struct position *prev, *next;
} TPosition, *TTask;

/* QUEUE */
typedef struct queue {
    TTask head, tail;
} TQueue;

TQueue* initQ();
int enqueueTask(TQueue* q, char *line, char *ch);
int enqueueTask2(TQueue* q, char *line, char *ch);
int dequeueTask(TQueue* q, char *line, char *s);
int dequeueTaskSwitch(TQueue* q, char *line, char *s);
void destroyQueue(TQueue* q);
void printQueue(TQueue* q);

#endif
