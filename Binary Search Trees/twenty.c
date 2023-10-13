//Include statements used throughout program
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "bst.h"


//This function is responsible for the actual game. It asks a series of questions until the
//computer presents the player with a guess. At the end of the game the user is asked again to
//press 'q' or any other key, in which the game would play again.
void PlayTwentyQuestions(struct node* root) {
	char c;
	struct node* current_node = root;

	printf("You think of a fruit or vegetable and I will try to guess it!\n");

	//use a while loop to iterate through the BST while the left
	//or right node are not null. The nested if-else statement addresses
	//if the user inputs 'y' or 'n'.
	while (current_node->left != NULL || current_node->right != NULL) {
	    printf("%s\n", current_node->question);
	    printf("y/n: ");
	    scanf(" %c", &c);
	    printf("\n");

	    if (c == 'y') {
	        current_node = current_node->left;
	    }
	    else if (c == 'n') {
	        current_node = current_node->right;
	    }
	    else {
	        printf("Print either 'y' or 'n'.\n");
	    }
	}

	//outside of the while loop we use and if statement to address the case
	//in which both the left AND right children are null (you have reached a
	//leaf node). in this case, the computer takes a guess.
	if (current_node->left == NULL && current_node->right == NULL) {
		//the computer takes a guess
		printf("%s?\n", current_node->guess);
		printf("y/n: ");
		scanf(" %c", &c);

		if(c == 'y') {
			printf("I win!\n");
		}
		else {
			printf("You win!\n");
		}
		return;
	}
}


//This is the main function. It is primarily used to determine if the users input is 'q' or
//not. If the input is not 'q' then PlayTwentyQuestions() is called and the game is executed.
int main() {
  	char c;
  	int done = 0;

	struct node* game_tree = create_game_tree();

    printf("Welcome! Press 'q' to quit or any other key to continue:\n");

    while(!done) {
        scanf(" %c", &c);

    	if (c == 'q') {
    		done = 1;
    		printf("Bye Bye!\n");
    	}
    	else {
    		PlayTwentyQuestions(game_tree);
    	    printf("Press 'q' to quit or any other key to continue:\n");
    	}
    }
    return 0;
} //last main function bracket
