# 191CV210_CS252_PROJECT

Details/Documentation for individual project constituting the 
following problem statements from the 10th edition of Silberschatz book - 

*  4.23 - 
Write a multithreaded program that outputs prime numbers. 
This program should work as follows: The user will run the program and will enter a number on the command line. 
The program will then create a separate thread that outputs all the prime numbers less than or equal to the number entered by the user.

Reference/Credits for solution - https://stackoverflow.com/questions/44881796/display-the-prime-numbers-using-multi-threading-in-c

Brief - A printprimes function is created which is passed as a start routine for threads generated. Thread generation and execution fills the vector primes with 0(if index is not prime) and 1(if index is prime), which lastly helps in printing all the primes required by a simple for loop. 


*  7.16 - 
The C program stack-ptr.c (available in the source-code download) contains an implementation of a stack using a linked list. 
An example of its use is as follows: 
StackNode *top = NULL; push(5, &top); push(10, &top); push(15, &top); int value = pop(&top); value = pop(&top); value = pop(&top); 
This program currently has a race condition and is not appropriate for a concurrent environment. Using Pthreads mutex locks (described in Section 7.3.1), 
fix the race condition.

Reference/Credits for solution - https://cs241.cs.illinois.edu/coursebook/Synchronization

Brief - A double datatype stack implementation is used here to solve the problem. Push and Pop functions are defined such that when one thread is running the pop function, the other is locked for a snippet of the scope of function in order to eliminate the race condition. This is done using Mutex Locks. Lastly, the main function simply demonstrates how the stack will work.(Not written a multithreaded solution for the for the problem but this implementation of a stack will work and eliminate the race condition in a concurrent environment)
