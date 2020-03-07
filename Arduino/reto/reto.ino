#include <Arduino_FreeRTOS.h>
#include <semphr.h>

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
    xTaskCreate(TareaB, "TareaB", 128, NULL, 1, NULL);
    xTaskCreate(TareaC, "TareaC", 128, NULL, 1,NULL);

    vTaskStartScheduler();
    
}

static void TareaA(void* params) {

    int t = medio_periodo_ms;
    static float voltaje;
    
    while(true) { 
        int lectura = analogRead(A0);
        voltaje = 5 * (float) lectura / 1023.0;
        Serial.print("Voltaje potenciómetro 1: ");
        Serial.println(voltaje, 3);
        vTaskDelay(t / portTICK_PERIOD_MS);
    }
}

static void TareaB(void* params) {

    int t = medio_periodo_ms / 2;
    static float voltaje;
    
    while(true) { 
        int lectura = analogRead(A1);
        voltaje = 5 * (float) lectura / 1023.0;
        Serial.print("Voltaje potenciómetro 2: ");
        Serial.println(voltaje, 3);
        vTaskDelay(t / portTICK_PERIOD_MS);
    }
}

static void TareaC(void* params) {

    int t = medio_periodo_ms / 4;
    static float temperatura;
    
    while(true) { 
        int lectura = analogRead(A2);
        temperatura = map(lectura, 176, 9, 27, 200); 
        Serial.print("Temperatura sensor 3: ");
        Serial.println(temperatura);
        vTaskDelay(t / portTICK_PERIOD_MS);
    }
}

void loop() {}
