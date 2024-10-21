int distN = 0;
int distS = 0;
int distL = 0;
int distO = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  Serial.begin(9600);
  pinMode(42, OUTPUT);
  pinMode(40, OUTPUT);
  pinMode(38, OUTPUT);
  pinMode(36, OUTPUT);
  pinMode(52, OUTPUT);
  pinMode(53, OUTPUT);
}

void loop()
{
  distN = 0.01723 * readUltrasonicDistance(51, 50);
  Serial.println(distN);
  if (distN <= 15) {
    digitalWrite(34, HIGH);
    digitalWrite(53, HIGH);
    
  } else {
    digitalWrite(34, LOW);
    digitalWrite(53, LOW);
  
  }
 delay(10); // Delay a little bit to improve simulation performance
}
