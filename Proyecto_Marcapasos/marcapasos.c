#include <stdio.h>
#include <sys/time.h>

#include "marcapasos.h"

#define TOTAL_MUESTRAS 3
#define FREC_NORMAL 60


void sensorActividadCardiaca(void) {

    double start_t, delta_t, BPM;
    double frecBPM[TOTAL_MUESTRAS];
    int indice = 0;

    while (1) {

        start_t = tiempoSegundos();
        getchar();
        delta_t = (tiempoSegundos() - start_t);
        BPM = 60 / delta_t; // Latidos por minuto
        frecBPM[indice++ % TOTAL_MUESTRAS] = BPM;

        if (indice > 5) {
            double f_prom = analizarFrecuenciaCardiaca(frecBPM, TOTAL_MUESTRAS);
            printf("%d. Frecuencia cardiaca promedio: %.1f BPM", indice, f_prom);
        }
        else {
            printf("Recopilando datos iniciales... (%d/5)", indice);
        }

    }

    return;

}

double analizarFrecuenciaCardiaca(double *arr, int n) {

    double frecPromedio = promedioArreglo(arr, n);

    if (frecPromedio < FREC_NORMAL) {
        printf("¡Frecuencia cardiaca por debajo de lo normal!");
    }

    return frecPromedio;
    
}


/*

    <--- Funciones auxiliares --->

*/

double tiempoSegundos(void) {

    struct timeval tv;
    gettimeofday(&tv,NULL);
    return (double) tv.tv_sec + tv.tv_usec/1e6;

}

double promedioArreglo(double *a, int n) {
    double suma = 0;
    for (int i = 0; i < n; ++i) {
        suma += a[i];
    }
    return suma / (double) n;
}