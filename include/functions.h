/* GHIȚĂ Andrei-Iulian - 324CB */
#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

#include <stdbool.h>

void reset_output_file();
FILE* open_file_in();
FILE* open_file_out();
bool nextIsChar(char *line);
int calculateStringValue(const char *str);

#endif
