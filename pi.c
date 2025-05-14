#include<stdio.h>
#include<wiringPi.h>

#define SENSOR_PIN //GPIOピンの番号を入れる
#define LIGHT_PIN //GPIOピンの番号を入れる

//起動確認処理
void check(int times) {
    delay(1000);
    for (int i = 0; i < 3; i++){
        digitalWrite(LIGHT_PIN, HIGH);
        delay(500);
        digitalWrite(LIGHT_PIN, LOW);
        delay(500);
    }
    printf("Ready\n");
}

int main(void) {
    wiringPiSetupGpio ();
    pinMode (SENSOR_PIN, INPUT);
    pinMode (LIGHT_PIN, OUTPUT);

    check(1);

    while (1) {
        if (digitalRead(SENSOR_PIN) == HIGH) {
            digitalWrite(LIGHT_PIN, HIGH); //ライト点灯
        } else {
            digitalWrite(LIGHT_PIN, LOW); //ライト消灯
        }
        delay(100);
    }

    return 0;
}
