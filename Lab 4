int slidePot = A0;
int spinPot = A1;
void setup() {
  // put your setup code here, to run once:
  pinMode(slidePot, INPUT);
  pinMode(spinPot, INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
int pot1Val = analogRead(slidePot);
int pot2Val = analogRead(spinPot);
int slideVal = map(pot1Val, 0,1023, 0, 255);
int spinVal = map(pot2Val, 0,1023, 0, 255);

//Serial.println(slideVal);
//Serial.println(spinVal);
Serial.print(slideVal);
Serial.print(",");
Serial.println(spinVal);
}
