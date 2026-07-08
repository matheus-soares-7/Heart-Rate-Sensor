#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Inclui os arquivos criados localmente na pasta do projeto
#include "HeartPulseAnalyzer.h"
#include "PulseDisplay.h"

#define PIN_SENSOR A0

// Inicialização global dos periféricos
Adafruit_SSD1306 oled(128, 64, &Wire);
PulseDisplay visualizer(oled);
HeartPulseAnalyzer pulse(PIN_SENSOR);

void setup() {
  Serial.begin(9600);
  visualizer.begin();
}

void loop() {
  // Atualiza os cálculos e filtros do sensor
  pulse.update();

  // Print de telemetria no Monitor Serial
  Serial.print(pulse.getFilteredValue()); 
  Serial.print(",");
  Serial.print(pulse.getMaxVal()); 
  Serial.print(",");
  Serial.println(pulse.getBPM());

  // Atualiza a interface gráfica com os novos dados processados
  visualizer.updateGraph(pulse.getFilteredValue(), pulse.getBPM());
}