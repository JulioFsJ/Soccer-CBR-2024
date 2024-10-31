#include "motores.h"

const int NUM_SENSORS = 8;  
const int IR_PINS[NUM_SENSORS] = {2, 3, 4, 5, 6, 7, 8, 9}; 

void setup() {
  Serial.begin(9600);
  setupMotors(); // Configura os motores com SoftPWM
  
  // Define os pinos dos sensores como entrada
  for (int i = 0; i < NUM_SENSORS; ++i) {
    pinMode(IR_PINS[i], INPUT);
  }
}

void loop() {
  float minDutyCycle = 100.0;  
  int minSensorIndex = -1; 
  int sensorVector[NUM_SENSORS] = {0}; 

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
        motorComb0(); 
        break;
      case 1:
        motorComb1();  
        break;
      case 2:
       motorComb2();  
       break;
      case 3:
        motorComb3(); 
        break;
      case 4:
        motorComb4();  
        break;
      case 5:
        motorComb5();  
        break;
      case 6:
        motorComb5(); 
        break;
      case 7:
        motorComb7();  
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
  delay(600); // Pequeno atraso entre os ciclos
}
