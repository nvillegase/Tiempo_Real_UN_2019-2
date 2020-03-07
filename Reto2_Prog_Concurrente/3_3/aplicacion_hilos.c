#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>


void* tarea_A(void* arg) {
    unsigned long suma = 0;
    printf("Ejecutando la tarea A:\nSumar el primer millón de números positivos\n");
    for (int i = 1; i <= 1000000; ++i) {
        suma += i;
    }
    printf("Terminada la tarea A. Resultado: %lu\n", suma);
    pthread_exit((void*) arg);
}


void* tarea_B(void* arg) {
    unsigned long suma = 0;
    printf("Ejecutando la tarea B:\nCalcular la suma del primer millón de números impares\n");
    for (int i = 0; i <= 2000001; ++i) {
        if (i % 2 == 1) {
            suma += i;
        }
    }
    printf("Terminada la tarea B. Resultado: %lu\n", suma);
    pthread_exit((void*) arg);
}

void main(void) {

    pthread_t hilos[2];

    unsigned long long tid;

    for (tid = 0; tid < 2; ++tid) {
        if (tid == 0) {
            pthread_create(&hilos[tid], NULL, &tarea_A, (void *)tid);
        }
        else {
            pthread_create(&hilos[tid], NULL, &tarea_B, (void *)tid);
        }
    }

    void *status;
    for (tid = 0; tid < 2; ++tid) {
        pthread_join(hilos[tid], &status);
    }

    pthread_exit(NULL);

}


