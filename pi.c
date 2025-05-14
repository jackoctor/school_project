#include<stdio.h>
#include<wiringPi.h>

#define SENSOR_PIN //GPIOピンの番号を入れる
#define LIGHT_PIN //GPIOピンの番号を入れる

int main(void) {
    wiringPiSetupGpio ();
    pinMode (SENSOR_PIN, INPUT);
    pinMode (LIGHT_PIN, OUTPUT);

    while (1) {
        if (digitalRead(SENSOR_PIN) == HIGH) {
            digitalWrite(LIGHT_PIN, HIGH); //ライト点灯
        } else {
            digitalRead(LIGHT_PIN, LOW); //ライト消灯
        }
        delay(100);
    }

    return 0;
}