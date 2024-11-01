#include <Wire.h>
#include <Adafruit_TCS34725.h>
#include "mpu6050.h"

#define NUM_SENSORS 4
#define WHITE_THRESHOLD 5 // Limite para detectar branco (ajuste conforme necessário)

Adafruit_TCS34725 tcs[NUM_SENSORS]; // Array para os sensores

const int PCA9548A_ADDRESS = 0x70; // Endereço I2C do PCA9548A
const int MPU6050_CHANNEL = 4; // Canal do PCA9548A onde o MPU6050 está conectado

void setup() {
  Serial.begin(9600);

  Wire.begin(); // Inicializa a comunicação I2C
  setPCA9548AChannel(MPU6050_CHANNEL); // Ativa o canal do MPU6050

  mpu_begin();

  Serial.println("Calibrando, deixa parado!");
  delay(1000);
  mpu_calibrate(200);
  Serial.println("===== Calibrado! =====\n");

  mpu_reset();

    // Inicializa os sensores
  for (int i = 0; i < NUM_SENSORS; i++) {
    selectSensor(i);
    if (!tcs[i].begin()) {
      Serial.print("Não foi possível encontrar o sensor ");
      Serial.println(i);
    }
  }
}

void loop() {

  for (int i = 0; i < NUM_SENSORS; i++) {
    selectSensor(i);
    readColor(i);
  }

  mpu_loop();

  // Lê os ângulos do giroscópio
  Serial.print("yaw(z): "); Serial.println(getAngleZ());

  // Aqui você pode adicionar código para recalibrar se necessário
  // Por exemplo, um botão externo poderia ser conectado a um pino e lido aqui.

  delay(100); // Pequena pausa para evitar excesso de mensagens no serial
}
void selectSensor(int sensor) {
  Wire.beginTransmission(PCA9548A_ADDRESS);
  Wire.write(1 << sensor); // Ativa o canal do multiplexador
  Wire.endTransmission();
}
void readColor(int sensor) {
  uint16_t r, g, b, c;
  tcs[sensor].getRawData(&r, &g, &b, &c);
  
  Serial.print("Sensor ");
  Serial.print(sensor);
  Serial.print(": R=");
  Serial.print(r);
  Serial.print(" G=");
  Serial.print(g);
  Serial.print(" B=");
  Serial.print(b);
  Serial.print(" C=");
  Serial.println(c);
  
  if (isWhite(r, g, b, c)) {
    Serial.print("Sensor ");
    Serial.print(sensor);
    Serial.println(" detectou branco!");
  }
}
bool isWhite(uint16_t r, uint16_t g, uint16_t b, uint16_t c) {
  // Verifica se a soma dos valores RGB está acima do limite
  return (r > WHITE_THRESHOLD && g > WHITE_THRESHOLD && b > WHITE_THRESHOLD);
}

// Função para ativar o canal do PCA9548A
void setPCA9548AChannel(int channel) {
  Wire.beginTransmission(PCA9548A_ADDRESS);
  Wire.write(1 << channel); // Ativa o canal desejado
  Wire.endTransmission();
}