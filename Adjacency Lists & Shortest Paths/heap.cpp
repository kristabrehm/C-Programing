//heap.cpp file

//include statements
#include "heap.h"
#include "data_structures.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <cmath>
#include <limits.h>
#include <vector>
#include <queue>
#include <cfloat>
#include <limits.h>

#define NIL -1
		
using namespace std;


//function to initalize the heap:
//Your program should initialize a min-heap of capacity n using Dynamic memory allocation
pHEAP initHeap(int capacity) {
    pHEAP heap = (pHEAP)malloc(sizeof(HEAP)); //allocate memory
    
    //first memory allocation fail
    if (heap == NULL) {
        fprintf(stderr, "Error: heap is null");
        return NULL;
    }
    
    heap->capacity = capacity;  //set capacity
    heap->size = 0;             //set the size of the heap to 0 
    heap->H = (pELEMENT*)malloc((capacity + 1) * sizeof(ELEMENT)); //initalizing the array of vertices
   
    //fprintf(stderr, "heap capacity %d\n", heap->capacity);
    
   //second memory allocation fail
    if (heap->H == NULL) {
        free(heap);
        return NULL;
    }
    return heap;
}


//this function is responsible for maintaining the heap property
//the input values are taken in from ifile and heapified in this function
void minHeapify(pHEAP heap, int i) {
    //error handling
    if (heap == NULL) {
	   fprintf(stderr, "Error: heap is NULL\n");
	   return;
	}
	
    int node = i;
    int leftChild = 2 * i;       //the left child is found by 2 * i + 1
    int rightChild = 2 * i + 1;  //the right child is found by 2 * i + 2
    
    //in the pseudocode for heapify we need to look at both the left and right nodes
    //LEFT NODE
    if (leftChild <= heap->size && heap->H[leftChild]->key < heap->H[node]->key) {
        node = leftChild;
    }

    //RIGHT NODE
    if (rightChild <= heap->size && heap->H[rightChild]->key < heap->H[node]->key) {
        node = rightChild;
    }

    if (node != i) {
        exchange(heap, i, node);    //call exchange function to swap nodes
        //exchange(V, i, node);    //call exchange function to swap nodes
        minHeapify(heap, node);     //recursively call minHeapify again to repeat process
    }
}

//this function is used to swap 2 key values within a heap
void exchange(pHEAP heap, int one, int two) {
    // Swap elements in the heap array
    ELEMENT* temp = heap->H[one];
    heap->H[one] = heap->H[two];
    heap->H[two] = temp;
}


//this function inserts into the min-heap by inserting the key at the
//end of the array. it then moves as needed.
void insert(pHEAP heap, double key, int index) {
  //error handling
  if (heap == NULL) {
        fprintf(stderr, "Error: heap is NULL\n");
        return;
  }
  if (heap->size >= heap->capacity){
      return;
  }
  
    
  pVERTEX element = (pVERTEX)malloc(sizeof(TAG_VERTEX));    //allocate memory
  if(element == NULL){
      fprintf(stderr, "error: failed to allocate memory for element\n");
  }
 
  element->key = key;
  element->index = index;       //CHECK TIS LINE
  heap->size++;
  int size = heap->size;
  heap->H[size] = element;
  
  //heapify
  while (size > 1 && heap->H[size]->key < heap->H[size/2]->key) {
    exchange(heap, size, size/2);
    size = size/2;
  }
}




//this function is responsible for iterating through the entire heap and
//removing the smallest key. after removal the heap should be heapified.
pVERTEX extractMin(pHEAP pq) {
    //fprintf(stderr, "Entered extract min\n");
    
    if (pq == NULL) {
        fprintf(stderr, "Error: heap is NULL\n");
        return NULL;                                //CHECK RETURN STATEMENT
    }
    if (pq->size == 0) {
        fprintf(stderr, "Error:heap is empty\n");
        return NULL;                                //CHECK RETURN STATEMENT
    }
	        
    pVERTEX minElement = pq->H[1];
    pq->H[1] = pq->H[pq->size];
    pq->size--;
    

    minHeapify(pq, 1);    //maintain heap property
    
    return minElement;

}



//this function decrease the value of a certain key and takes in 2 parameters
void decreaseKey(pHEAP heap, int index, double newKey) {
    //error handling
    if (heap == NULL) {
	   fprintf(stderr, "Error: heap is NULL\n");
	   return;
	}
	
	/*
    //if index is out of range
    if (index < 1 || index > heap->size){
        fprintf(stderr, "Error: invalid index value\n");
        return;
    }
    
    //If newKey is not smaller than the current key
	if (newKey > heap->H[index]->key){	
	    fprintf(stderr, "Error: new key is not smaller\n");
	    return;
	}
	*/
	
    heap->H[index]->key = newKey; // update key

  //heapify
    while (index > 1 && heap->H[index]->key < heap->H[index/2]->key) {
        exchange(heap, index, index/2);
        index = index/2;
    }
}
