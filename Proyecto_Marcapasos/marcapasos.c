#include <stdio.h>
#include <sys/time.h>

#include "marcapasos.h"

#define TOTAL_MUESTRAS 3
#define FREC_NORMAL 60


void sensorActividadCardiaca(void) {

    double t_inicio, delta_t, BPM;
    double frecBPM[TOTAL_MUESTRAS];
    int indice = 0;

    printf("Presione la tecla ENTER para simular los latidos del corazón...\n");

    while (1) {

        t_inicio = tiempoSegundos();
        getchar();
        delta_t = (tiempoSegundos() - t_inicio);
        BPM = 60 / delta_t; // Latidos por minuto
        frecBPM[indice++ % TOTAL_MUESTRAS] = BPM;

        if (indice > 5) {
            analizarFrecuenciaCardiaca(frecBPM, TOTAL_MUESTRAS);
        }
        else {
            printf("Recopilando datos iniciales... (%d/5)", indice);
        }

    }

    return;

}

double analizarFrecuenciaCardiaca(double *arr, int n) {

    double frecPromedio = promedioArreglo(arr, n);
    printf("Frecuencia cardiaca promedio: %.1f BPM", frecPromedio);

    if (frecPromedio < FREC_NORMAL) {
        printf("\t ¡Aviso! Frecuencia cardiaca por debajo de lo normal");
    }
    else if (frecPromedio >= FREC_NORMAL) {
        printf("\t Frecuencia cardiaca en el rango normal...");
    }

    return frecPromedio;
    
}


/*

    <--- Funciones auxiliares --->

*/

double tiempoSegundos(void) {

    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (double) tv.tv_sec + tv.tv_usec/1e6;

}

double promedioArreglo(double *a, int n) {
    double suma = 0;
    for (int i = 0; i < n; ++i) {
        suma += a[i];
    }
    return suma / (double) n;
}