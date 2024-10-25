#include <Wire.h>
#include "Adafruit_TCS34725.h"
#include "FDSFSG.h"

// Endereço I2C do PCA9548A
#define PCA9548A_ADDR 0x70

// Tolerância para considerar que é branco
#define WHITE_THRESHOLD 700

// Cria uma instância do sensor TCS34725
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);

void setup() {
  Wire.begin(); // Inicializa o barramento I2C
  Serial.begin(9600); // Inicializa a comunicação serial

  // Seleciona o canal 3
  selectChannel(1);
  
  // Inicializa o sensor TCS34725
  if (tcs.begin()) {
    Serial.println("Sensor TCS34725 encontrado!");
  } else {
    Serial.println("Sensor TCS34725 não encontrado. Verifique as conexões!");
    while (1);
  }
}

void loop() {
  // Lê os dados de cor
  uint16_t r, g, b, c;
  tcs.getRawData(&r, &g, &b, &c);

  // Verifica se os valores de R, G e B estão próximos
  if (isWhite(r, g, b)) {
    Serial.println("Cor detectada: BRANCO");
    desligarMotores();
  }else{
    Serial.println("Nao branco");
    motorComb0();
  }

  delay(1000); // Espera 1 segundo antes da próxima leitura
}

bool isWhite(uint16_t r, uint16_t g, uint16_t b) {
  // Verifica se as diferenças entre R, G e B estão dentro de um limite aceitável
  int maxValue = max(r, max(g, b));
  int minValue = min(r, min(g, b));
  
  return (maxValue - minValue < WHITE_THRESHOLD) && (maxValue > 500); // Ajuste 500 conforme necessário
}

void selectChannel(int channel) {
  if (channel < 0 || channel > 7) {
    Serial.println("Canal deve estar entre 0 e 7");
    return;
  }
  Wire.beginTransmission(PCA9548A_ADDR);
  Wire.write(1 << channel); // Ativa o canal desejado
  Wire.endTransmission();
}

void deselectAll() {
  Wire.beginTransmission(PCA9548A_ADDR);
  Wire.write(0); // Desmarca todos os canais
  Wire.endTransmission();
}