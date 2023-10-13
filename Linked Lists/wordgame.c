//Include statements and variables used throughout program
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "slist.h"   //need to include slist.h file


//This function is used to add a new node at the front of the linked list.
//We do so by being given a reference to the head of a list and an int.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "slist.h"

void insertOrdered(slist* list, char name[], int num_guesses) {
    //First we need to create a new node and use malloc() to
	//allocate memory on the heap
    struct node* newnode = malloc(sizeof(struct node));

    strncpy(newnode->name, name, sizeof(newnode->name));
    newnode->name[sizeof(newnode->name) - 1] = '\0'; 		//CHECK HERE

    newnode->num_guesses = num_guesses;
    newnode->next = NULL;
    // Use an if-else statement to check if the list is empty or not
    // If it is empty, set the new node to be first
    //if it is not empty, add the new node in addition to the nodes already present
    if (list->head == NULL || num_guesses <= list->head->num_guesses) {
        newnode->next = list->head;
        list->head = newnode;
    } else {
        struct node* current = list->head;
        while (current->next != NULL && num_guesses > current->next->num_guesses) {
            current = current->next;
        }
        newnode->next = current->next;
        current->next = newnode;
    }
}

//this function is responsible for printing the current leader board stored in the
//linked list. at max, the top five players are printed in non-decreasing order.
void printList_n(slist* list, int n){
	struct node* current = list->head;
	int index = 1;

	while(current != NULL && index <= n) {
		printf("%s %d", current->name, (current->num_guesses -1));
		current = current->next;
		index++;
		printf("\n");
	}
}
