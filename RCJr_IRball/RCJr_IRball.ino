#include "Motores.h"  // Inclui o arquivo de cabeçalho dos motores

const int NUM_SENSORS = 8;  
const int IR_PINS[NUM_SENSORS] = {2, 3, 4, 5, 6, 7, 8, 9}; 

void setup() {
  Serial.begin(9600);

  // Define os pinos dos motores como saída
  for (int i = 0; i < 6; ++i) {
    pinMode(MOTOR_PINS[i], OUTPUT);
  }
  
  // Define os pinos dos sensores como entrada
  for (int i = 0; i < NUM_SENSORS; ++i) {
    pinMode(IR_PINS[i], INPUT);
  }
}

void loop() {
  float minDutyCycle = 100.0;  
  int minSensorIndex = -1; 
  int sensorVector[NUM_SENSORS] = {0}; 

  // Loop pelos sensores
  for (int i = 0; i < NUM_SENSORS; ++i) {
    unsigned long duration = pulseIn(IR_PINS[i], HIGH, 5000);

    // Verifica se o sinal foi detectado
    if (duration > 0) {
      float dutyCycle = (duration / 1000.0) * 100.0; // Calcula o duty cycle em porcentagem
      Serial.print("Sensor ");
      Serial.print(i); // Identifica o número do sensor
      Serial.print(": ");
      Serial.print(dutyCycle); 
      Serial.print("%, ");

      // Verifica se o duty cycle atual é menor que o mínimo
      if (dutyCycle < minDutyCycle) {
        minDutyCycle = dutyCycle;
        minSensorIndex = i;
      }

    } else { // Caso não tenha detectado sinal
      Serial.print("Sensor ");
      Serial.print(i);
      Serial.print(": Não detectado, ");
    }
  }

  // Se um sensor com menor duty cycle foi encontrado
  if (minSensorIndex != -1) {
    sensorVector[minSensorIndex] = 1; // Marca o menor sensor no vetor como 1

    // Exibe o vetor resultante
    Serial.print("\nVetor de sensores: ");
    for (int i = 0; i < NUM_SENSORS; ++i) {
      Serial.print(sensorVector[i]);
      Serial.print(" ");
    }

    // Condição específica para cada sensor e aciona os motores correspondentes
    desligarMotores(); // Desliga os motores antes de ligar a nova combinação

    if (minSensorIndex == 0) {
      motorComb0();  // Liga a combinação de motores 0 e 1
    } else if (minSensorIndex == 1) {
      desligarMotores();  // Liga a combinação de motores 2 e 3
    } else if (minSensorIndex == 2) {
      motorComb2();  // Liga a combinação de motores 4 e 5
    } else if (minSensorIndex == 3) {
      desligarMotores();  // Liga a combinação de motores 0 e 2
    } else if (minSensorIndex == 4) {
      motorComb4();  // Liga a combinação de motores 1 e 3
    } else if (minSensorIndex == 5) {
      desligarMotores();  // Liga a combinação de motores 4 e 0
    } else if (minSensorIndex == 6) {
      motorComb4();  // Liga a combinação de motores 1 e 3
    } else if (minSensorIndex == 7) {
      desligarMotores();  // Liga a combinação de motores 4 e 0
  }

    // Exibe o sensor com o menor duty cycle
    Serial.print("Sensor com menor duty cycle: Sensor ");
    Serial.print(minSensorIndex);
    Serial.print(" com ");
    Serial.print(minDutyCycle);
    Serial.println("%");
    
  } else { // Caso nenhum sensor tenha sido detectado
    Serial.println("\nNenhum sensor detectado.");
    desligarMotores(); // Desliga todos os motores se não houver sinal
  }

  Serial.println(); // Quebra de linha após cada ciclo
  delay(600); // Pequeno atraso entre os ciclos
}
