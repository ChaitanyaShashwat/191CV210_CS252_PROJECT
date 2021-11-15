#include <stdio.h>
#include <iostream.h>
#include <stdlib.h>
#include <pthread.h>
 
#define MAX_THREADS 2

std::vector<int> primes;

void *printprime(void *ptr, int N)
{
    int j, flag;
    int i = (int)ptr;//explicit conversion due to pointer being void
    while (i < N)
    {
        primes[i]=0;//initializing to remove junk values
     
        cout<<"Thread ID"<<pthread_self()<<"checking"<<i<<endl;
     
        flag = 0;
     
        for (j = 2; j <= i / 2; j++)
        {
            if (i % j == 0)
            {
                flag = 1;
                break;
                //when not prime 
            }
        }

        if (flag == 0 && (i > 1))
        {
            primes[i]=1;
            //if prime, it'll store 1(true) at index 
        }
        i += MAX_THREADS;
        //so that threads work one after the other or simply to reduce redundancy
    }
}

int main()
{
    pthread_t tid[MAX_THREADS] = {{0}};
    int count = 0,N;
    
    cout<<"Enter N(number till which primes have to be computed)";
    cin>>N;
    cout<<endl;
 
    //THREAD CREATION along with passing the printprime function
    for (count = 0; count < MAX_THREADS; count++)
    {
        cout<<"Creating threads "<<count;
        pthread_create(&tid[count], NULL, printprime, (void *)count);
    }

    cout<<endl;

    // The pthread_join() function waits for the thread specified by thread to terminate.
    for (count = 0; count < MAX_THREADS; count++)
    {
        pthread_join(tid[count], NULL);
    }

    for (count = 0; count < N; count++)
        if (primes[count] == 1)
        {
            cout<<count;
            //printing primes
        }

    return 0;
}
