#include <Arduino_FreeRTOS.h>
#include <semphr.h>
#include "led.h"

#define LED1 30
#define LED2 32
#define LED3 34

int medio_periodo_ms;

void setup() {
  
    Serial.begin(9600);
    Serial.print("Seleccione el periodo (milisegundos):\t");
    while (!Serial.available()) {}

    medio_periodo_ms = (int) Serial.parseFloat();
    Serial.print(medio_periodo_ms);
    Serial.println(" ms.");

    for (int i = 0; i < 3; ++i) {
        Serial.print("Comenzando en ");
        Serial.print(3 - i);
        Serial.println("...");
        delay(1000);
    }
    
    xTaskCreate(TareaA, "TareaA", 128, NULL, 1, NULL);
    xTaskCreate(TareaB, "TareaB", 128, NULL, 2, NULL);
    xTaskCreate(TareaC, "TareaC", 128, NULL, 3,NULL);

    vTaskStartScheduler();
    
}

static void TareaA(void* params) {

    led led1(LED1);
    int t = medio_periodo_ms;
    
    while(true) { 
        led1.toggle();
        vTaskDelay(t / portTICK_PERIOD_MS);
    }
}

static void TareaB(void* params) {

    
    led led2(LED2);
    int t = medio_periodo_ms / 2;
      
    while(true) {
        led2.toggle();
        vTaskDelay(t / portTICK_PERIOD_MS);
    }
}

static void TareaC(void* params) {

    led led3(LED3);
    int t = medio_periodo_ms / 4;
    
    while(true) {
        led3.toggle();
        vTaskDelay(t / portTICK_PERIOD_MS);
    }
}

void loop() {}
