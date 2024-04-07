/* GHIȚĂ Andrei-Iulian - 324CB */
#ifndef _TASKS_H_
#define _TASKS_H_

#include <stdio.h>

#include "list.h"

/* UPDATE TASKS */                              /* Str Value */
#define ML "MOVE_LEFT"          // 1                705
#define MR "MOVE_RIGHT"         // 2                788
#define W "WRITE"               // 3    <C>         395
#define CC "CLEAR_CELL"         // 4                742
#define CA "CLEAR_ALL"          // 5                671
#define IL "INSERT_LEFT"        // 6    <C>         863
#define IR "INSERT_RIGHT"       // 7    <C>         946

/* SEARCH TASKS */
#define SRCH "SEARCH"           // 8    <C>         438
#define SRCHL "SEARCH_LEFT"     // 9    <C>         832
#define SRCHR "SEARCH_RIGHT"    // 10   <C>         915

/* QUERY TASKS */
#define SC "SHOW_CURRENT"       // 11
#define SH "SHOW"               // 12
#define SW "SWITCH"             // 13

#define EXEC "EXECUTE"          // 14

/* TASKS / FUNCTIONS' HEADERS */
void moveLeft(TList train, TList* t);
void moveRight(TList train, TList* t);
void clearCell(TList* t);
void clearAll(TList train, TList* t);
int insertLeft(TList* t, char *str);
void insertRight(TList* t, char *str);

int search(TList* current, char *str);
int searchLeft(TList* current, char *str);
int searchRight(TList* current, char *str);

void showTrain(TList train, TList current, FILE* fout);
int execute(char *line);

#endif
