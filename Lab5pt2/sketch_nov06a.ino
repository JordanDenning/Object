int switchPin = 2;
int enablePin = 9;
int motor1Pin = 3;
int motor2Pin = 4;
void setup() {
  // put your setup code here, to run once:
  pinMode(switchPin, INPUT);
  pinMode(enablePin, OUTPUT);
  pinMode(motor1Pin, OUTPUT);
  pinMode(motor2Pin, OUTPUT);

  digitalWrite(enablePin, HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:

  int switchVal = digitalRead(switchPin);

  if (switchVal == HIGH)
  {
    digitalWrite(motor1Pin, HIGH);
    digitalWrite(motor2Pin, LOW);
  }
  else
  {
    digitalWrite(motor1Pin, LOW);
    digitalWrite(motor2Pin, HIGH);
  }

}
