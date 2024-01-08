#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

//Função de sleep
void sleep(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock())
        ;
}
//semáforos
typedef int semaphore;

semaphore garfos[5];

//filósofos
typedef int filosofo;

filosofo filosofos[5];
// Função de comer
void comer (int threadid){
    int id = (int) threadid;
    printf("Filosofo %i comendo\n",id);
}

// Função de pensar
void pensar (int threadid) {
    int id = (int) threadid;
    printf("Filosofo %d voltou a pensar\n",id);
}

//Wait e Signal
void wait (semaphore* S, int id){
    while(*S <= 0);
    *S = 0;
    return;
}
void signal (semaphore* S){
*S = 1;
}

void *processo(void *threadid){
    int id = (int) threadid;
    while (1) {
        wait(&garfos[id], id);
        wait(&garfos[(id+1)%5], id);
        comer(id);
        signal(&garfos[id]);
        signal(&garfos[(id+1)%5]);
        pensar(id);
        sleep(100);
    }
}
void main(){

//Valores inicias para os garfos são 1
for(int i = 0; i<5; i++)garfos[i]=1;

int num; //indetificador da thread
    pthread_t t1, t2, t3, t4, t5;
    int numThread; // armazena o retorno da pthread_create
    //Criando as threads
    num = 0;
    numThread = pthread_create(&t1, NULL, processo, (void *)num);
    num = 1;
    numThread = pthread_create(&t2, NULL, processo, (void *)num);
    num = 2;
    numThread = pthread_create(&t3, NULL, processo, (void *)num);
    num = 3;
    numThread = pthread_create(&t4, NULL, processo, (void *)num);
    num = 4;
    numThread = pthread_create(&t5, NULL, processo, (void *)num);
     pthread_join(t1,NULL); //Espera a t1 acabar
    pthread_join(t2,NULL); // Espera a t2 acabar
     pthread_join(t3,NULL); //Espera a t3 acabar
    pthread_join(t4,NULL); // Espera a t4 acabar
     pthread_join(t5,NULL); //Espera a t5 acabar
}