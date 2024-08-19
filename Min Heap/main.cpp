//main.cpp file

//inlcude statements
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>

// need to include our header files for util and heap 
#include "util.h"
#include "heap.h"
#include "data_structures.h"

using namespace std;

int main(int argc, char **argv){
    HEAP *heap;
    double key, anotherKey;
    int returnV;
    char Word[120];
    FILE *fp;
    double capacity = -1;
    int flag;   //used for valid executions

    //argv[1] IS USED TO OPEN THE FILE IN READ MODE
    //argv[2] IS USED TO OPEN THE FILE IN WRITE MODE
    
    //IF COUNT IS 0 IN FLAG CASE is 1, DONT PRINT

    //argc counts the number of command line arguments passed
    /*
    if (argc < 3){
        fprintf(stderr, "Usage: %s <ifile> <ofile>\n", argv[0]);
        exit(0);
    }
        */
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <ifile> <ofile> <flag>\n", argv[0]);
        exit(0);
    } 
    
    fp = fopen(argv[1], "r");
    if (!fp){
        fprintf(stderr, "Error: cannot open file %s\n", argv[1]);
        exit(0);
    }
    
    //***************************FLAG HANDELING
    try {
        flag = stoi(argv[3]);
    } catch (const exception& e) {
        fprintf(stderr, "Provide a flag value\n");
        //exit(EXIT_FAILURE);
    }
    
    //handle the case in which there is not a valid execution
    //PROGRAM SHOULD NOT TERMINATE
    if (flag != 0 && flag != 1) {
        fprintf(stderr, "./PJ2 <ifile> <ofile> flag\n");
        //exit(EXIT_FAILURE);
    }


    //while loop: responsible for reading in commands
    while (1) {
        returnV = nextInstruction(Word, &key, &anotherKey); //TAKES IN INFORMATION

        //if there is invalid instruction, print the following
        if (returnV == 0){
            fprintf(stderr, "Warning: Invalid instruction\n");
            continue;
        }
     
        //if the word is stop, terminate the program
        if (strcmp(Word, "Stop")==0){
            return 0; //terminaytes the program
        }
      
      
      //if the command is print, do the following
        if (strcmp(Word, "Print")==0){
	        //if heap is not null, print the current state of the heap to stdout
            printHeap(heap);
            continue;
        }


        //if the command is Init, do the following
	    if (strcmp(Word, "Init")==0) {
	        if (returnV == 1) {
	           capacity = key;      //set the capacity equal to key
	           
	        if (key < 0) {
                    fprintf(stderr, "Error: Capacity not initialized\n");
                    continue;
                }
                
	            heap = initHeap(capacity);  //call init function
    
	            if (heap == NULL) {
	                fprintf(stderr, "Error: Failed to initialize the heap\n");
                    continue; 
	            }
	        } 
	        continue;
	    }
    
        //if the command is read, do the following
        if (strcmp(Word, "Read") == 0) {
            if (heap == NULL) {
                fprintf(stderr, "Error: heap is NULL\n");
                continue;
            }
            
            if (capacity < 0) {
                fprintf(stderr, "Error: capacity not initialized\n");
                continue;
            }
                //"Usage: %s <ifile> <ofile> <flag>\n", argv[0]);
            readHeap(heap, argv[1]); //read to file in argv[1]
            
            if (flag == 1){
               // fprintf(stderr, "INSIDE FLAG == 1\n");
               if (heap->size != 0) {
                   fprintf(stdout, "Number of Heapify calls: %d\n", heap->numHeapifyCalls);
               }
                //fprintf(stdout, "Number of Heapify calls: %d\n", heap->numHeapifyCalls);
            }
            continue;
        }
        

        //if the command is write, do the following
        if (strcmp(Word, "Write")==0){
            //if heap is NULL
            if (heap == NULL) {
	            fprintf(stderr, "Error: heap is NULL\n");
	            continue;
	        }
	        //if heap is empty
	        if(heap->size ==0){
	            fprintf(stderr, "Error: heap is empty\n");
	        }
	        //else, not null or empty
	        writeHeap(heap, argv[2]);    //write to file in argv[2]
            
	        continue;
        }
    
	    //if the instruction is Insert, do the following
	    //check if the heap is NULL
	    if (strcmp(Word, "Insert")==0) {
	        

	        //insert object into the min heap
	        insertHeap(heap, key);
	        continue;
        }        
     
 	    //if the instruction is ExtractMin, do the following
        if (strcmp(Word, "ExtractMin")==0) {
	        //perform the extractmin operation
 	        extractMinHeap(heap, flag);
 	        continue;
        } 
        
        
        //if the instruction is DecreaseKey, do the following
        if (strcmp(Word, "DecreaseKey") == 0) {
        //if (strcmp(Word, strlen("DecreaseKey"))==0) {

            //decrease the key field and perform operations on min heap, then continue
	        decreaseKeyHeap(heap, (int) key, anotherKey);
	        
	        continue;
        }
    }
    
}
