i#include <Arduino.h>

// BCD input pins to 7447
#define PIN_A 2   // LSB
#define PIN_B 3
#define PIN_C 4
#define PIN_D 5   // MSB

void disp_7447(int d, int c, int b, int a)
{
    digitalWrite(PIN_A, a);
    digitalWrite(PIN_B, b);
    digitalWrite(PIN_C, c);
    digitalWrite(PIN_D, d);
}

// Display number with DON'T CARE handling
void displayBCD(int num)
{
    if (num >= 0 && num <= 9)
    {
        // Valid BCD
        disp_7447(
            (num >> 3) & 1,
            (num >> 2) & 1,
            (num >> 1) & 1,
            (num >> 0) & 1
        );
    }
    else
    {
        // DON'T CARE (10–15)
        // Blank display
        disp_7447(0, 0, 0, 0);
    }
}

void setup()
{
    pinMode(PIN_A, OUTPUT);
    pinMode(PIN_B, OUTPUT);
    pinMode(PIN_C, OUTPUT);
    pinMode(PIN_D, OUTPUT);
}

void loop()
{
    for (int i = 0; i < 16; i++)
    {
        displayBCD(i);
        delay(1000);
    }
}
