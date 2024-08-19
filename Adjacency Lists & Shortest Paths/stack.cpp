//stack.cpp file

//include statements
#include "stack.h"
#include "data_structures.h"

#include <iostream>
using namespace std;

#define MAX 10000

//int a[MAX]; // Maximum size of Stack 


//function to initalize the stack:
//Your program should initialize a stack of capacity n using Dynamic memory allocation
pSTACK initStack(int capacity){
    pSTACK stack = new STACK;
    if(stack == NULL) {
        fprintf(stderr, "memeory allocation failed\n");
    }
    
    stack->topOfStack = -1;             //set the top of the stack
    stack->stackCapacity = capacity;    //set capacity
    stack->elements = new pVERTEX[capacity];
    
   //second memory allocation fail
    if (stack->elements == NULL) {
        free(stack);
        return NULL;
    }
    return stack;    
}

//add to the stack
void push(pSTACK stack, pVERTEX element){
    if (stack->topOfStack >= (stack->stackCapacity)-1){
        fprintf(stderr, "stack overflow\n");
        return;
    } 
    stack->elements[stack->topOfStack++] = element;
}


//check to see if the stack is empty
bool isStackEmpty(STACK* stack){
    return(stack->topOfStack == -1);
}

//remove from the stack
void pop(STACK* stack) {

    stack->topOfStack--;
}
