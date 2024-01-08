#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

//Variáveis globais do programa
int count;
int vez;

//Função executada dentro da seção crítica
void secao_critica (int threadid){
    int id = (int) threadid;
    printf("(%d) Secao Critica, count = %i\n",id, count);
    count += 1;
    //pthread_exit(NULL);
}

//Função de espera
void secao_nao_critica (int threadid) {
    int id = (int) threadid;
    printf("(%d) Esperando\n",id);
    //pthread_exit(NULL);
}

void *p0 (void *threadid){
    int id = (int) threadid;
    int outro = 1;
    while (1) {
        while(vez != 0) ;
        secao_critica(id);
        vez = outro;
        secao_nao_critica(id);
    }
}
void *p1 (void *threadid){
    int id = (int) threadid;
    int outro = 0;
    while (1) {
        while(vez != 1) ;
        secao_critica(id);
        vez = outro;
        secao_nao_critica(id);
    }
}

void main(){
    vez = 0;
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

