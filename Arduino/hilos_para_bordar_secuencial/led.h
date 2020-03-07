#include <Arduino.h>

class led {
    public:
        led(int pin);
        void toggle(void);
        void apagar_led(void);
        void encender_led(void);
    private:
        int _led_pin; 
        bool _status;
};

led::led(int pin) {
    _led_pin = pin;
    pinMode(pin, OUTPUT);
    apagar_led();
}

void led::apagar_led(void) {
    digitalWrite(_led_pin, LOW);
    Serial.print("Led ");
    Serial.print(_led_pin);
    Serial.println(" apagado.");
}

void led::encender_led(void) {
    digitalWrite(_led_pin, HIGH);
    Serial.print("Led ");
    Serial.print(_led_pin);
    Serial.println(" encendido.");
}

void led::toggle(void) {
    if (digitalRead(_led_pin)) {
        apagar_led();
    }
    else {
        encender_led();
    }
}
