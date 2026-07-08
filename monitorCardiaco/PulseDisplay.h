#ifndef PULSE_DISPLAY_H
#define PULSE_DISPLAY_H

#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

class PulseDisplay {
private:
    Adafruit_SSD1306& _oled;
    int _prevY;
    void scrollLeft();

public:
    PulseDisplay(Adafruit_SSD1306& oledInstance);
    void begin();
    void updateGraph(int filtValue, int bpm);
};

#endif