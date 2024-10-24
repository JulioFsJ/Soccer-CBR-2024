#ifndef MOTORES_H
#define MOTORES_H

const int MOTOR_PINS[6] = {52, 36, 40, 38, 53, 34}; // Pinos dos motores

void motorComb0() {
  digitalWrite(MOTOR_PINS[0], HIGH); // Motor 0 ON
  digitalWrite(MOTOR_PINS[1], HIGH); // Motor 1 ON
  Serial.println("Motores 0 e 1 ligados.");
}

void motorComb1() {
  digitalWrite(MOTOR_PINS[2], HIGH); // Motor 2 ON
  digitalWrite(MOTOR_PINS[3], HIGH); // Motor 3 ON
  Serial.println("Motores 2 e 3 ligados.");
}

void motorComb2() {
  digitalWrite(MOTOR_PINS[4], HIGH); // Motor 4 ON
  digitalWrite(MOTOR_PINS[5], HIGH); // Motor 5 ON
  Serial.println("Motores 4 e 5 ligados.");
}

void motorComb3() {
  digitalWrite(MOTOR_PINS[0], HIGH); // Motor 0 ON
  digitalWrite(MOTOR_PINS[2], HIGH); // Motor 2 ON
  Serial.println("Motores 0 e 2 ligados.");
}

void motorComb4() {
  digitalWrite(MOTOR_PINS[1], HIGH); // Motor 1 ON
  digitalWrite(MOTOR_PINS[3], HIGH); // Motor 3 ON
  Serial.println("Motores 1 e 3 ligados.");
}

void motorComb5() {
  digitalWrite(MOTOR_PINS[4], HIGH); // Motor 4 ON
  digitalWrite(MOTOR_PINS[0], HIGH); // Motor 0 ON
  Serial.println("Motores 4 e 0 ligados.");
}

// Função para desligar todos os motores
void desligarMotores() {
  for (int i = 0; i < 6; ++i) {
    digitalWrite(MOTOR_PINS[i], LOW); // Todos os motores OFF
  }
  Serial.println("Todos os motores desligados.");
}

#endif
