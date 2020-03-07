#include <Arduino_FreeRTOS.h>
#include <semphr.h>

#define USAR_SEMAFORO false

#if USAR_SEMAFORO
  SemaphoreHandle_t s;
#endif

void setup() {
  
    Serial.begin(115200);
    
    #if USAR_SEMAFORO
      s = xSemaphoreCreateCounting(1, 1);
    #endif
    
    xTaskCreate(imprimir, "imprimir1", 128, "Hola", 1, NULL);
    xTaskCreate(imprimir, "imprimir1", 128, "Chao", 1, NULL);
    xTaskCreate(imprimir, "imprimir1", 128, "Perro", 1, NULL);

    vTaskStartScheduler();
    
}

void loop() {}

void imprimir(void *param) {

    char* msg = (char*) param;
    while (true) {
        #if USAR_SEMAFORO
          if (xSemaphoreTake(s, (TickType_t) 10) == pdTRUE) {
              Serial.println(msg);
              xSemaphoreGive(s);
          }
        #else
          Serial.println(msg);
        #endif
        vTaskDelay(3000 / portTICK_PERIOD_MS);
    }
}
