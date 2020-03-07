#include <Arduino_FreeRTOS.h>
#include <semphr.h>

#define USAR_SEMAFORO true

#if USAR_SEMAFORO
  SemaphoreHandle_t s;
#endif

void setup() {
  
    Serial.begin(9600);
    
    #if USAR_SEMAFORO
      s = xSemaphoreCreateMutex();
    #endif
    
    xTaskCreate(imprimir, "imprimir1", 128, "Perro", 2, NULL);
    xTaskCreate(imprimir, "imprimir1", 128, "Gato", 1, NULL);
    xTaskCreate(imprimir, "imprimir1", 128, "Jirafa", 3, NULL);

    vTaskStartScheduler();
    
}

void loop() {}

void imprimir(void *param) {

    char* msg = (char*) param;
    while (true) {
        #if USAR_SEMAFORO
          if (xSemaphoreTake(s, (TickType_t) 1) == pdTRUE) {
              Serial.println(msg);
              xSemaphoreGive(s);
          }
        #else
          Serial.println(msg);
        #endif
        vTaskDelay(18 / portTICK_PERIOD_MS);
    }
}
