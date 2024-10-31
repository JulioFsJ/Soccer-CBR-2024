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
void motorComb0() {
  desligarMotores(); 
  SoftPWMSet(MOTOR_PINS[0], 150); 
  SoftPWMSet(MOTOR_PINS[5], 150);
}

void motorComb1() {
  desligarMotores();
  SoftPWMSet(MOTOR_PINS[0], 150); 
  SoftPWMSet(MOTOR_PINS[5], 150); 
  SoftPWMSet(MOTOR_PINS[3], 100); 
}

void motorComb2() {
  desligarMotores();
  SoftPWMSet(MOTOR_PINS[0], 100); 
  SoftPWMSet(MOTOR_PINS[5], 100); 
  SoftPWMSet(MOTOR_PINS[4], 25);
}

void motorComb3() {
  desligarMotores(); 
  SoftPWMSet(MOTOR_PINS[0], 150); 
  SoftPWMSet(MOTOR_PINS[5], 150);
}

void motorComb4() {
  desligarMotores();
  SoftPWMSet(MOTOR_PINS[0], 100); 
  SoftPWMSet(MOTOR_PINS[5], 100); 
  SoftPWMSet(MOTOR_PINS[3], 25); 
}

void motorComb5() {
  desligarMotores();
  SoftPWMSet(MOTOR_PINS[0], 100); 
  SoftPWMSet(MOTOR_PINS[5], 100); 
  SoftPWMSet(MOTOR_PINS[4], 25); 
}

void motorComb6() {
  desligarMotores(); 
  SoftPWMSet(MOTOR_PINS[0], 150); 
  SoftPWMSet(MOTOR_PINS[5], 150);
}

void motorComb7() {
  desligarMotores();
  SoftPWMSet(MOTOR_PINS[0], 100); 
  SoftPWMSet(MOTOR_PINS[5], 100); 
  SoftPWMSet(MOTOR_PINS[3], 25); 
}

void desligarMotores() {
  // Desliga todos os motores com PWM zero
  for (int i = 0; i < 6; ++i) {
    SoftPWMSet(MOTOR_PINS[i], 0);
  }
}
