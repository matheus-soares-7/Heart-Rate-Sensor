#ifndef HEART_PULSE_ANALYZER_H
#define HEART_PULSE_ANALYZER_H

#include <Arduino.h>

class HeartPulseAnalyzer {
private:
    int _pin;
    float _alpha;
    float _prevFilt;
    float _prevRaw;
    int _filtValue;
    int _maxVal;
    int _bpm;
    bool _pulse;
    unsigned long _lastBeat;
    unsigned long _lastMaxTime;

    void computeBPM();

public:
    HeartPulseAnalyzer(int pin, float alpha = 0.75);
    void update();
    int getFilteredValue() const;
    int getBPM() const;
    int getMaxVal() const;
};

#endif