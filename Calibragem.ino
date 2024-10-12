int motor1_A = 34;
int motor1_B = 32;
int motor2_A = 30;
int motor2_B = 28;
int motor3_A = 26;
int motor3_B = 24;

void setup() {
  pinMode(motor1_A, OUTPUT);
  pinMode(motor1_B, OUTPUT);
  pinMode(motor2_A, OUTPUT);
  pinMode(motor2_B, OUTPUT);
  pinMode(motor3_A, OUTPUT);
  pinMode(motor3_B, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Mover motor 1 para frente
  digitalWrite(motor1_A, HIGH);
  digitalWrite(motor1_B, LOW);
  // Mover motor 2 para frente
  digitalWrite(motor2_A, HIGH);
  digitalWrite(motor2_B, LOW);
  // Mover motor 3 para frente
  digitalWrite(motor3_A, HIGH);
  digitalWrite(motor3_B, LOW);
  delay(2000); // Rodar por 2 segundos

  // Mover motor 1 para trás
  digitalWrite(motor1_A, LOW);
  digitalWrite(motor1_B, HIGH);
  // Mover motor 2 para trás
  digitalWrite(motor2_A, LOW);
  digitalWrite(motor2_B, HIGH);
  // Mover motor 3 para trás
  digitalWrite(motor3_A, LOW);
  digitalWrite(motor3_B, HIGH);
  delay(2000);

}

// Função stop 
void stopAllMotors() {
  digitalWrite(motor1_A, LOW);
  digitalWrite(motor1_B, LOW);
  
  digitalWrite(motor2_A, LOW);
  digitalWrite(motor2_B, LOW);
  
  digitalWrite(motor3_A, LOW);
  digitalWrite(motor3_B, LOW);
}
