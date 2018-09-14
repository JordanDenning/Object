int momBut = 2;
int led1 = 3;
int led2 = 4;

int buttonVal;

void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

 buttonVal = digitalRead(momBut);

  if(buttonVal == HIGH)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
  }
  else if(buttonVal == LOW)
  {
    digitalWrite(led2, HIGH);
    digitalWrite(led1, LOW);
  }

}

//pinMode();

//digitalRead();  //binary piece of input

//digitalWrite(); //sedning out binary signal
