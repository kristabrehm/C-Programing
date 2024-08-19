//data_structures.h file

#ifndef _data_structures_h
#define _data_structures_h 1

#include <utility>

//VERTICES IMPLEMENTATION
//struct for the vertices in the graph
typedef struct TAG_VERTEX{
    int index;
  //  COLOR color;
    double key;
    int pi;
    int position;
}VERTEX;

typedef VERTEX *pVERTEX;

//EDGES IMPLEMENTATION
//struct for the nodes on the adjacency lists of the graph
typedef struct TAG_NODE{
    int index;
    int u;
    int v;
    double w;
    TAG_NODE *next;
}NODE;

typedef NODE *pNODE;



//MIN HEAP IMPLEMENTATION
//To partially re-use your implementation of Project 2, you can use the following:
typedef VERTEX ELEMENT;
typedef ELEMENT *pELEMENT;

//In this project, the elements of the heap array should be pointers to objects of type VERTEX. 
//To reuse codes with minimal modification:
typedef struct TAG_HEAP{
    int capacity;
    int size;
    pELEMENT *H;
}HEAP;

typedef HEAP *pHEAP;


//STACK IMPLEMENTATION
typedef struct TAG_STACK{
    int topOfStack;
    int stackCapacity;
    pVERTEX *elements;
}STACK;

typedef STACK *pSTACK;


//GRAPH IMPLEMENTATION
typedef struct {
    int vertices;
    pVERTEX* V;
    pNODE* ADJ;
} Graph;


#endif
