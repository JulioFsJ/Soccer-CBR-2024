// DEFINE OS PINOS DOS SENSORES
const int trigPins[] = {51, 49, 47, 45};
const int echoPins[] = {50, 48, 46, 44};

void setup() {
  Serial.begin(9600);
  
  // CONFIGURA OS PINOS
  for (int i = 0; i < 4; i++) {
    pinMode(trigPins[i], OUTPUT);
    pinMode(echoPins[i], INPUT);
  }
}

long lerSensor(int trigPin, int echoPin) {
  long duration;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  return duration * 0.034 / 2; // cm
}

void loop() {
  const char* direcoes[] = {"Norte", "Sul", "Leste", "Oeste"};
  
  //pode remover isso para não pesar mais o arduino
  for (int i = 0; i < 4; i++) {
    Serial.print("Distância Sensor ");
    Serial.print(direcoes[i]);
    Serial.print(": ");
    Serial.print(lerSensor(trigPins[i], echoPins[i]));
    Serial.println(" cm");
  }

  Serial.println();
  delay(1000); //<--- Pode remover o serial print e o delay dps 
}