//heap.h file

#ifndef _heap_h
#define _heap_h
#include "data_structures.h"
#include <stdio.h>


//corresponding basic min heap functions Heapify, 
//BuildHeap, ExtractMin, DecreaseKey, and Insertion.

//function declarations
HEAP* initHeap (double);                           //initalized heap
void printHeap (TAG_HEAP*);                     //prints heap contents
void minHeapify (TAG_HEAP*, int);               //heapifies - maintains property
void buildHeap (TAG_HEAP*);                     //creates the heap from array
void insertHeap (TAG_HEAP*, double);    //inserts into heap
void extractMinHeap (TAG_HEAP*, int);                //extracts min heap
void decreaseKeyHeap (TAG_HEAP*, int, double);  //decreases key in heap
void exchange (TAG_HEAP*, int, int);            //swaps 2 keys in a heap
void readHeap (TAG_HEAP*, char*);               //reads the input file
void writeHeap (TAG_HEAP*, char*);              //writes to output file

//void insertHeap (TAG_HEAP*, double, char*);
#endif
