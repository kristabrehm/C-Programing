#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"
#include "list_read.h"
#include "list_write.h"

int main(int argc, char **argv){
    FILE *fp;
    LIST *List;
    NODE *pNODE;
    double key, max;
    int returnV;
    char Word[100];

    if (argc < 3){
        fprintf(stderr, "Usage: %s <ifile> <ofile>\n", argv[0]);
        exit(0);
    }

    fp = fopen(argv[1], "r");
    if (!fp){
        fprintf(stderr, "Error: cannot open file %s\n", argv[1]);
        exit(0);
    }
    List = (LIST *) calloc(1, sizeof(LIST));
    if (!List){
        fprintf(stderr, "Error: calloc failed\n");
        exit(0);
    }
    while ((returnV = fscanf(fp, "%lf", &key)) == 1){
        listAppend(List, key);
    }
    fclose(fp);

    while (1){
        returnV = nextInstruction(Word, &key);

        if (returnV == 0){
            fprintf(stderr, "Warning: Invalid instruction\n");
            continue;
        }

        if (strcmp(Word, "Stop")==0){
            return 0;
        }

        if (strcmp(Word, "Print")==0){
            listPrint(List);
            fprintf(stdout, "\n");
            continue;
        }

        if (strcmp(Word, "Max")==0){
            if (List != NULL && List->head != NULL){
                max = listMax(List);
                fprintf(stdout, "Max=%lf\n", max);
            }
            continue;
        }

        if (strcmp(Word, "Write")==0){
            if (List != NULL || List->head != NULL){
                fp = fopen(argv[2], "w");
                if (!fp){
                    fprintf(stderr, "Error: cannot open file %s\n", argv[2]);
                    exit(0);
                }
                pNODE = List->head;
                while (pNODE){
                    fprintf(fp, "%lf\n", pNODE->key);
                    pNODE = pNODE->next;
                }
                fclose(fp);
            }
            continue;
        }

        if (strcmp(Word, "Insert")==0){
            listInsert(List, key);
            continue;
        }

        if (strcmp(Word, "Append")==0){
            listAppend(List, key);
            continue;
        }

        if (strcmp(Word, "Delete")==0){
            listDelete(List, key);
            continue;
        }
    }

    return 1;
}
