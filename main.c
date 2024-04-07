/* GHIȚĂ Andrei-Iulian - 324CB */
#include "./include/main.h"

int main() {
    reset_output_file();
    FILE* fin = open_file_in();
    FILE* fout = open_file_out();

    int len = 0;
    char *line = malloc(20 * sizeof(char));
    char *str = malloc(20 * sizeof(char));

    fscanf(fin, "%d", &len);

    TQueue* q = initQ();                // tasks queue
    TList train = initList();           // sentinel
    TList current = train->next;        // mechanic
    int tl = 0;                         // switch

    while (len > 0) {
        fscanf(fin, "%s", line);

        if (strcmp(line, EXEC) == 0) {
            if (tl == 1) {
                dequeueTaskSwitch(q, line, str);
            } else {
                dequeueTask(q, line, str);
            }
            int operation = execute(line);
            int res = 0;

            switch (operation) {
                case 705:
                    moveLeft(train, &current);
                    break;
                case 788:
                    moveRight(train, &current);
                    break;
                case 395:
                    current->info = str[0];
                    break;
                case 742:
                    clearCell(&current);
                    break;
                case 671:
                    clearAll(train, &current);
                    break;
                case 863:
                    res = insertLeft(&current, str);
                    if (res == 0) {
                        fprintf(fout, "ERROR\n");
                    }
                    break;
                case 946:
                    insertRight(&current, str);
                    break;
                case 438:
                    res = search(&current, str);
                    if (res == 0) {
                        fprintf(fout, "ERROR\n");
                    }
                    break;
                case 832:
                    res = searchLeft(&current, str);
                    if (res == 0) {
                        fprintf(fout, "ERROR\n");
                    }
                    break;
                case 915:
                    res = searchRight(&current, str);
                    if (res == 0) {
                        fprintf(fout, "ERROR\n");
                    }
                    break;
                default:
                    printf("Invalid choice! [%d]\n", operation);
            }
        } else if (strcmp(line, SC) == 0) {
            fprintf(fout, "%c\n", current->info);
        } else if (strcmp(line, SH) == 0) {
            showTrain(train, current, fout);
        } else if (strcmp(line, SW) == 0) {
            if (tl == 0) tl = 1;
            else tl = 0;
        } else if (nextIsChar(line)) {
            fscanf(fin, "%s", str);
            if (tl == 0) enqueueTask(q, line, str);
            else enqueueTask2(q, line, str);
        } else {
            if (tl == 0) enqueueTask(q, line, "\0");
            else enqueueTask2(q, line, "\0");
        }

        len -= 1;
    }

    destroyQueue(q);
    destroyList(&train);
    // free(q);
    // free(train);
    free(line);
    free(str);

    fclose(fin);
    fclose(fout);

    return 0;
}
