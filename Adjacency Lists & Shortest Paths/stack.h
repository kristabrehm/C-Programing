//stack.h file

#ifndef _stack_h
#define _stack_h
#include "data_structures.h"
#include "graph.h" 
#include <stdio.h>


//function declarations:
pSTACK initStack(int);

//stack operations: push, pop, isEmpty, 
void push(pSTACK, pVERTEX);
void pop(pSTACK);
bool isStackEmpty(pSTACK);

#endif
