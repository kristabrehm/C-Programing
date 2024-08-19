//heap.cpp file

//include statements
#include "heap.h"
#include "data_structures.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <cmath>
		
using namespace std;

//corresponding basic min heap functions Heapify, 
//BuildHeap, ExtractMin, DecreaseKey, and Insertion.


//function that creates a HEAP pbject with the desired capacity and 0 size
//this function returns an initalized heap
HEAP* initHeap(double capacity) {
    //printf("Inside initHeap. Received capacity: %lf\n", capacity);
    
    HEAP *heap = (HEAP *)malloc(sizeof(HEAP)); //allocate memory
    heap->numHeapifyCalls = 0;
    
    //first memory allocation fail
    if (heap == NULL) {
        fprintf(stderr, "Error: heap is null");
        return NULL;
    }
    
    heap->capacity = capacity;  //set capacity
    heap->size = 0;             //set the size of the heap to 0 
    heap->A = (ELEMENT **)malloc((capacity + 1) * sizeof(ELEMENT *)); //initalizing the array
   
    //fprintf(stderr, "heap->capacity: %lf \n", heap->capacity);
   
   //second memory allocation fail
    if (heap->A == NULL) {
        //free(heap);
        fprintf(stderr, "Error: failed to allocate memory for heap array\n");
        return NULL;
    }
    return heap;
}


//the min heap property so heapify must be called
void buildHeap (TAG_HEAP* heap) {
    //need to iterate through the array list
    //USES A for loop
    //changes from > 0
    
    if (heap == NULL) {
	   fprintf(stderr, "Error: heap is NULL\n");
	   return;
	}
	heap->numHeapifyCalls = 0;
	        
    for (int i = heap->size / 2; i >= 1; i--) {
        minHeapify(heap,i);    //need to call heapify after the contents are made into a heap
    }
}


//this function is responsible for maintaining the heap property
//the input values are taken in from ifile and heapified in this function
void minHeapify(TAG_HEAP* heap, int i) {
    if (heap == NULL) {
	   fprintf(stderr, "Error: heap is NULL\n");
	   return;
	}
	
    int node = i;
    int leftChild = 2 * i;       //the left child is found by 2 * i + 1
    int rightChild = 2 * i + 1;  //the right child is found by 2 * i + 2
    
    heap->numHeapifyCalls++;
    //in the pseudocode for heapify we need to look at both the left and right nodes
    //LEFT NODE
    if (leftChild <= heap->size && heap->A[leftChild]->key < heap->A[node]->key) {
        node = leftChild;
    }

    //RIGHT NODE
    if (rightChild <= heap->size && heap->A[rightChild]->key < heap->A[node]->key) {
        node = rightChild;
    }

    if (node != i) {
        exchange(heap, i, node);    //call exchange function to swap nodes
        minHeapify(heap, node);     //recursively call minHeapify again to repeat process
    }
}



//this function is used to swap 2 key values within a heap
void exchange(TAG_HEAP* heap, int one, int two) {
    // Swap elements in the heap array
    ELEMENT* temp = heap->A[one];
    heap->A[one] = heap->A[two];
    heap->A[two] = temp;
}



//this function prints the contents of the heap object
void printHeap(TAG_HEAP* heap) {
    //fprintf(stdout, "Number of Heapify calls: %d\n", heap->size);
    
    if (heap == NULL ) {
        fprintf (stderr, "Error: heap is NULL\n");
	    return;
	} 
	
    // print heap size
    fprintf(stdout, "%d\n", heap->size);

    // use a for loop to iterate over the array
    // print the current size (NOT CAPACITY), followed by key values
    // min heaps use 1-indexed arrays
    for (int i = 1; i <= heap->size; i++) {
        if (heap->A[i] == NULL) {
            fprintf(stdout, "Error: heap is NULL\n");
            continue;
        }
        fprintf(stdout, "%.6lf\n", heap->A[i]->key);
    }
}

//this function inserts into the min-heap by inserting the key at the
//end of the array. it then moves as needed.
void insertHeap(TAG_HEAP* heap, double key) {
  if (heap == NULL) {
        fprintf(stderr, "Error: heap is NULL\n");
        return;
    }
  
  //the first thing u want to do is check if the size is greater than capacity
  
  if (heap->size >= heap->capacity){
      return;
  }
    
  //allocating memory
  TAG_ELEMENT* element = (TAG_ELEMENT*)malloc(sizeof(TAG_ELEMENT));
  
    if (element == NULL) {
        fprintf(stderr, "Error: failed to allocate memory for element\n");
        return;
    }
    
  element->key = key;

    
  heap->size++;
  int size = heap->size;
  heap->A[size] = element;
  //fprintf(stderr, "inside insert: heap size is %d\n", heap->size);

  //heapify
  while (size > 1 && heap->A[size]->key < heap->A[size/2]->key) {
    exchange(heap, size, size/2);
    size = size/2;
  }

}


//this function decrease the value of a certain key and takes in 2 parameters
void decreaseKeyHeap(TAG_HEAP* heap, int position, double newKey) {
    //position is the index to the array for the min heap
    //newkey is the value of the key field of object
    
    if (heap == NULL) {
	   fprintf(stderr, "Error: heap is NULL\n");
	   return;
	}
	if (heap->size == 0) {
        fprintf(stderr, "Error: heap is empty\n");
        return;
    }
	
    //if position is out of range
    if (position < 1 || position > heap->size){
        fprintf(stderr, "Error: invalid call to DecreaseKey\n");
        return;
    }
    
    //If newKey is not smaller than the current key
	if (newKey > heap->A[position]->key){	
	    fprintf(stderr, "Error: invalid call to DecreaseKey\n");
	    return;
	}
	
    heap->A[position]->key = newKey; // update key

  //heapify
    while (position > 1 && heap->A[position]->key < heap->A[position/2]->key) {
        exchange(heap, position, position/2);
        position = position/2;
    }
}


//this function is responsible for iterating through the entire heap and
//removing the smallest key. after removal the heap should be heapified.
void extractMinHeap(TAG_HEAP* heap, int flag) {

    if (heap == NULL) {
        fprintf(stderr, "Error: heap is NULL\n");
        return;
    }
    if (heap->size == 0) {
        fprintf(stderr, "Error:heap is empty\n");
        return;
    }
	        
    TAG_ELEMENT* minElement = heap->A[1];

    heap->A[1] = heap->A[heap->size];
    heap->size--;
    heap->numHeapifyCalls = 0;
    //heap->numHeapifyCalls++;

    minHeapify(heap, 1);    //maintain heap property
    
    printf("ExtractMin: %lf\n", minElement->key);
    
    if (flag == 1){
        //fprintf(stderr, "INSIDE FLAG == 1\n");
        fprintf(stdout, "Number of Heapify calls: %d\n", heap->numHeapifyCalls);
    }
   // free(minElement);
}



//this function is resposible for writing the contents
//of the heap to the output file
void writeHeap(TAG_HEAP* heap, char* file) {
    FILE* fp = fopen(file, "w");    //opens file in write mode
    
    if (!fp) {
        fprintf(stderr, "Error: cannot write to file %s\n", file);
    	return;
    }
    
    //write the heap information to the file, then close the file
	fprintf(fp, "%d\n", heap->size);
	
    for (int i = 1; i <= heap->size; i++) {
        fprintf(fp, "%.6lf\n", heap->A[i]->key);
    }
	fclose(fp);
}

//this function is responsible from reading in from the ifile
//it takes in the values in the file that can later be used and turned
//in a min heap
void readHeap(TAG_HEAP* heap, char* file) {
    FILE* fp = fopen(file, "r");  // opens file in read mode
    double n;  // read in from the first line of the file

    // if file is not opened successfully
    if (!fp) {
        fprintf(stderr, "Error: cannot open file %s\n", file);
        return;
    }

    // N IS EQUIVALENT TO THE HEAP SIZE
    // READ IN THE FIRST VALUE IN THE FILE TO GET VALUE OF N
    if (fscanf(fp, "%lf", &n) != 1) {
        fprintf(stderr, "Error: failed to read capacity from file\n");
        // FREE HEAP HERE AS WELL
        // for (int i = 1; i <= heap->size; i++) {
        //    free(heap->A[i]); // Free each element
        //}
        //free(heap->A);  // Free the array
        //free(heap);     // Free the heap structure
            
        fclose(fp);
        return;
    }

    // If capacity is smaller than n, write an error message to stderr, close the file,
    // and wait for the next instruction from stdin, skip the following actions.
    if (heap->capacity < n) {
        fprintf(stderr, "Error: heap capacity is smaller than n\n");
        fclose(fp);
        return;
    }

    heap->size = 0;
    
    // iterate through the entire heap to count the elements (heap->size)
    for (int j = 1; j <= n; j++) {
        ELEMENT* element = (ELEMENT*)malloc(sizeof(ELEMENT));

        if (element == NULL) {
            fprintf(stderr, "Error: failed to allocate memory for element\n");
            fclose(fp);
            return;
        }

        if (fscanf(fp, "%lf", &(element->key)) != 1) {
            fprintf(stderr, "Error: failed to read key from file\n");
            //free(element);
            // free the heap --> iterate through array first up until heap size *****************
            // free array then heap
           // for (int i = 1; i <= heap->size; i++) {
            //    free(heap->A[i]); // Free each element
           // }
           // free(heap->A);  // Free the array
           // free(heap);     // Free the heap structure
           // free(element);
            
            fclose(fp);
            return;
        }

        heap->A[j] = element;
        heap->size++;
    }

    n = heap->size;

    // After reading in the file, we call buildHeap
    // buildHeap will later call minHeapify() and exchange() to get the final min heap
    buildHeap(heap);

    fclose(fp);
}






