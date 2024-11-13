#include "motores.h"

void setupMotors() {
  SoftPWMBegin();
  
  // Configura cada pino dos motores para o controle com SoftPWM
  for (int i = 0; i < 6; ++i) {
    SoftPWMSet(MOTOR_PINS[i], 0);              
    SoftPWMSetFadeTime(MOTOR_PINS[i], 1000, 1000); 
  }
}

// Funções para definir combinações de motores
void frente() {
  desligarMotores(); 
  SoftPWMSet(MOTOR_PINS[0], 150); 
  SoftPWMSet(MOTOR_PINS[5], 145);
  delay(2000);
  SoftPWMSet(MOTOR_PINS[2], 130);
  delay(13);
  desligarMotores(); 
  SoftPWMSet(MOTOR_PINS[0], 145); 
  SoftPWMSet(MOTOR_PINS[5], 150);
  SoftPWMSet(MOTOR_PINS[2], 0);

}

void diagonaldireita() {
  desligarMotores();
  SoftPWMSet(MOTOR_PINS[0], 150); 
  SoftPWMSet(MOTOR_PINS[5], 150); 
  SoftPWMSet(MOTOR_PINS[3], 80); 
}

void direita() {
  desligarMotores();
  SoftPWMSet(MOTOR_PINS[0], 100); 
  SoftPWMSet(MOTOR_PINS[5], 100); 
  SoftPWMSet(MOTOR_PINS[3], 150);
}

void diagonalinferiordireita() {
  desligarMotores(); 
  SoftPWMSet(MOTOR_PINS[1], 150); 
  SoftPWMSet(MOTOR_PINS[4], 150);
  SoftPWMSet(MOTOR_PINS[3], 80);
}

void tras() {
  desligarMotores();
  SoftPWMSet(MOTOR_PINS[1], 100); 
  SoftPWMSet(MOTOR_PINS[4], 100); 
}

void diagonalinferioresquerda() {
  desligarMotores();
  SoftPWMSet(MOTOR_PINS[1], 100); 
  SoftPWMSet(MOTOR_PINS[4], 100); 
  SoftPWMSet(MOTOR_PINS[2], 80); 
}

void esquerda() {
  desligarMotores(); 
  SoftPWMSet(MOTOR_PINS[0], 150); 
  SoftPWMSet(MOTOR_PINS[5], 150);
  SoftPWMSet(MOTOR_PINS[2], 100); 
}

void diagonalesquerda() {
  desligarMotores();
  SoftPWMSet(MOTOR_PINS[0], 100); 
  SoftPWMSet(MOTOR_PINS[5], 100); 
  SoftPWMSet(MOTOR_PINS[2], 80); 
}

void desligarMotores() {
  // Desliga todos os motores com PWM zero
  for (int i = 0; i < 6; ++i) {
    SoftPWMSet(MOTOR_PINS[i], 0);
  }
}
