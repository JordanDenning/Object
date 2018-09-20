int momBut = 2;
int led1 = 3;
int led2 = 4;
int led3 = 5;
int counter = 0;
int lastButtonState = 0;

int buttonVal;
void setup() {
  pinMode(2, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  buttonVal = digitalRead(momBut);
if(buttonVal != lastButtonState){
  
  if (buttonVal == HIGH)
  {
    counter = counter + 1;
    
  }
  delay(50);
}
lastButtonState = buttonVal;

  if(counter == 1 )
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  }
  else if(counter == 2)
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
  }

    else if(counter == 3)
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
  }
  else if(counter == 4)
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    counter = 0;
  }

}
