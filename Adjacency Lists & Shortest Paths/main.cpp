//main.cpp file

//this is the only include statement needed as include statements are declared in main.h
#include "main.h"
#define NIL -1
#include <string.h>

//main function:
int main(int argc, char **argv){
    HEAP *heap;
    Graph* G;
    pNODE* ADJ;
    pVERTEX* V;
    int capacity = -1;
    double key, anotherKey;
    int returnV;
    int n;              
    int m, source, destination;
    char Word[120];
    FILE *fp;
    int recentSource = -1;
    int flag;   //used for valid executions
    int graphType; //used to read in argv[2]
    bool pathComputed = false;
    double** w;     //weight
    
    
    //if the execution is not valid:    
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <ifile> <ofile> <flag>\n", argv[0]);
        exit(0);
    } 
    
    //argv[1] IS USED TO OPEN THE FILE IN READ MODE
    fp = fopen(argv[1], "r");
    if (!fp){
        fprintf(stderr, "Error: cannot open file %s\n", argv[1]);
        exit(0);
    }
        
    //READING IN IF THE GRAPH IS DIRECTED OR UNDIRECTED AND ASSIGNING VALUES TO 0 OR 1
    if (strcmp(argv[2], "DirectedGraph") == 0) {
        graphType = 0;
    } else if (strcmp(argv[2], "UndirectedGraph") == 0){
        graphType = 1;
    } else {
        fprintf(stderr, "Error: invalid graph type");
    }
    
    //***************************FLAG HANDELING
    try {
        flag = stoi(argv[3]);
    } catch (const exception& e) {
        fprintf(stderr, "Provide a flag value\n");
        fclose(fp);
        exit(0);
    }
    
    //handle the case in which there is not a valid execution
    //PROGRAM SHOULD NOT TERMINATE
    //<Flag> is either 1 or 2
    if (flag != 1 && flag != 2) {
        fprintf(stderr, "./PJ3 <InputFile> <GraphType> <Flag>\n");
        fclose(fp);
        exit(0);
    }

    read(&ADJ, &V, argv[1], flag, graphType);       //read in values
	 
	//VALUES N AND M ARE READ IN FROM THE FILE
    //these values are in the first line in the txt file
    if(fscanf(fp, "%d %d", &n, &m) != 2){
        fprintf(stderr, "Error: Invalid input format\n");
        fclose(fp);
        exit(0);
    }
    
    //while loop: responsible for reading in commands
    while (1) {
        returnV = nextInstruction(Word, &key, &anotherKey); //TAKES IN INFORMATION
      
        //if there is invalid instruction, print the following
        if (returnV == 0){
            fprintf(stderr, "Invalid instruction.\n");
            continue;
        }
     
        //if the word is stop, terminate the program
        if (strcmp(Word, "Stop")==0){
            return 0; //terminates the program
        }


      //if the command is PrintADJ, do the following
        if (strcmp(Word, "PrintADJ")==0){
	        printADJList(ADJ, n);                           //call print function
            continue;
        }

        //if the command is SinglePair, do the following
	    if (strcmp(Word, "SinglePair")==0) {
	        //initHeap(capacity);
	        dijkstra(V, ADJ, n, (int) key, (int) anotherKey); //call function
	        pathComputed = true;
	        recentSource = (int) key; // Update recentSource here

	        continue;
	    }
	    
	    
	    //if the command is SingleSource, do the following
	    if (strcmp(Word, "SingleSource")==0) {
	        singleSource(V, ADJ, n, (int) key);    //call function
	        pathComputed = true;
	        recentSource = (int) key; // Update recentSource here
	        continue;
	    }
	    
	    /*
	    //if the command is PrintPath, do the following
	    //source is key and anotherkey is destination
	    if (strcmp(Word, "PrintPath")==0) {
	        if (pathComputed == true){
	            printPath(V, (int) key, (int) anotherKey);    //call function
	        } else {
	            pathComputed = false;
	           // fprintf(stdout, "There is no path from %d to %d.\n", (int) key, (int) anotherKey);
	        }
	        continue;
	    }
	    */
	    // If the command is PrintPath, do the following
// Source is key and anotherKey is destination
if (strcmp(Word, "PrintPath") == 0) {
    if (pathComputed) {
        // Check if the recentSource matches the key
        if (recentSource == (int)key) {
            printPath(V, (int)key, (int)anotherKey); // Call function only if recentSource matches key
        }
        // If recentSource does not match key, continue to next iteration
        else {
            continue;
        }
    } else {
        pathComputed = false;
        // fprintf(stdout, "There is no path from %d to %d.\n", (int)key, (int)anotherKey);
    }
    continue;
}

	    
	    //if the command is PrintLength, do the following
	    if (strcmp(Word, "PrintLength")==0) {
	        int s, t;
	        //fscanf(stdin, "%d %d", &s, &t);
	        /*
	        if (source != s || destination != t) {
	            fprintf(stdout, "There is no path from %d to %d.\n", s, t);
	        }
	        */
	        printLength(V, n, (int) key, (int) anotherKey);   //call function
	        
	        continue;
	    }
    }

    
}
