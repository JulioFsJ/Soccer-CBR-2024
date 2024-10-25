#include "motores.h"

void setupMotors() {
  SoftPWMBegin();
  
  // Configura cada pino dos motores para o controle com SoftPWM
  for (int i = 0; i < 6; ++i) {
    SoftPWMSet(MOTOR_PINS[i], 0);               // Inicializa com PWM em 0
    SoftPWMSetFadeTime(MOTOR_PINS[i], 1000, 1000); // Tempo de fade mais curto para resposta rápida
  }
}

// Funções para definir combinações de motores
void motorComb0() {
  desligarMotores(); // Garante que todos os motores estão desligados antes de ligar nova combinação
  SoftPWMSet(MOTOR_PINS[0], 150); // Liga o motor 1 para frente
  SoftPWMSet(MOTOR_PINS[5], 150); // Liga o motor 2 para frente
}

void motorComb2() {
  desligarMotores();
  SoftPWMSet(MOTOR_PINS[0], 100); // Liga o motor 3 para frente
  SoftPWMSet(MOTOR_PINS[5], 100); // Liga o motor 1 para trás
  SoftPWMSet(MOTOR_PINS[3], 25); // Liga o motor 1 para trás
}

void motorComb4() {
  desligarMotores();
  SoftPWMSet(MOTOR_PINS[0], 100); // Liga o motor 3 para frente
  SoftPWMSet(MOTOR_PINS[5], 100); // Liga o motor 1 para trás
  SoftPWMSet(MOTOR_PINS[4], 25); // Liga o motor 1 para trás
}

void desligarMotores() {
  // Desliga todos os motores com PWM zero
  for (int i = 0; i < 6; ++i) {
    SoftPWMSet(MOTOR_PINS[i], 0);
  }
}
