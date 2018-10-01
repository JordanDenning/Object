int pot1 = A0;
int pot2 = A1;
int greenLED = 3;
int blueLED = 2;
int potVal;
int brightnessVal;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(greenLED,OUTPUT);
  pinMode(blueLED,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int potVal1 = analogRead(pot1);
  int potVal2 = analogRead(pot2);

  int mapVal1 = map(potVal1, 0, 1023, 0, 255);
  int mapVal2 = map(potVal2, 0, 1023, 0, 255);

  analogWrite(greenLED, mapVal1);
  analogWrite(blueLED, mapVal2);

  Serial.print("red: ");
  Serial.print(mapVal1);
  Serial.print(", blue: ");
  Serial.print(mapVal2);

}
