
int IR1=8;      
int IR2=9;    
int enA = 5;   
int enB = 6;    
int MotorBip1=4;
int MotorBip2=7;
int changer=13;
void setup() 
{
  
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(IR1,INPUT);
  pinMode(IR2,INPUT);
  pinMode(changer,INPUT);
  pinMode(MotorBip1,OUTPUT);
  pinMode(MotorBip2,OUTPUT);
}
void loop() 
{
  if(digitalRead(changer)==HIGH)
  {
   if(digitalRead(IR1)==HIGH && digitalRead(IR2)==HIGH) //IR will not glow on black line
  {
    digitalWrite(MotorBip1,HIGH);
    digitalWrite(MotorBip2,HIGH);
   analogWrite (enA, 0);
   analogWrite (enB, 0);
  }

  else if(digitalRead(IR1)==LOW && digitalRead(IR2)==LOW)  //IR not on black line
  {
    digitalWrite(MotorBip1,LOW);
    digitalWrite(MotorBip2,LOW);
    analogWrite (enA, 200);
    analogWrite (enB, 200);
  }

  else if(digitalRead(IR1)==LOW && digitalRead(IR2)==HIGH)
  {
  \
    digitalWrite(MotorBip1,HIGH);
    digitalWrite(MotorBip2,LOW);
    analogWrite (enA, 200);
    analogWrite (enB, 150);
   delay(100);
  }

  else if(digitalRead(IR1)==HIGH && digitalRead(IR2)==LOW)
  {
    //Tilt robot towards right by stopping the right wheel and moving the left one
         // If I want to turn right then the speed of the right wheel should be less than that of the left wheel, here, let a be the right wheel
    digitalWrite(MotorBip1,LOW);
    digitalWrite(MotorBip2,HIGH);
    analogWrite (enA, 150);
   analogWrite (enB, 200);
   delay(100);
  }

  else
  {
    digitalWrite(MotorBip1,LOW);
    digitalWrite(MotorBip2,LOW);
    analogWrite (enA, 0);
   analogWrite (enB, 0);
  }}
  else
  {
    char t;
    if(Serial.available()){
  t = Serial.read();
  Serial.println(t);
}
 
if(t == 'F'){     
  digitalWrite(MotorBip1,HIGH);
  digitalWrite(MotorBip2,HIGH);
}
 
else if(t == 'B'){   
  digitalWrite(MotorBip1,HIGH);
  digitalWrite(MotorBip2,HIGH);
}
 
else if(t == 'L'){    
  digitalWrite(MotorBip1,HIGH);
}
 
else if(t == 'R'){  
  digitalWrite(MotorBip2,HIGH);
}

else if(t == 'S'){      
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  digitalWrite(10,LOW);
}
delay(100);
}
}
