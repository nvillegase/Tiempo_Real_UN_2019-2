#include <stdio.h>
#include <sys/time.h>

#include "lib/kbhit.h"
#include "marcapasos.h"

#define TOTAL_MUESTRAS 5
#define FREC_NORMAL_BAJO 60
#define FREC_NORMAL_ALTO 100


void sensorActividadCardiaca(void) {

    double t_inicio, delta_t, BPM;
    double frecBPM[TOTAL_MUESTRAS];
    int indice = 0;
    short descarga;

    printf("Presione la tecla 'q' para salir, y cualquier tecla para simular los latidos del corazón...\n");

    while (1) {

        t_inicio = tiempoSegundos();
        descarga = 0;
        
        while(!kbhit()) {
            if (tiempoSegundos() - t_inicio > 1.5) {
                descargaElectrica();
                descarga = 1;
                break;
            }
        }

        if (descarga == 0) {
            char c = getchar();
            if (c == 'q') break;
        }

        delta_t = (tiempoSegundos() - t_inicio);
        BPM = 60 / delta_t; // Latidos por minuto
        frecBPM[indice++ % TOTAL_MUESTRAS] = BPM;

        if (indice > 5) {
            analizarFrecuenciaCardiaca(frecBPM, TOTAL_MUESTRAS);
        }
        else {
            printf("Recopilando datos ... (%d/%d)\n", indice, TOTAL_MUESTRAS);
        }

    }

    return;

}


double analizarFrecuenciaCardiaca(double *arr, int n) {

    double frecPromedio = promedioArreglo(arr, n);
    printf("Frecuencia cardiaca promedio: %.1f BPM", frecPromedio);

    if (frecPromedio < FREC_NORMAL_BAJO) {
        printf("\t ¡Aviso! Frecuencia cardiaca por debajo de lo normal\n");
    }
    else if (FREC_NORMAL_BAJO <= frecPromedio && frecPromedio <= FREC_NORMAL_ALTO) {
        printf("\t Frecuencia cardiaca en el rango normal...\n");
    }
    else {
        printf("\t ¡Aviso! Frecuencia cardiaca por encima de lo normal\n");
    }

    return frecPromedio;
    
}


void descargaElectrica(void) {
    printf("¡¡¡ Actividad cardiaca crítica, descarga eléctrica !!!\n");
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