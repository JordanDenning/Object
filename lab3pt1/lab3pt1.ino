int pot = A0;
int LED = 3;
int potVal;
int brightnessVal;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int potVal = analogRead(pot);
  int mapVal = map(potVal, 0, 1023, 0, 255);

  analogWrite(LED, mapVal);

}
