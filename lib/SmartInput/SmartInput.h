#pragma once
#include <Arduino.h>
class SmartInput{
private:
    int pin;
    bool block;
    unsigned long last;
    int cont;
    bool inverseLogic = false;
public:
    unsigned long timeRead = 0;
    // PIN TIME PULLUP INVERSE_LOGIC
    SmartInput(int pin, unsigned long timeReads, bool pullup , bool inverseLogic );
    // PIN TIME INVERSE_LOGIC
    SmartInput(int pin, unsigned long timeRead, bool inverseLogic  );
    // PIN TIME 
    SmartInput(int pin, unsigned long timeRead);
    // PIN 
    SmartInput(int pin);
    SmartInput();
    bool read();
    bool readConst();
};