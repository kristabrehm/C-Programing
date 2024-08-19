//graph.cpp file

//include statements
#include "graph.h"
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
#include <stack>
#include <stdbool.h>

#define NIL -1
		
using namespace std;

//this function is responsible from reading in from the ifile
//it takes in the values in the file that can later be used and turned in a min heap
//need to read in n and m then have a for loop looping through the rest of the file
//needs to read in 4 values: u, v, w and (u, v)
void read(NODE*** ADJ, VERTEX*** V, char* file, int flag, int graphType) {
    FILE* fp = fopen(file, "r");  // opens file in read mode
    int n, m;                     // first 2 values in the file

    // if file is not opened successfully
    if (!fp) {
        fprintf(stderr, "Error: cannot open file %s\n", file);
        return;
    }
    
    //read n and m
    if (fscanf(fp, "%d %d", &n, &m) != 2) {
        fprintf(stderr, "Error: failed to read\n");
        fclose(fp);
        return;
    }

    *ADJ = (NODE**)malloc((n + 1) * sizeof(NODE*));     //memory allocation
    *V = (VERTEX**)malloc((n + 1) * sizeof(VERTEX*));   // memory allocation
    //error handling
    if (*ADJ == NULL || *V == NULL) {
        fprintf(stderr, "Error: memory allocation failed\n");
        fclose(fp);
        return;
    }

    //initalize adjacency list
    for (int i = 1; i <= n; i++) {
        (*ADJ)[i] = NULL;
        (*V)[i] = NULL;
    }

    //read in data
    for (int i = 1; i <= m; i++) {
        int edgeIndex, u, v;
        double w;
        //error handling
        if (fscanf(fp, "%d %d %d %lf", &edgeIndex, &u, &v, &w) != 4) {
            fprintf(stderr, "Error: failed to read edge data\n");
            fclose(fp);
            return;
        }

        NODE* newnode = (NODE*)malloc(sizeof(NODE)); // memory allocation
        // error handling
        if (newnode == NULL) {
            fprintf(stderr, "Error: memory allocation failed\n");
            fclose(fp);
            return;
        }

        //assign values
        newnode->u = u;
        newnode->v = v;
        newnode->w = w;
        newnode->next = NULL;

        //DIRECTED GRAPHS ****************
        if (graphType == 0) {
            NODE* current = (*ADJ)[u];
            if (flag == 1) {
                newnode->next = current;
                (*ADJ)[u] = newnode;
            } 
            else if (flag == 2) {
                NODE* prev = NULL;
                while (current != NULL) {
                    if (current->v == v)
                        break;
                    prev = current;
                    current = current->next;
                }
                if (current == NULL) {
                    // No duplicate found, insert at the rear
                    if (prev == NULL)
                        (*ADJ)[u] = newnode;
                    else
                        prev->next = newnode;
                }
            } 
            else {
                fprintf(stderr, "Error: Invalid flag value\n");
                fclose(fp);
                return;
            }
        } 
        else if (graphType == 1) { //UNDIRECTED GRAPH ************************
            NODE* node1 = (*ADJ)[u];
            NODE* node2 = (*ADJ)[v];
            if (flag == 1) {
                newnode->next = node1;
                (*ADJ)[u] = newnode;
                NODE* newnode1 = (NODE*)malloc(sizeof(NODE)); // Memory allocation
                if (newnode1 == NULL) {
                    fprintf(stderr, "Error: memory allocation failed\n");
                    fclose(fp);
                    return;
                }
                newnode1->u = v;
                newnode1->v = u;
                newnode1->w = w;
                newnode1->next = node2;
                (*ADJ)[v] = newnode1;
            } 
            else if (flag == 2) {
                // Insert at the rear of ADJ[u]
                while (node1 != NULL && node1->next != NULL) {
                    node1 = node1->next;
                }
                if (node1 != NULL) {
                    node1->next = newnode;
                } else {
                    (*ADJ)[u] = newnode;
                }
                NODE* newnode1 = (NODE*)malloc(sizeof(NODE)); // Memory allocation
                if (newnode1 == NULL) {
                    fprintf(stderr, "Error: memory allocation failed\n");
                    fclose(fp);
                    return;
                }
                newnode1->u = v;
                newnode1->v = u;
                newnode1->w = w;
                newnode1->next = NULL;
                node2 = (*ADJ)[v];
                while (node2 != NULL && node2->next != NULL) {
                    node2 = node2->next;
                }
                if (node2 != NULL) {
                    node2->next = newnode1;
                } 
                else {
                    (*ADJ)[v] = newnode1;
                }
            } 
            else {
                fprintf(stderr, "Error: Invalid flag value\n");
                fclose(fp);
                return;
            }
        } 
        else {
            fprintf(stderr, "Error: Invalid graph type\n");
            fclose(fp);
            return;
        }
    }

    fclose(fp);
}



//function to print the adjecency list:
void printADJList(pNODE* ADJ, int n){
    for(int i = 1; i <=n; i++){
        fprintf(stdout, "ADJ[%d]:-->", i);
        
        // TODO: Checking if adjacency list is NULL 
        if (!ADJ){
            fprintf(stderr, "Adjacency list was null\n"); 
            return;
        }
        
        for (pNODE current = ADJ[i]; current != NULL; current = current->next){
            printf("[%d %d: %4.2lf]", current->u, current->v, current->w);
            if(current->next != NULL){
               fprintf(stdout,"-->"); 
            }
        }
        fprintf(stdout, "\n");
    }
}

//need a relax function as a part of DIJKSTRA
void relax(pVERTEX* V, int u, int v, double w){
    //fprintf(stderr, "Entered relax function\n");
   if(V[v]->key > V[u]->key + w){
       V[v]->key = V[u]->key + w;
       V[v]->pi = u;
   } 
}



//called from dijkstra
void initializeSingleSource(pVERTEX* V, int n, int s) {
    //fprintf(stderr, "Entered initalize single source\n");
    for (int i = 1; i <= n; i++) {
        V[i] = (pVERTEX)malloc(sizeof(VERTEX));
            if (V[i] == NULL) {
                fprintf(stderr, "Error: Memory allocation failed for V[%d]\n", i);
                return;
            }
        V[i]->index = i;
        V[i]->key = DBL_MAX;        //SEG FAULT HERE (SOMETIMES)
        V[i]->pi = NIL;
    }
    V[s]->key = 0;
}


//DIJKSTRA IS CALLED WHEN SINGLEPAIR IS THE INPUT
void dijkstra(pVERTEX* V, pNODE* ADJ, int n, int s, int t) {
    //error handling
    if (V == NULL || ADJ == NULL) {
        fprintf(stderr, "Error: Memory allocation failed for V or ADJ\n");
        return;
    }

    initializeSingleSource(V, n, s);    //initalize single source according to pseudocode
    
    //initalize set and queue
    pHEAP pq = initHeap(n);      
    if (pq == NULL) {
        fprintf(stderr, "Error: failed to initialize priority queue\n");
        return;
    }
    
    //insert vertices into q
    for (int i = 1; i <= n; i++) {
        insert(pq, V[i]->key, i);  // Insert all vertices into the priority queue
    }
    
    //DIJKSTRAS ALGO BELOW ***********************
    while (!isEmpty(pq)) {
        pVERTEX u = extractMin(pq);  
        pNODE current = ADJ[u->index];     

        while (current != NULL) {
            relax(V, u->index, current->v, current->w); //call relax function
            
            if (V[current->v]->key != DBL_MAX) {
                decreaseKey(pq, V[current->v]->index, V[current->v]->key); //call decrease key
            }
            current = current->next;
        }
    }
}


//this fucntion is called WHEN SINGLESOURCE 
//this is the same algorithm as dijkstra just without destination
void singleSource(pVERTEX* V, pNODE* ADJ, int n, int s) {
       //error handling
    if (V == NULL || ADJ == NULL) {
        fprintf(stderr, "Error: Memory allocation failed for V or ADJ\n");
        return;
    }
    
    initializeSingleSource(V, n, s);    //initalize single source according to pseudocode
    
    //initalize set and queue
    pHEAP pq = initHeap(n);      
    if (pq == NULL) {
        fprintf(stderr, "Error: failed to initialize priority queue\n");
        return;
    }
    
    //insert vertices into q
    for (int i = 1; i <= n; i++) {
        insert(pq, V[i]->key, i);  // Insert all vertices into the priority queue
    }
    
    //DIJKSTRAS ALGO BELOW ***********************
    while (!isEmpty(pq)) {
        pVERTEX u = extractMin(pq);  
        pNODE current = ADJ[u->index];     

        while (current != NULL) {
            relax(V, u->index, current->v, current->w); //call relax function
            
            if (V[current->v]->key != DBL_MAX) {
                decreaseKey(pq, V[current->v]->index, V[current->v]->key); //call decrease key
            }
            current = current->next;
        }
    }
    /*
    //for debugging
        for (int i = 1; i <= n; i++) {
        printf("Predecessor of vertex %d: %d\n", i, V[i]->pi);
    }*/
}


//THIS IS THE ONLY PATH PRINTING INSTRUCTION
void printPath(pVERTEX* V, int s, int t){
    int current = t;
    int maxVertices = 100;
    int path[maxVertices];
    int pathLength = 0; //initalize to 0
    
    
    //error handling
    if (V[t]->pi == NIL) {
        fprintf(stdout, "There is no path from %d to %d.\n", s, t);
        return;
    }
    
    while (current != NIL){
        path[pathLength++] = current;   
        current = V[current]->pi;
    }

    /*
    //(pathLength == 0 || path[pathLength - 1] != s) 
    if (path[pathLength - 1] != s)  {
        fprintf(stdout, "There is no path from %d to %d.\n", s, t);
        return;
    }
*/
    fprintf(stdout, "The shortest path from %d to %d is:\n", s, t);
    
    for (int i = pathLength - 1; i > 0; i--) {
        fprintf(stdout, "[%d:%8.2lf]-->", path[i], V[path[i]]->key);
    }
    
    fprintf(stdout, "[%d:%8.2lf].\n", path[0], V[path[0]]->key);
}  



//THIS FUNCTION IS CALLED WHEN PRINTLENGTH IS THE COMMAND
//if you have computed a path, print but if you have no computed a path, print nothing
void printLength(pVERTEX* V, int n, int s, int t) {
        // Check if the vertex indices are valid
    if (s < 1 || s > n || t < 1 || t > n) {
        fprintf(stdout, "Invalid vertex indices.\n");
        return;
    }
    
    //error handling
    if(V[t]->pi == NIL){
        fprintf(stdout, "There is no path from %d to %d.\n", s, t);
        return;
    }
    fprintf(stdout, "The length of the shortest path from %d to %d is: %8.2lf\n", s, t, V[t]->key);
    //fprintf(stdout, "There is no path from %d to %d. \n", s, t);
}



//function used for error handling
bool isEmpty(pHEAP heap){
    return heap->size == 0;
}


