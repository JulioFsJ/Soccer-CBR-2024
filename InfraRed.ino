const int NUM_SENSORS = 8;  // Número total de sensores IR
const int IR_PINS[NUM_SENSORS] = {2, 3, 4, 5, 6, 7, 8, 9}; // Pinos digitais

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < NUM_SENSORS; ++i) {
    pinMode(IR_PINS[i], INPUT);
  }
}

void loop() {
  for (int i = 0; i < NUM_SENSORS; ++i) {
    unsigned long duration = pulseIn(IR_PINS[i], HIGH); // Mede a duração do pulso em HIGH para o sensor atual
    
    if (duration > 0) {
      float dutyCycle = (duration / 1000.0) * 100.0; // Calcula o duty cycle em porcentagem
      Serial.print("Sensor ");
      Serial.print(i); // Identifica o número do sensor
      Serial.print(": ");
      Serial.print(dutyCycle); // Imprime o duty cycle
      Serial.print("%, ");
    } else {
      Serial.print("Sensor ");
      Serial.print(i);
      Serial.print(": Não detectado, ");
    }
  }
  Serial.println(); // Quebra de linha após cada ciclo de aferição dos sensores
  delay(600);
}
