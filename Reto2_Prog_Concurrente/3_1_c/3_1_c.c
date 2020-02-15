#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>

#define MAX_COUNT 20

char *barras[5] = {"*", "**", "***", "****", "*****"};

void ChildProcess(void);
void ParentProcess(void);

void main(void) {
    pid_t pid;
    pid = fork();
    if (pid == 0) {
        ChildProcess();
    }
    else {
        ParentProcess();
    }
}

void ChildProcess(void) {
    int i;
    for (i = MAX_COUNT; i > 0; --i) {
        printf("\t\th-%s\n", barras[i % 5]);
        sleep(i % 5);
    
    }
    printf("   *** Fin proceso hijo ***\n");
}

void ParentProcess(void) {
    int i, h;
    for (i = 1; i <= MAX_COUNT; ++i) {
        printf("\t\tp-%s\n", barras[i % 5]);
        sleep(i % 5);
    }
    printf("   *** Fin del padre ***\n");
}