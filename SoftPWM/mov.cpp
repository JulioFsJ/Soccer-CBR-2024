// robot.cpp

#include "mov.h"

// Constantes do robô
const float pi = 3.141592;
const float wheelAngle1 = 0;         // Ângulo da Roda 1 (0°)
const float wheelAngle2 = 2 * pi / 3; // Ângulo da Roda 2 (120°)
const float wheelAngle3 = 4 * pi / 3; // Ângulo da Roda 3 (240°)

// Função para configurar os pinos dos motores
void setupMotors() {
  // Inicializa a biblioteca SoftPWM
  SoftPWMBegin();

  // Configura cada pino de MOTOR_PINS
  for (int i = 0; i < 6; i++) {
    SoftPWMSet(MOTOR_PINS[i], 0); // Inicializa o PWM no valor 0
    SoftPWMSetFadeTime(MOTOR_PINS[i], 1000, 1000); // Define tempo de fade
  }
}

// Função para controlar um motor usando SoftPWM
void setMotor(int motorIndex, int speed) {
  int forwardPin = MOTOR_PINS[motorIndex * 2];      // Pino de frente
  int backwardPin = MOTOR_PINS[motorIndex * 2 + 1]; // Pino de trás

  if (speed >= 0) {
    SoftPWMSet(forwardPin, speed);
    SoftPWMSet(backwardPin, 0); // Desativa o pino para trás
  } else {
    SoftPWMSet(forwardPin, 0);  // Desativa o pino para frente
    SoftPWMSet(backwardPin, -speed);
  }
}

// Função para calcular e mover o robô com base no ângulo
void moveRobot(float direction, float speed, float rotation = 0) {
  // Calcular componentes x e y da velocidade
  float Vx = speed * cos(direction);
  float Vy = speed * sin(direction);

  // Calcular as velocidades de cada roda
  int speed1 = Vx * cos(wheelAngle1) + Vy * sin(wheelAngle1) + rotation;
  int speed2 = Vx * cos(wheelAngle2) + Vy * sin(wheelAngle2) + rotation;
  int speed3 = Vx * cos(wheelAngle3) + Vy * sin(wheelAngle3) + rotation;

  // Controlar os motores com as velocidades calculadas
  setMotor(0, constrain(speed1, -255, 255)); // Motor 1
  setMotor(1, constrain(speed2, -255, 255)); // Motor 2
  setMotor(2, constrain(speed3, -255, 255)); // Motor 3
}

// Funções para mover o robô em diferentes ângulos
void move0() {
  moveRobot(0, 150); // Move para 0° (Frente)
}

void move45() {
  moveRobot(pi / 4, 150); // Move para 45°
}

void move90() {
  moveRobot(pi / 2, 150); // Move para 90° (Esquerda)
}

void move135() {
  moveRobot(3 * pi / 4, 150); // Move para 135°
}

void move180() {
  moveRobot(pi, 150); // Move para 180° (Trás)
}

void move225() {
  moveRobot(5 * pi / 4, 150); // Move para 225°
}

void move270() {
  moveRobot(3 * pi / 2, 150); // Move para 270° (Direita)
}

void move315() {
  moveRobot(7 * pi / 4, 150); // Move para 315°
}
