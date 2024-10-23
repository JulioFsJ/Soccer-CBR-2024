#ifndef __SENSOR_CONTROL__
#define __SENSOR_CONTROL__

#include "Arduino.h"
#define IR_NUM 8

const uint8_t   SensorPins[IR_NUM]  = {2, 3, 4, 5, 6, 7, 8, 9};
const float     unitVectorX[IR_NUM] = {0.000, 0.707, 1.000, 0.707, 0.000, -0.707, -1.000, -0.707};
const float     unitVectorY[IR_NUM] = {1.000, 0.707, 0.000, -0.707, -1.000, -0.707, 0.000, 0.707};
const float     deltaPulseWidth     = 2.0;

typedef struct {
    int activeSensors;      
    int maxPulseWidth;      
    int maxSensorNumber;    
} sensorInfo_t;

typedef struct {
    float x;
    float y;
} vectorXY_t;

typedef struct {
    float radius;
    float theta;
} vectorRT_t;

void setAllSensorPinsInput(void);
bool getSensorPin(uint8_t pin);
sensorInfo_t getAllSensorPulseWidth(float pulseWidth[IR_NUM], uint16_t timeLimit);
vectorXY_t calcVectorXYFromPulseWidth(float *pulseWidth);
vectorRT_t calcRTfromXY(vectorXY_t *vectorXY_p);

#endif