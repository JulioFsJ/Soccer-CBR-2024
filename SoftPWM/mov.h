// robot.h

#ifndef ROBOT_H
#define ROBOT_H

#include <Arduino.h>
#include <SoftPWM.h>

// Definição dos pinos dos motores (frente/trás para cada motor)
const int MOTOR_PINS[6] = {52, 53, 40, 38, 36, 34}; // Frente motor 1, trás motor 1, frente motor 2, trás motor 2, frente motor 3, trás motor 3

// Função para configurar os pinos
void setupMotors();

// Função para definir a velocidade de um motor usando SoftPWM
void setMotor(int motorIndex, int speed);

// Funções para mover o robô em ângulos específicos
void move45();
void move90();
void move135();
void move180();
void move225();
void move270();
void move315();
void move0();

#endif
