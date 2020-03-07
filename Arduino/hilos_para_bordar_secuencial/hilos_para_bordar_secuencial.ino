#include "led.h"

#define LED1 30
#define LED2 32
#define LED3 34

int periodo_ms;
led led1(LED1);
led led2(LED2);
led led3(LED3);

void setup() {

    Serial.begin(9600);
    Serial.print("Seleccione el periodo (milisegundos):\t");
    while (!Serial.available()) {}

    periodo_ms = (int) Serial.parseFloat();
    Serial.print(periodo_ms);
    Serial.println(" ms.");

    for (int i = 0; i < 3; ++i) {
        Serial.print("Comenzando en ");
        Serial.print(3 - i);
        Serial.println("...");
        delay(1000);
    }

}

void loop() {

    static uint64_t timer_led_1 = 0, 
                    timer_led_2 = 0, 
                    timer_led_3 = 0;
    
    if (millis() - timer_led_1 >= periodo_ms) {
        timer_led_1 = millis();
        led1.toggle();
    }
    if (millis() - timer_led_2 >= 0.5*periodo_ms) {
        timer_led_2 = millis();
        led2.toggle();
    }
    if (millis() - timer_led_3 >= 0.25*periodo_ms) {
        timer_led_3 = millis();
        led3.toggle();
    }

}

