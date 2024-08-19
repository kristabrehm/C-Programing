//util.cpp file

#include <stdio.h>
#include <string.h>
#include "util.h"
#include "data_structures.h"
#include "heap.h"


int nextInstruction(char *Word, double *key, double *anotherKey)
{
    int returnV;
    double capacity;

    fscanf(stdin, "%s", Word); //prints instruction to stdout

    if (strcmp(Word, "Stop")==0) return 1; 

   //the commands we are using in the test cases are Init, Read, Print, Write, and Stop
    if (strcmp(Word, "Print")==0) return 1;
    if (strcmp(Word, "Write")==0) return 1;
    if (strcmp(Word, "Read")==0) return 1;
    if(strcmp(Word, "ExtractMin")==0) return 1;


    if (strcmp(Word, "Init")==0){
	//need to read the value associated with Init
        returnV = fscanf(stdin, "%lf", key);
        if (returnV == 1){
            return 1;
        }else{
            return 0;
        }
    }

  
    if (strcmp(Word, "Insert")==0){
        //need to read the value associated with Insert
        returnV = fscanf(stdin, "%lf", key);
        if (returnV == 1){
            return 1;
        }else{
            return 0;
        }
    }

    if (strcmp(Word, "DecreaseKey") == 0) {
        returnV = fscanf(stdin, "%lf %lf", key, anotherKey);
        // todo: temp
        //fprintf(stderr, "Position: %lf, NewKey: %lf \n", *key, *anotherKey);

        if (returnV == 2){
            return 1;
        }else{
            return 0;
        }
    }
    
    return 0;
}
