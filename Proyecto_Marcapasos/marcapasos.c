#include <stdio.h>
#include <time.h>

#include "marcapasos.h"

void sensorActividadCardiaca(void) {

    static clock_t start_t;

    printf("Comenzando temporizador de 10 segundos...\n");

    for (int i = 10; i > 0; --i) {
        start_t = clock();
        while ((clock() - start_t) / CLOCKS_PER_SEC < 1.0) {}
        printf("%d\n", i);
    }

    printf("Listo!!\n");

    return;
}