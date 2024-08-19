//heap.h file

#ifndef _heap_h
#define _heap_h
#include "data_structures.h"
#include <stdio.h>
#include <string.h>


//function declarations:
pHEAP initHeap(int);                           //initalizes heap

void insert (TAG_HEAP*, double, int);                //inserts into heap
pVERTEX extractMin(TAG_HEAP*);
void minHeapify (TAG_HEAP*, int);               //heapifies - maintains property
void exchange (TAG_HEAP*, int, int);            //swaps 2 keys in a heap    ORIGINAL
void decreaseKey (TAG_HEAP*, int, double);      //decreases key in heap   ORIGINAL




#endif
