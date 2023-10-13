//Include statements and variables used throughout program
#ifndef slist_h
#define slist_h
#include <stdio.h>
#include <unistd.h>

//we need to define the board rows and columns again
#define NUM_ROWS 6
#define NUM_COLS 7

//we use a struct to keep the references to data and next of type node
//because we want to print out the board after each move, we need to keep
//track of the board itself

//This struct contains information about the board
struct node {
	char board[NUM_ROWS][NUM_COLS];
	struct node* next;
};

//This struct contains the actual (entire) linked list
struct singlylinkedlist {
	struct node* head;
	struct node* tail;
};

typedef struct singlylinkedlist slist;

//we then call all of the linked list - related functions
void insertNewNodeAtTail(slist* list, char board[NUM_ROWS][NUM_COLS]);
void freeList(slist* list);
void replayMoves(slist* list);

#endif /* slist_h */
