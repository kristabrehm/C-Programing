/*
Throughout the code there is a series of nested for loops used to create and iterate
through the connect for board in each function. We use a 2D array in order to create both columns and rows
that are accessible.

Now, when the game ends, the user is prompted to not only to quit, but also to enter r
to rerun. A replay shows the empty board and the moves that occurred.

A linked list is used to record the moves the player makes.
A singly linked list is used in files slist.c and slist.h.

NOTE: Remember to reset the 'board' array to start fresh with the replay.
Then make sure you have a loop that traverses your LL and does
a 'printboard' each time.
 */

//Include statements and variables used throughout program
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include "slist.h"

#define NUM_ROWS 6
#define NUM_COLS 7
char board[NUM_ROWS][NUM_COLS];

bool game_over = false;
char player = 'R';

//prints the current state of the board
 void printBoard(char board[][NUM_COLS]){
	for (int row = 0; row <+ NUM_ROWS; row++) {
		for (int col = 0; col < NUM_COLS; col++) {
			printf("|%c", board[row][col]);
		}
		printf("|\n");
	}
	printf("---------------\n");
 }


 //checks if all places on board have been taken
 //check rows for 4 sequential tokens
  bool CheckBoardFull(char board[][NUM_COLS]) {

 	 for (int row = 0; row < NUM_ROWS; row++) {
 		 for (int col = 0; col < NUM_COLS; col++) {
 			 if(board[row][col] == ' ') {
 				 return false;
 			}
 		}
 	 }
 	 return true;		//return true if the board is full by default
  }


 //returns the next available row for a given column
 //return -1 if a column is full else return the row
  int getEmptyRow(char board[][NUM_COLS], int col) {
 	 for (int row = NUM_ROWS - 1; row > 0; row--) {
 		 if (board[row][col] == ' '){
 			 return row;
 		 }
  }
 	 return -1;		//return -1 if the column is full by default
  }


 //checks for 4 sequential player tokens
 //for the winner or return ' ' if no winner yet
  char checkWinner(char board[][NUM_COLS]){
 //we can use for loops to iterate through the board

 	 //check horizontally
 	 for (int row = 0; row < NUM_ROWS; row++) {
 		 for (int col = 0; col < NUM_COLS - 3; col++) {
 			 if ((board[row][col] != ' ') && (board[row][col] == board[row][col+1])&& (board[row][col] == board[row][col+2])&& (board[row][col] == board[row][col+3])) {
 				 return board[row][col];
 			 }
 		}
 	}
 	 //check vertically
 	 //to do so we need to flip flop the row and the column being the nested loop
 	 for (int col =0; col < NUM_COLS; col++) {
 		 for(int row = 0; row < NUM_ROWS - 3; row++){
 			 if ((board[row][col] != ' ') && (board[row][col] == board[row+1][col])&& (board[row][col] == board[row+2][col])&& (board[row][col] == board[row+3][col])) {
 				 return board[row][col];
 			 }
 		 }
 	 }
  	 return ' ';
  }


//prompts the player for a column between 1 - 7.
 int getColumn(char player) {

 	 int column;

 	 printf("%s to play, Pick a column (1-7):", player =='R' ? "Red":"Yellow");

 	 int num_values = scanf("%d", &column);
 	 while(getchar() != '\n');		//clear buffer of newline

 	 //re-prompt if player enters invalid guess
 	 while (num_values != 1 || column < 1 || column > NUM_COLS) {
 	 	 printf("make sure the column is between 1 and 7: \n");
 	 	 num_values = scanf("%d", &column);
 	 	 while(getchar() != '\n');
 	 }
 	 return column - 1;
 }

 //This function is responsible for printing the board and what it looked like during all of
 //the moves as they were made throughout the game. When called, it uses the sleep function to delay
 //each board being printed.
 void replayMoves(slist* list) {
     struct node* current = list->head;
     while (current != NULL) {
         printBoard(current->board);
         current = current->next;
         sleep(1);
         }
 }

 //allows players to pick a column for their token (R/Y) and announces
 //a winner or a tie
 void PlayConnectFour(slist* list) {
 	//create an empty board
 	 for (int row = 0; row < NUM_ROWS; row++) {
 		for (int col = 0; col < NUM_COLS; col++) {
 			board[row][col] = ' ';
 		}
 	}

 	 for (int row = 0; row < NUM_ROWS; row++) {
 		for (int col = 0; col < NUM_COLS; col++) {
 			printf("|%c", board[row][col]);
 		}
 		printf("|\n");
 	}
 	printf("---------------\n");


 	 while (!game_over) {
 		 int col = getColumn(player);
 		 printBoard(board);

 		 int row = getEmptyRow(board, col);

 		if (row == -1){
 		    printf("This column is full. Please choose again.\n");
 		    continue;
 		}

 		 board[row][col] = player;

  		 //After each move, while in the loop, we need to
 		 //add the state of the current board to the end of the linked list before the
 		 //next player moves.
 		 insertNewNodeAtTail(list, board);

 		 char winner = checkWinner(board);

 		 //we use a series of if and else-if statements to determine the numerous
 		 //combinations of who won
 		 if (winner == 'R'){
 			 game_over = true;
 			 printf("Red wins!\n");
 			 printf("Good game!\n");
 		 } else if (winner == 'Y'){
 			 game_over = true;
 			 printf("Yellow wins!\n");
 			 printf("Good game!\n");
 		 } else if(CheckBoardFull(board)){
 			 game_over = true;
 			 printf("It's a tie, nobody wins!");
 		 }

 		 player = (player == 'R' ? 'Y' : 'R');	//conditional (ternary) operator

 			for (int row = 0; row < NUM_ROWS; row++) {
 				for (int col = 0; col < NUM_COLS; col++) {
 					printf("|%c", board[row][col]);
 				}
 				printf("|\n");
 			}
 			printf("---------------\n");
 	 }
 }

 //prompts the user to play or quit and then enters a loop to allow
 //the user to play as many times as they liked
 int main() {
	//declare and initialize our linked list to be empty (NULL)
	slist list;
	list.head = NULL;
	list.tail = NULL;

  	char c;
  	int done = 0;

 	char player[2][100];
 	int playerRed = 0;		//player one will be located at index 0
 	int playerYellow = 1;	//player two will be located at index 1


     printf("Welcome! Press 'q' to quit or any other key to continue:\n");
     scanf(" %c", &c);

     //as long as the input from the user is not 'q' we then ask the users
     //what their names are and assign them colors. the game then starts with
     //the two players alternating back and forth until there is a winner
 	if (c == 'q') {
 		done = 1;
 		printf("Bye Bye!\n");
 		freeList(&list);
 	} else {
 		printf("Player one, what is your name?: ");
 		scanf("%s", player[playerRed]);

 		printf("Player two, what is your name?: ");
 		scanf("%s", player[playerYellow]);

 		printf("\n%s you will be the color red\n", player[playerRed]);
 		printf("%s you will be the color yellow\n\n", player[playerYellow]);

 	    printf("Press 'q' to quit or any other key to continue:\n");
 	}
 	//the if-else statement addresses if the user input is 'q' or not.
     //if q is entered the system quits by returning 0, but if not PlayGuessingGame() is called.
 	//Now when the game ends, the player is prompted to choose either 'q' or 'r' (for replay)
     while(!done) {
         scanf(" %c", &c);

     	if (c == 'q') {
     		done = 1;
     		printf("Bye Bye!\n");
     		//it is important that we do not free the linked list until AFTER the game is over.
     		//if it is freed before the game ends or before replayMoves() is called, nothing will print because
     		//it will then be considered empty.
     		freeList(&list);
     	}
     	else if (c == 'r') {
     		//now, when the user inputs 'r,' they will see a delayed replay of all the moves made during the game.
     		//they are then asked to either q or press another key to continue and cannot replay again.
     		replayMoves(&list);

     		printf("Press 'q' to quit or any other key to continue:\n");

     	    scanf(" %c", &c);
     	    if (c == 'q') {
     	    	done = 1;
     	  		printf("Bye Bye!\n");
     	    }
     	    else {
     	   		PlayConnectFour(&list);
     	      }
     	}
     	else {
     		PlayConnectFour(&list);
     	    printf("Press 'q' to quit or 'r' to replay or any other key to continue:\n");
     	}
     }

     return 0;
 } //last main function bracket
