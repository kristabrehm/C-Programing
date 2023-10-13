/*
 * All of our binary search tree operations (Creating the tree, searching and inserting)
 * are located in this file. This is similar to the slist.c file in assignment 5 where all
 * of the linked list operations were located in the same file.
 */


//Include statements used throughout program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"


//when creating the game tree, the leaf nodes contain the names of fruits and vegetables
//while the internal nodes contain the questions. Either the question or guess will be am
//empty string ("") so the program will know which to print.
struct node* create_game_tree() {
	struct node* root = NULL;

	//100 is considered the root node in the BST
	//leaf nodes contain only answers & internal nodes contain questions
	root = insert(root, 100, "Does it grow underground?", "");
	insert(root, 50, "Is it long in shape?", "");
	insert(root, 25, "Is it orange in color?", "");
	insert(root, 15, "", "It's a carrot!");
	insert(root, 35, "", "It's a parsnip!");
	insert(root, 75, "Is it red in color?", "");
	insert(root, 65, "", "It's a radish!");
	insert(root, 85, "", "It's a potato!");
	insert(root, 150, "Does it grow on a tree?", "");
	insert(root, 125, "Is it red in color?", "");
	insert(root, 115, "", "It's an apple!");
	insert(root, 135, "", "It's a peach!");
	insert(root, 175, "Is it red in color?", "");
	insert(root, 165, "", "It's a tomato!");
	insert(root, 185, "", "It's a pea!");

	return root;
}


//this is the insert function. it is responsible for inserting the nodes into the correct
//spot in the BST. it first checks to see if the root node is NULL or not. it then traverses
//appropriately. This function can also be written recursively.
struct node* insert(struct node* root, int data, char* question, char* guess) {
	//first create a new node
    struct node* temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->question = strdup(question);
    temp->guess = strdup(guess);
    temp->left = temp->right = NULL;	//initialize the BST to null

    //if the tree is empty
    if (root == NULL) {
        return temp;
    }

    //search for new node's parent
    //create 2 pointers pointing at the root
    //parent is always trailing behind by 1 node
    //we need to initialize parent to NULL initially then set it equal to current.
    struct node* current = root;
    struct node* parent = NULL;

    while (current != NULL) {
        parent = current;

        if (data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    //insert the node
    if (data < parent->data) {
        parent->left = temp;
    } else {
        parent->right = temp;
    }
    return root;
}

//this function is used to search for a specific node. it starts at the root
//and uses a while loop to search the rest of the tree based off if the node will
//be the left or right child. repeats until found (if it is in the tree).
struct node* search(struct node* root, int data) {
	struct node* current = root;

	while(current != NULL && data != current->data) {
		if(data < current->data){
			current = current->left;
		} else {
			current = current->right;
		}
	}
	return current;
}
