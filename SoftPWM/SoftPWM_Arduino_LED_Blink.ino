#include "mov.h"

void setup() {
  setupMotors(); // Inicializa os pinos dos motores
}

void loop() {
  move0();    // Exemplo: Move o robô para frente (0°)
  delay(1000);
  move90();   // Exemplo: Move o robô a 45°
  delay(1000);
  move270();   // Exemplo: Move o robô a 90°
  delay(1000);
  // Continue chamando outras funções de movimento conforme necessário
}
