#include "Arduino.h"

#define LED_B 2
#define PWM1_Ch 0
#define PWM1_Res 8
#define PWM1_Freq 1000

String command;

int value = 0;

void setup()
{

    Serial.begin(115200);

    ledcAttachPin(LED_B, PWM1_Ch);
    ledcSetup(PWM1_Ch, PWM1_Freq, PWM1_Res);
    ledcWrite(PWM1_Ch, 128);
}

void loop()
{

    if (Serial.available())
    {
        command = Serial.readStringUntil('\n');
        value = command.toInt();

        ledcWrite(PWM1_Ch, value);

        Serial.println(value);
    }
}
