# Heart-Rate-Sensor with Display and Grafic

Este é um projeto de monitor cardíaco desenvolvido para Arduino que lê os sinais analógicos de um sensor de pulso, aplica um filtro passa-alta para estabilizar o sinal, calcula os Batimentos Por Minuto (BPM) em tempo real e exibe um gráfico com efeito *scrolling* em um display OLED SSD1306.

O grande diferencial deste projeto é a sua **arquitetura de software**, totalmente reestruturada utilizando **Programação Orientada a Objetos (POO)**. A lógica de processamento do sensor e a interface gráfica do display foram isoladas em classes independentes, tornando o código altamente modular, limpo e profissional.

---

## 📸 Demonstração do Projeto

<!-- Substitua 'sua_foto.jpg' pelo nome exato do arquivo da foto que você vai subir no GitHub -->
![Demonstração do Monitor Cardíaco funcionando](foto.bpm.jpg)

---

## ✨ Funcionalidades e Destaques

* **Arquitetura em POO:** Código limpo e modular dividido nas classes `HeartPulseAnalyzer` (processamento do sinal) e `PulseDisplay` (renderização gráfica).
* **Filtro Passa-Alta Digital:** Implementação de algoritmo para filtragem de ruídos e centralização do sinal analógico no eixo zero.
* **Cálculo de BPM Dinâmico:** Detecção inteligente de picos baseada em limiar adaptativo (`thresh`) com proteção contra falsos positivos.
* **Efeito Scroll no OLED:** Deslocamento direto no buffer da tela para uma animação fluida do gráfico, sem engasgos no Arduino.
* **Telemetria Serial:** Envio de dados formatados prontos para visualização no *Serial Plotter* do Arduino IDE.

---

## 🛠️ Hardware Necessário

* 1x Arduino (Uno, Nano, Mega ou similar)
* 1x Display OLED 128x64 I2C (Controlador SSD1306)
* 1x Sensor de Pulso Cardíaco Analógico (ex: Pulse Sensor Amped)
* Cabos Jumper e Protoboard

---

## 🔌 Conexões (Pinout)

### Display OLED I2C
* **VCC** ➡️ 5V / 3.3V
* **GND** ➡️ GND
* **SCL** ➡️ A5 (no Arduino Uno/Nano)
* **SDA** ➡️ A4 (no Arduino Uno/Nano)

### Sensor de Pulso
* **VCC** ➡️ 5V
* **GND** ➡️ GND
* **Sinal (Analog)** ➡️ A0

---

## 🚀 Como Executar o Projeto

1. Certifique-se de ter as seguintes bibliotecas instaladas na sua Arduino IDE:
   * `Adafruit SSD1306`
   * `Adafruit GFX Library`
2. Baixe ou clone este repositório.
3. Certifique-se de manter todos os arquivos (`MonitorCardiaco.ino`, `HeartPulseAnalyzer.h`, `HeartPulseAnalyzer.cpp`, `PulseDisplay.h`, `PulseDisplay.cpp`) dentro da mesma pasta chamada `MonitorCardiaco`.
4. Abra o arquivo `MonitorCardiaco.ino` na Arduino IDE.
5. Faça o upload para o seu Arduino.

---

## 📄 Estrutura de Arquivos

* `MonitorCardiaco.ino`: Arquivo principal que gerencia o fluxo de setup e o loop.
* `HeartPulseAnalyzer.h` / `.cpp`: Classe responsável por ler o sensor, filtrar o ruído e calcular o BPM.
* `PulseDisplay.h` / `.cpp`: Classe responsável por manipular o display OLED, desenhar o gráfico e escrever os textos.

---
Feito com 💻 e ☕ por Matheus Soares de Lima, Maria Eduarda S. Ferraz, Lucas Gabriel C. Veloso, Pedro Augusto M. Lacerda, Samuel de Araújo N. Silva.  (https://github.com/matheus-soares-7).
