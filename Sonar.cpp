//DEFINE OS PINOS DO SENSOR NORTE
#define TRIG_PIN_1 51
#define ECHO_PIN_1 50
//DEFINE OS PINOS DO SENSOR SUL
#define TRIG_PIN_2 49
#define ECHO_PIN_2 48
//DEFINE OS PINOS DO SENSOR LESTE
#define TRIG_PIN_3 47
#define ECHO_PIN_3 46
//DEFINE OS PINOS DO SENSOR OESTE
#define TRIG_PIN_4 45
#define ECHO_PIN_4 44

void setup() {
  Serial.begin(9600);
  
  //CONFIGURA OS PINOS
  pinMode(TRIG_PIN_1, OUTPUT);
  pinMode(ECHO_PIN_1, INPUT);
  
  pinMode(TRIG_PIN_2, OUTPUT);
  pinMode(ECHO_PIN_2, INPUT);
  
  pinMode(TRIG_PIN_3, OUTPUT);
  pinMode(ECHO_PIN_3, INPUT);
  
  pinMode(TRIG_PIN_4, OUTPUT);
  pinMode(ECHO_PIN_4, INPUT);
}

void loop() {

  //PODE TIRAR ESSES SERIALPRINT DPS
  long duration, distance;

  // Norte
  digitalWrite(TRIG_PIN_1, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN_1, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN_1, LOW);
  duration = pulseIn(ECHO_PIN_1, HIGH);
  distance = duration * 0.034 / 2; // cm
  Serial.print("Distância Sensor 1: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Sul
  digitalWrite(TRIG_PIN_2, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN_2, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN_2, LOW);
  duration = pulseIn(ECHO_PIN_2, HIGH);
  distance = duration * 0.034 / 2; // cm
  Serial.print("Distância Sensor 2: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Leste
  digitalWrite(TRIG_PIN_3, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN_3, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN_3, LOW);
  duration = pulseIn(ECHO_PIN_3, HIGH);
  distance = duration * 0.034 / 2; // cm
  Serial.print("Distância Sensor 3: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Oeste
  digitalWrite(TRIG_PIN_4, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN_4, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN_4, LOW);
  duration = pulseIn(ECHO_PIN_4, HIGH);
  distance = duration * 0.034 / 2; // cm
  Serial.print("Distância Sensor 4: ");
  Serial.print(distance);
  Serial.println(" cm");

  Serial.println();
  delay(1000); // Espera 1 segundo antes de repetir //<---Pode retirar isso dps
}