/*
 * game.c
 *	This file contains code creating a guessing game between the user and the computer.
 * The rand function is utilized here to give a different number the user must guess each time.
 *      Author: kristabrehm
 */

//Include import statements
#include <math.h>		//used for math functions
#include <stdio.h>		//Input Output handling
#include <stdlib.h>		//rand() function is in this library

int GetGuess() {
	//Variable Declaration & Initialization:
	//this is the input from the user (their guess)
	int num;
	num = scanf("%d", &num);

	//Return that number
	return num;
}


void PlayGuessingGame() {
	//Variable Declaration & Initialization:
	//we ultimately need to get the square root of the random number
	//We store our range of numbers (10-100 inclusive) in variables HIGH and LOW to later use in the calculation
	//A variable is then used to calculate the squart root of the random number using the inclusive range
	//we also need a variable to call the getGuess() function and store the num

	int HIGH = 100;
	int LOW = 10;
	int number = LOW + (rand() % (HIGH - LOW));
	double sqrtNum = sqrt(number);

	int userGuess;


	printf("%f is the square root of what number?", sqrtNum);
	userGuess = GetGuess();

	//A do-while loop can be used to to repeat the guessing process until the correct
	//number is guessed (in that case break is used to quit the program).
	//In the do-while loop, there are if and else if statements used to correlate to if the
	//user guess is greater/less/equal to the target number.

    do {
        scanf("%d", &userGuess);
        if (userGuess == number) {
    		printf("you got it baby!\n");
    		break;
        }

        if (userGuess > number) {
    		printf("too high, guess again:\n");
        }

        else if (userGuess < number){
    		printf("too low, guess again:\n");
        }

    } while (userGuess != number);
}


//This is the main function. The welcome statement is presented in the console and as long as 'q' is
//not input by the user than PlayGuessingGame() is executed.
int main() {
	//Variable Declaration & Initialization:
	//we need a char variable to store the user's input
	char c;

    printf("Welcome! Press 'q' to quit or any other key to continue:\n");
    scanf(" %c", &c);

	//the if-else statement addresses if the user input is 'q' or not.
    //if q is entered the system quits by returning 0, but if not PlayGuessingGame() is called.

    if (c == 'q') {
    	printf("Bye Bye!\n");
        return 0;
    }
    else {
    	PlayGuessingGame();
    }

    return 0;
}
