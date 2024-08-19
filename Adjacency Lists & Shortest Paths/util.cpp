//util.cpp file

#include <stdio.h>
#include <string.h>

#include "util.h"
#include "data_structures.h"
#include "heap.h"
#include "main.h"
#include "graph.h"


//used with main function to loop over instructions
int nextInstruction(char *Word, double *key, double *anotherKey)
{
    int returnV;
    double capacity;

    fscanf(stdin, "%s", Word); //prints instruction to stdout

    //take in no parameters
    if (strcmp(Word, "Stop")==0) return 1; 
    if (strcmp(Word, "PrintADJ")==0) return 1;


    if (strcmp(Word, "SingleSource")==0){
        returnV = fscanf(stdin, "%lf", key);
        if (returnV == 1){
            return 1;
        } else {
            return 0;
        }
    }
    
    if (strcmp(Word, "SinglePair") == 0) {
        returnV = fscanf(stdin, "%lf %lf", key, anotherKey);
        if (returnV == 2){
            return 1;
        } else {
            return 0;
        }
    }
    
    if (strcmp(Word, "PrintPath") == 0) {
        returnV = fscanf(stdin, "%lf %lf", key, anotherKey);
        //fprintf(stderr, "source: %lf, desintaion: %lf \n", *key, *anotherKey);
        if (returnV == 2){
            return 1;
        } else {
            return 0;
        }
    }

    if (strcmp(Word, "PrintLength") == 0) {
        returnV = fscanf(stdin, "%lf %lf", key, anotherKey);
        if (returnV == 2){
            return 1;
        } else {
            return 0;
        }
    }
    
    return 0;
}
