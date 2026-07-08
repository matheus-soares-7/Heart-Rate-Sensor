#include "HeartPulseAnalyzer.h"

HeartPulseAnalyzer::HeartPulseAnalyzer(int pin, float alpha) {
    _pin = pin;
    _alpha = alpha;
    _prevFilt = 0;
    _prevRaw = 0;
    _filtValue = 0;
    _maxVal = 100;
    _bpm = 0;
    _pulse = false;
    _lastBeat = 0;
    _lastMaxTime = 0;
}

void HeartPulseAnalyzer::update() {
    int raw = analogRead(_pin);

    // Filtro passa-alta original
    float filt = _alpha * (_prevFilt + raw - _prevRaw);
    _prevFilt = filt;
    _prevRaw = raw;

    _filtValue = constrain((int)filt, -40, 100);

    computeBPM();
}

void HeartPulseAnalyzer::computeBPM() {
    int thresh = _maxVal - 10;
    unsigned long currTime = millis();

    // Detecção de pulso
    if (_filtValue > thresh && !_pulse) {
        _pulse = true;
        unsigned long interval = currTime - _lastBeat;

        if (interval > 300 && interval < 2000) {
            _bpm = 60000 / interval;
        }
        _lastBeat = currTime;
    }

    // Atualização dinâmica do valor máximo
    if (_filtValue > 30) {
        unsigned long interval = currTime - _lastMaxTime;
        if (interval > 300 && interval < 2000) {
            _maxVal = _filtValue;
        }
        _lastMaxTime = currTime;
    }

    // Reset do estado do pulso
    if (_filtValue < thresh - 10) {
        _pulse = false;
    }

    // Timeout (se passar de 3 segundos sem pulso, zera)
    if (millis() - _lastBeat > 3000) {
        _bpm = 0;
    }
}

int HeartPulseAnalyzer::getFilteredValue() const { return _filtValue; }
int HeartPulseAnalyzer::getBPM() const { return _bpm; }
int HeartPulseAnalyzer::getMaxVal() const { return _maxVal; }