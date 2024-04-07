/* GHIȚĂ Andrei-Iulian - 324CB */
#include "../include/main.h"
#include "../include/functions.h"

void reset_output_file() {
    int f = open(PATH_OUT, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (f == -1) {
        printf("Error opening output file");
        exit(EXIT_FAILURE);
    }
    close(f);
}

FILE* open_file_in() {
    FILE* f = fopen(PATH_IN, "r");
    if (f == NULL) {
        printf("Error opening input file");
        exit(EXIT_FAILURE);
    }
    return f;
}

FILE* open_file_out() {
    FILE* f = fopen(PATH_OUT, "a");
    if (f == NULL) {
        printf("Error opening output file");
        exit(EXIT_FAILURE);
    }
    return f;
}

bool nextIsChar(char *line) {
    if (strcmp(line, W) == 0 || strcmp(line, IL) == 0 ||
        strcmp(line, IR) == 0 || strcmp(line, SRCH) == 0 ||
        strcmp(line, SRCHL) == 0 || strcmp(line, SRCHR) == 0
        ) {
            return true;
        }
    return false;
}

int calculateStringValue(const char *str) {
    int value = 0;
    while (*str) {
        value += *str;
        str++;
    }
    return value;
}
