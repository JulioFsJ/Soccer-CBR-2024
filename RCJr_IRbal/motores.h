#ifndef MOTORES_H
#define MOTORES_H

#include <SoftPWM.h>
#include <Arduino.h>

// Definição dos pinos dos motores
const int MOTOR_PINS[6] = {52, 53, 40, 38, 34, 36}; // Frente motor 1, trás motor 1, frente motor 2, trás motor 2, frente motor 3, trás motor 3

// Função para configurar os motores
void setupMotors();

// Funções para controlar as combinações específicas de motores
void frente();
void diagonaldireita();
void direita();
void diagonalinferiordireita();
void tras();
void diagonalinferioresquerda();
void esquerda();
void diagonalesquerda();
void desligarMotores();

#endif
