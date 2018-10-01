int photocell = A0;
int spkr = 8;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int photoVal = analogRead(photocell);
  float frequency = map(photoVal, 0,1023, 120, 800);
  Serial.println(photoVal);
  tone(spkr, frequency, 10);

}
