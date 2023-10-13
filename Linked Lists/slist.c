//Include statements and variables used throughout program
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "slist.h"

//we need to define the board rows and columns again
#define NUM_ROWS 6
#define NUM_COLS 7

//This function is used to add a new node at the end of the linked list (tail).
//We do so by being given a reference to the head of a list and an int.
void insertNewNodeAtTail(slist* list, char board[NUM_ROWS][NUM_COLS]) {
    //First we need to create a new node and use malloc() to
	//allocate memory on the heap
    struct node* newnode = malloc(sizeof(struct node));

    //we then use a for loop to iterate through the 2D array the board is stored in.
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            newnode->board[i][j] = board[i][j];
        }
    }

    newnode->next = NULL;

    // Use an if-else statement to check if the list is empty or not
    // If it is empty, set the new node head and tail. if it is not empty, find the current tail and add a new node to it
    if (list->head == NULL) {
        list->head = newnode;
        list->tail = newnode;
    } else {
        list->tail->next = newnode;
        list->tail = newnode;
    }
}

//This function frees the nodes of the linked list. A while loop is used to indicate
//as long as the node is not null, it needs to be freed. We use a while loop to make sure
//that ALL of the nodes are freed, not just the current one.
void freeList(slist* list){
	struct node* current = list->head;

	while(current != NULL) {
		struct node* temp = current;
		current = current->next;
		free(temp);
	}
	list->head = NULL;
	list->tail = NULL;
}



