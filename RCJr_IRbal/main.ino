#include "motores.h"

const int NUM_SENSORS = 8;  
const int IR_PINS[NUM_SENSORS] = {2, 3, 4, 5, 6, 7, 8, 9};

#include <Wire.h>
#include <Adafruit_TCS34725.h>

#define COLOR_SENSORS 4
#define WHITE_THRESHOLD 1

Adafruit_TCS34725 tcs[COLOR_SENSORS]; // Array para os sensores

const int PCA9548A_ADDRESS = 0x70; // Endereço I2C do PCA9548A

void setup() {
  Serial.begin(9600);
  setupMotors(); // Configura os motores com SoftPWM
  
  // Define os pinos dos sensores como entrada
  for (int i = 0; i < NUM_SENSORS; ++i) {
    pinMode(IR_PINS[i], INPUT);
  }

  Wire.begin();
  for (int i = 0; i < COLOR_SENSORS; i++) {
    selectSensor(i);
    if (!tcs[i].begin()) {
      Serial.print("Não foi possível encontrar o sensor ");
      Serial.println(i);
    }
  }
}

void loop() {
  float minDutyCycle = 100.0;  
  int minSensorIndex = -1; 
  int sensorVector[NUM_SENSORS] = {0}; 

    for (int i = 0; i < COLOR_SENSORS; i++) {
    selectSensor(i);
    readColor(i);
  }

  // Loop pelos sensores para ler o duty cycle
  for (int i = 0; i < NUM_SENSORS; ++i) {
    unsigned long duration = pulseIn(IR_PINS[i], HIGH, 5000);

    // Calcula o duty cycle em porcentagem se o sinal foi detectado
    if (duration > 0) {
      float dutyCycle = (duration / 1000.0) * 100.0; // Duty cycle como porcentagem
      Serial.print("Sensor ");
      Serial.print(i);
      Serial.print(": ");
      Serial.print(dutyCycle); 
      Serial.print("%, ");

      if (dutyCycle < minDutyCycle) {
        minDutyCycle = dutyCycle;
        minSensorIndex = i;
      }
    } else {
      Serial.print("Sensor ");
      Serial.print(i);
      Serial.print(": Não detectado, ");
    }
  }

  // Se encontrou um sensor com o menor duty cycle
  if (minSensorIndex != -1) {
    sensorVector[minSensorIndex] = 1; // Marca o menor sensor no vetor como 1
    Serial.print("\nVetor de sensores: ");
    for (int i = 0; i < NUM_SENSORS; ++i) {
      Serial.print(sensorVector[i]);
      Serial.print(" ");
    }

    desligarMotores(); // Desliga os motores antes de ativar a nova combinação

    switch(minSensorIndex) {
      case 0:
        frente(); 
        break;
      case 1:
        diagonaldireita();  
        break;
      case 2:
       direita();  
       break;
      case 3:
        diagonalinferiordireita(); 
        break;
      case 4:
        tras();  
        break;
      case 5:
        diagonalinferioresquerda();  
        break;
      case 6:
        esquerda(); 
        break;
      case 7:
        diagonalesquerda();  
        break;
      default:
        desligarMotores(); // Desliga todos os motores para índices sem combinação específica
    }

    // Exibe o sensor com o menor duty cycle
    Serial.print("Sensor com menor duty cycle: Sensor ");
    Serial.print(minSensorIndex);
    Serial.print(" com ");
    Serial.print(minDutyCycle);
    Serial.println("%");
  } else {
    Serial.println("\nNenhum sensor detectado.");
    desligarMotores();
  }

  Serial.println(); // Quebra de linha após cada ciclo
}
void selectSensor(int sensor) {
  Wire.beginTransmission(PCA9548A_ADDRESS);
  Wire.write(1 << sensor); // Ativa o canal do multiplexador
  Wire.endTransmission();
}

void readColor(int sensor) {
  uint16_t r, g, b, c;
  tcs[sensor].getRawData(&r, &g, &b, &c);

  if (isWhite(r, g, b, c)) {
    onWhiteDetected(sensor); // Chama a função ao detectar branco
  }
}

bool isWhite(uint16_t r, uint16_t g, uint16_t b, uint16_t c) {
  // Verifica se a soma dos valores RGB está acima do limite
  return (r > WHITE_THRESHOLD && g > WHITE_THRESHOLD && b > WHITE_THRESHOLD);
}

void onWhiteDetected(int sensor) {
  // Executa uma ação específica para cada sensor
  switch (sensor) {
    case 0:
    esquerda();
    delay(0.20);
      break;
    case 1:
    frente();
    delay(0.20);
      break;
    case 2:
    direita();
    delay(0.20);
      break;
    case 3:
    tras();
    delay(0.20);
      break;
    default:
    break;
  }
}
