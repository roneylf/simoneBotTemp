#include "SmartInput.h"

SmartInput::SmartInput(int pin, unsigned long timeRead, bool pullup, bool inverseLogic)
{
    this->pin = pin;
    this->timeRead = timeRead;
    this->inverseLogic = inverseLogic;
    pinMode(pin, pullup ?INPUT_PULLUP  : INPUT_PULLUP);
}
SmartInput::SmartInput(int pin, unsigned long timeRead, bool inverseLogic)
{
    this->pin = pin;
    this->timeRead = timeRead;
    this->inverseLogic = inverseLogic;
    pinMode(pin, INPUT_PULLUP);
}
SmartInput::SmartInput(int pin, unsigned long timeRead)
{
    this->pin = pin;
    this->timeRead = timeRead;
    pinMode(pin, INPUT_PULLUP);
}
SmartInput::SmartInput(int pin)
{
    this->pin = pin;
    pinMode(pin, INPUT_PULLUP);
}
SmartInput::SmartInput()
{
   // this->pin = pin;
   // pinMode(pin, INPUT_PULLUP);
}

bool SmartInput::read()
{
    if (digitalRead(pin) != inverseLogic)
    {
        if (last > 1)
        {
            if (last + timeRead < millis())
            {
                last = 0;
            }
        }
        else
        {
            last = millis();
            return false;
        }
        if (!block)
        {
            block = true;
            return true;
        }
    }
    else
    {
        if (last > 1)
        {
            last = 0;
        }
        if (block)
        {
            block = false;
        }
    }
    return false;
}
bool SmartInput::readConst()
{
    return (digitalRead(pin) != inverseLogic);
}