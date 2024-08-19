# C-Programming
This repository contains code pertaining to C/C++.
In CSE 220 and CSE 240, emphasis is put on the procedural, object-oriented, functional and declarative languages, as well as systems programming. 
In CSE 310, Data Structures and Algorithms, emphasis is focused on advanced data structures and algorithms, including stacks, queues, trees (B, B+, AVL), graphs, as well as searching for graphs, hashing, external sorting.

In the Linked Lists folder, find a connect four game that utilizes linked lists to add each player to a leaderboard. Linked Lists and structs are used to add each player's information to the array. File input and output is additionally used to write the leaderboard to a file, and read it if available.

In the binary search tree folder, a 2-player connect four game was created. The player has the opportunity to 'rerun' the game which utilized sleep() to replay all of the moves made throughout the game. A BST is used to store the board after each move.

# Data Structures and Algorithms Projects:
- File I/O: Project one deals with the basic handling of file IO. The instructions are as follows: for this project, you should have four modules, with the header files named data_structures.h, util.h, list_read.h, list_write.h, and the implementation files list_read.cpp, list_write.cpp, main.cpp, and util.cpp. The program should be able to handle upwards of 20 test cases.
- Min Heaps: Project 2 deals with the development of the following min heap functionalities: Heapify, BuildHeap, ExtractMin, DecreaseKey, and Insertion. When writing the min heap data structure, A[i] should be either of type ELEMENT* or ELEMENT, depending on your specific implementation. ELEMENT is a struct that includes a field named 'key' of type double, along with other
fields. Consequently, the heap order is determined by either A[i]->key or A[i].key, depending on your chosen implementation.
- Adjacency Lists, Heaps, Stacks & Shortest Paths: This project is the essential part of a navigation system. It reads in a directed graph or an undirected graph G with n vertices and m edges from a file specified by the command-line (with proper arguments). It then takes corresponding actions for given instructions from stdin. Besides the Stop instruction, valid instructions include
  α: graph printing instruction (PrintADJ)
  β: path computation instructions (SinglePair and SingleSource)
  γ: length/path printing instructions (PrintLength and PrintPath)
Both SinglePair and SingleSource path computations should have worst-case time complexity O(m log n). Path printing should have worst-case time complexity O(n). Length printing should have worst-case time complexity O(1). Memory should be allocated when needed, and released when it is no longer needed. Memory leaks should be avoided.
Development of following modules:
  • a module for various data structures, with header file named data structures.h
  • a module for min-heap, with header file named heap.h and implementation file named heap.cpp
  • amoduleforstack,withheaderfilenamedstack.handimplementationfilenamedstack.cpp
  • a module for graph algorithms, with header file named graph.h and implementation file
  named graph.cpp
  • amoduleforutilities,withheaderfilenamedutil.handimplementationfilenamedutil.cpp
  • and the main program, with header file named main.h and implementation file named main.cpp
