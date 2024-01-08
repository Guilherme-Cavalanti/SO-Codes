#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
 
void *PrintHello(void *threadid){//função a ser executada quando uma thread for criada
  long id;
  id = (long)threadid;//conversão de void pra long
  printf("Thread %ld: Hello World\n", id);
  pthread_exit(NULL); //finalização da thread
}

 int main(){
    pthread_t t1, t2, t3; //criando t1 e t2 do tipo thread
    int create; //variável que recebe o retorno da função pthread_create()
    long num; //identificador da thread
 
    num = 1;
    create = pthread_create(&t1, NULL, PrintHello, (void *)num); //criando thread 1
 
    num = 2;
    create = pthread_create(&t2, NULL, PrintHello, (void *)num); //criando thread 2
    pthread_join(t1,NULL); //Espera a t1 acabar
    pthread_join(t2,NULL); // Espera a t2 acabar
 
    return 0;
}
