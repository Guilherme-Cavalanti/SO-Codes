#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

//contador
int count;

//semáforos
typedef int semaphore; 
semaphore mutex0;

semaphore mutex1;


//Função executada dentro da seção crítica
void secao_critica (int threadid){
    int id = (int) threadid;
    printf("(%d) Secao Critica, count = %i\n",id, count);
    count += 1;
}

//Função de espera
void secao_nao_critica (int threadid) {
    int id = (int) threadid;
    printf("(%d) Esperando\n",id);
}

//Wait e Signal
void wait (semaphore* S, int id){
    while(*S <= 0);
    secao_critica(id);
    *S = 0;
    return;
}
void signal (semaphore* S){
*S = 1;
}

// Processo 0
void *p0 (void *threadid){
    int id = (int) threadid;
    while (1) {
        // while(mutex != 0);
        wait(&mutex0, id);
        // secao_critica(id);
        signal(&mutex1);
        secao_nao_critica(id);
    }
}

// Processo 1
void *p1 (void *threadid){
    int id = (int) threadid;
    while (1) {
        // while(mutex != 0);
        wait(&mutex1, id);
        // secao_critica(id);
        signal(&mutex0);
        secao_nao_critica(id);
    }
}

// Main
void main(){
    mutex0 = 1;
    mutex1 = 0;
    count = 0;
    int num; //indetificador da thread
    pthread_t t1, t2;
    int numThread; // armazena o retorno da pthread_create
    num = 0;
    numThread = pthread_create(&t1, NULL, p0, (void *)num);
    num = 1;
    numThread = pthread_create(&t2, NULL, p1, (void *)num);
    pthread_join(t1,NULL); //Espera a t1 acabar
    pthread_join(t2,NULL); // Espera a t2 acabar
}

