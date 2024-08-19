//graph.h file

#ifndef _graph_h
#define _graph_h
#include "data_structures.h"
#include "heap.h"


//function declarations:
//DONE:
void read(NODE***, VERTEX***, char*, int, int); //reads in from nextwork files
void initializeSingleSource(pVERTEX*, int, int);
void printADJList(pNODE*, int);                 //prints adjacency list
void printPath(pVERTEX*, int, int);                  //prints the shortest path
void relax(pVERTEX*, int, int, double);         //called in dijkstra
void dijkstra(VERTEX**, NODE**, int, int, int); //correct one
bool isEmpty(pHEAP);                            //returns heap size of 0 if true
void singleSource(VERTEX** , NODE** ,int, int); //singlesource function
void printLength(pVERTEX*, int, int, int);           //print length function


#endif
