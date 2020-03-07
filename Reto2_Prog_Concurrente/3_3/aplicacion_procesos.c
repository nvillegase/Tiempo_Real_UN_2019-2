#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

void tarea_A(void);
void tarea_B(void);


void main(void) {

    pid_t pid;
    pid = fork();

    if (pid == 0) { // Proceso hijo
        printf("Proceso con PID %d ejecutando tarea A\n", getpid());
        tarea_A();
    }
    else {
        printf("Proceso con PID %d ejecutando tarea B\n", getpid());
        tarea_B();
    }
}


void tarea_A(void) {
    unsigned long suma = 0;
    printf("Ejecutando la tarea A:\nSumar el primer millón de números positivos\n");
    for (int i = 1; i <= 1000000; ++i) {
        suma += i;
    }
    printf("Terminada la tarea A. Resultado: %lu\n", suma);
}


void tarea_B(void) {
    unsigned long suma = 0;
    printf("Ejecutando la tarea B:\nCalcular la suma del primer millón de números impares\n");
    for (int i = 0; i <= 2000001; ++i) {
        if (i % 2 == 1) {
            suma += i;
        }
    }
    printf("Terminada la tarea B. Resultado: %lu\n", suma);
}

