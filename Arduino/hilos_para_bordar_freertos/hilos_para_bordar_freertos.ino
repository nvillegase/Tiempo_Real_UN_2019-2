#include <Arduino_FreeRTOS.h>
//#include "led.h"

#define LED1 30
#define LED2 32
#define LED3 13

void setup() {

    Serial.begin(9600);
    Serial.print("Seleccione el periodo (milisegundos):\t");
    while (!Serial.available()) {}

    int periodo_ms = (int) Serial.parseFloat();
    Serial.print(periodo_ms);
    Serial.println(" ms.");

    for (int i = 0; i < 3; ++i) {
        Serial.print("Comenzando en ");
        Serial.print(3 - i);
        Serial.println("...");
        delay(1000);
    }

    static int periodo_1 = (int) periodo_ms;
    static int periodo_2 = (int) 0.5 * periodo_ms;
    static int periodo_3 = (int) 0.25 * periodo_ms;
    
    xTaskCreate(tarea1, "tarea1", 64, (void *) periodo_1, 1, NULL);
    xTaskCreate(tarea2, "tarea2", 64, (void *) periodo_2, 1, NULL);
    xTaskCreate(tarea3, "tarea3", 64, (void *) periodo_3, 1, NULL);

}

void loop() {}

/*
led led1(LED1);
led led2(LED2);
led led3(LED3);
*/

static void tarea1(void* periodo) {
    // led led1(LED1);
    pinMode(LED1, OUTPUT);  
    while (true) {
        digitalWrite(LED1, HIGH);
        Serial.println("Led 1 on");
        vTaskDelay((int) periodo / portTICK_PERIOD_MS);
        digitalWrite(LED1, LOW);
        Serial.println("Led 1 off");
        vTaskDelay((int) periodo / portTICK_PERIOD_MS);
    }
}

static void tarea2(void* periodo) {
    pinMode(LED2, OUTPUT);  
    while (true) {
        digitalWrite(LED2, HIGH);
        Serial.println("Led 2 on");
        vTaskDelay((int) periodo / portTICK_PERIOD_MS);
        digitalWrite(LED2, LOW);
        Serial.println("Led 2 off");
        vTaskDelay((int) periodo / portTICK_PERIOD_MS);
    }
}

static void tarea3(void* periodo) {
    pinMode(LED3, OUTPUT);  
    while (true) {
        digitalWrite(LED3, HIGH);
        Serial.println("Led 3 on");
        vTaskDelay((int) periodo / portTICK_PERIOD_MS);
        digitalWrite(LED3, LOW);
        Serial.println("Led 3 off");
        vTaskDelay((int) periodo / portTICK_PERIOD_MS);
    }
}

/*
static void tarea2(void* periodo) {
    //led led2(LED2);
    while (true) {
        led2.toggle();
        vTaskDelay((int) periodo / portTICK_PERIOD_MS);
    }
}

static void tarea3(void* periodo) {
    //led led3(LED3);
    while (true) {
        led3.toggle();
        vTaskDelay((int) periodo / portTICK_PERIOD_MS);
    }
}
*/
