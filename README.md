# 191CV210_CS252_PROJECT

Details/Documentation for individual project constituting the 
following problem statements from the 10th edition of Silberschatz book - 

*  4.23 - 
Write a multithreaded program that outputs prime numbers. 
This program should work as follows: The user will run the program and will enter a number on the command line. 
The program will then create a separate thread that outputs all the prime numbers less than or equal to the number entered by the user.

Reference/Credits for solution - https://stackoverflow.com/questions/44881796/display-the-prime-numbers-using-multi-threading-in-c


*  7.16 - 
The C program stack-ptr.c (available in the source-code download) contains an implementation of a stack using a linked list. 
An example of its use is as follows: 
StackNode *top = NULL; push(5, &top); push(10, &top); push(15, &top); int value = pop(&top); value = pop(&top); value = pop(&top); 
This program currently has a race condition and is not appropriate for a concurrent environment. Using Pthreads mutex locks (described in Section 7.3.1), 
fix the race condition.

Reference/Credits for solution - https://cs241.cs.illinois.edu/coursebook/Synchronization
