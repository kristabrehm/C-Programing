/*
 * This file contains the struct deceleration as well as calls all of the
 * BST related functions from bst.c
 */


//Include statements used throughout program
#ifndef BST_H_
#define BST_H_
#include <stdio.h>


//define our node of type struct to store data, question, guess and left and right nodes
struct node {
	int data;
	char* question;
	char* guess;
	struct node* left;
	struct node* right;
};

//call all of the BST related functions
struct node* create_game_tree();
struct node* insert(struct node* root, int data, char* question, char* guess);
struct node* search(struct node* root, int data);


#endif /* BST_H_ */
