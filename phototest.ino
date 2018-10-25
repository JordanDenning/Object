int detect = A4;
int detect2 = A2;
int detect3 = A5;
int detect4 = A1;
int detect5 = A0;
int detect6 = A3;
int LED = 3;
int LED2 = 5;
int LED3 = 6;
int LED4 = 9;
int LED5 = 10;
int LED6 = 11;
bool first = false;
bool second = false;
bool third = false;
bool fourth = false;
bool fifth = false;
bool sixth = false;
void setup() {
  pinMode(detect, INPUT);
  pinMode(detect2, INPUT);
  pinMode(detect3, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  digitalWrite(LED, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
  digitalWrite(LED5, LOW);
  digitalWrite(LED6, LOW);
//  digitalWrite(LED, HIGH);
//  digitalWrite(LED2, HIGH);
//  digitalWrite(LED3, HIGH);
//  digitalWrite(LED4, HIGH);
//  digitalWrite(LED5, HIGH);
//  digitalWrite(LED6, HIGH);
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  int val = analogRead(detect);
  int val2 = analogRead(detect2);
  int val3 = analogRead(detect3);
  int val4 = analogRead(detect4);
  int val5 = analogRead(detect5);
  int val6 = analogRead(detect6);
  Serial.println(val6);
  if(val <=33)
  {
    digitalWrite(LED, HIGH);
    first = true;
  }
    if(val2 <=30 && first == true)
  {
    digitalWrite(LED2, HIGH);
    second = true;
  }
    if(val3 <=33 && second == true)
  {
    digitalWrite(LED3, HIGH);
    third = true;
  }
    if(val4 <=25 && third == true)
  {
    digitalWrite(LED4, HIGH);
    fourth = true;
  }
      if(val5 <=25 && fourth == true)
  {
    digitalWrite(LED5, HIGH);
    fifth = true;
  }
    if(val6 <=33 && fifth == true)
  {
    digitalWrite(LED6, HIGH);
       for(int i = 0; i < 5; i++)
    {
      fadeInandOut();
    }
    first = false;
    second = false;
    third = false;
    fourth = false;
    fifth = false;
  }
//  else
//  {
//    digitalWrite(LED, LOW);
//  }
  // put your main code here, to run repeatedly:
}

void fadeInandOut()
{
    for (int i = 0; i < 255; i++){ //if i is less than 255 then increase i with 1
    analogWrite(LED, i); //write the i value to pin 11
    analogWrite(LED2, i);
    analogWrite(LED3, i);
    analogWrite(LED4, i);
    analogWrite(LED5, i);
    analogWrite(LED6, i);
    delay(23); //wait 5 ms then do the for loop again
    }
    delay(1000);
    for (int i = 255; i > -1; i--){ //descrease i with 1
    analogWrite(LED, i); //write the i value to pin 11
    analogWrite(LED2, i);
    analogWrite(LED3, i);
    analogWrite(LED4, i);
    analogWrite(LED5, i);
    analogWrite(LED6, i);
    delay(23);
    }
    delay(700);
    
}
