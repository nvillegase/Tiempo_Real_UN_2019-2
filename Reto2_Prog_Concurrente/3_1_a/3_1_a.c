#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <time.h>

#define MAX_COUNT 10
#define BUF_SIZE 120

void main(void) {
    pid_t pid;
    int i;
    int x = 0;

    char buf[BUF_SIZE];
    fork();
    pid = getpid();
    for (i = 1; i <= MAX_COUNT; i++) {
        x = rand();
        sprintf(buf, "Esta línea es de pid %d, valor = %d, valor de x es %d\n", pid, i, x);
        write(1, buf, strlen(buf));
    }
}
