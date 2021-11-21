#include <stdio.h>
#include <pthread.h>
#include <iostream.h>
#include <stdlib.h>

int count=10;
double values[count];
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
//MUTEX OBJECT m

void push(double v)
{
  pthread_mutex_lock(&m);
  //dissallows the other thread to work in between this phase
  values[count++] = v;
  pthread_mutex_unlock(&m);
}
double pop()
{
  pthread_mutex_lock(&m);
  //dissallows the other thread to work in between this phase
  double v = values[--count];
  pthread_mutex_unlock(&m);
  return v;
}
int is_empty()
{
  pthread_mutex_lock(&m);
  //dissallows the other thread to work in between this phase
  int result = count == 0;
  pthread_mutex_unlock(&m);
  return result;
}

int main()
{
  count=0;
  push(10);
  push(20);
  push(30);
  push(40);
  push(50);
  pop();
  pop();
  cout<<is_empty();
  //returns false
}
