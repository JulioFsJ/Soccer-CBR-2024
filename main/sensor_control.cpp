#include "sensor_control.h"

void setAllSensorPinsInput(void) {
    for (int i = 0; i < IR_NUM; ++i) {
        pinMode(SensorPins[i], INPUT);
    }
}

bool getSensorPin(uint8_t pin) {
    switch(pin) {
        case 0:   return PINB&(1<<2);
        case 1:   return PINB&(1<<1);
        case 2:   return PIND&(1<<5);
        case 3:   return PIND&(1<<6);
        case 4:   return PIND&(1<<7);
        case 5:   return PINB&(1<<0);
        case 6:   return PIND&(1<<4);
        case 7:   return PIND&(1<<2);
    }
    return false; 
}
  
sensorInfo_t getAllSensorPulseWidth(float pulseWidth[IR_NUM], uint16_t timeLimit) {
    sensorInfo_t sensorInfo;

    for(int i = 0; i < IR_NUM; i++) {
        pulseWidth[i] = 0;
    }

    const unsigned long startTime_us = micros();
    do {
        for (int i = 0; i < IR_NUM; i++) {
            if(getSensorPin(i) == false) {
                pulseWidth[i] += deltaPulseWidth;
            }
        }
    } while((micros() - startTime_us) < timeLimit);

    sensorInfo.activeSensors    = 0; 
    sensorInfo.maxPulseWidth   	= 0; 
    sensorInfo.maxSensorNumber 	= 0; 
    for(int i = 0; i < IR_NUM; i++) {
        if(pulseWidth[i] > 0) {
            sensorInfo.activeSensors += 1;
        }
        if(pulseWidth[i] > sensorInfo.maxPulseWidth) {
            pulseWidth[i] = micros() - startTime_us;
            sensorInfo.maxSensorNumber = i;
        }
    }

    return sensorInfo;
}

vectorXY_t calcVectorXYFromPulseWidth(float *pulseWidth) {
    vectorXY_t rslt = {0, 0};
    for(int i = 0; i < IR_NUM; i++) {
        rslt.x += pulseWidth[i] * unitVectorX[i];
        rslt.y += pulseWidth[i] * unitVectorY[i];
    }

    return rslt;
}

vectorRT_t calcRTfromXY(vectorXY_t *vectorXY_p) {
    vectorRT_t rslt;
    rslt.radius  = sqrt(pow(vectorXY_p->x, 2.0) + pow(vectorXY_p->y, 2.0));
    rslt.theta   = atan2(vectorXY_p->x, vectorXY_p->y) / PI * 180.0;

    return rslt;
}