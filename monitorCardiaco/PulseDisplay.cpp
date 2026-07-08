#include "PulseDisplay.h"

PulseDisplay::PulseDisplay(Adafruit_SSD1306& oledInstance) : _oled(oledInstance), _prevY(60) {}

void PulseDisplay::begin() {
    _oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    delay(1000);
    _oled.clearDisplay();
    _oled.display();
}

void PulseDisplay::scrollLeft() {
    uint8_t *buf = _oled.getBuffer();
    int widthBytes = 128;
    int pages = 8; // 64 pixels de altura / 8 bits por página

    for (int p = 0; p < pages; p++) {
        for (int c = 0; c < widthBytes - 1; c++) {
            buf[p * widthBytes + c] = buf[p * widthBytes + c + 1];
        }
        buf[p * widthBytes + (widthBytes - 1)] = 0;
    }
}

void PulseDisplay::updateGraph(int filtValue, int bpm) {
    int yPos = map(filtValue, -40, 100, 0, 60);
    int y = 60 - yPos;

    // Desloca o buffer da tela para a esquerda
    scrollLeft();

    // Desenha a linha de referência do eixo zero
    int zeroY = 60 - map(0, -40, 100, 0, 60);
    _oled.drawLine(0, zeroY, 127, zeroY, SSD1306_WHITE);

    // Desenha o novo segmento do sinal vindo da direita
    _oled.drawLine(126, _prevY, 127, y, SSD1306_WHITE);
    _prevY = y;

    // Limpa a área do texto (topo da tela) para não sobrepor o gráfico antigo
    _oled.fillRect(0, 0, 128, 16, SSD1306_BLACK);
    
    // Renderiza o BPM
    _oled.setCursor(0, 0);
    _oled.setTextSize(2);
    _oled.setTextColor(SSD1306_WHITE);
    _oled.print("BPM:");
    _oled.setCursor(60, 0);
    _oled.print(bpm);

    _oled.display();
}