#include<SoftwareSerial.h>
SoftwareSerial bt(2,3);
const int motor1 = 5;
const int motor2 = 6;
const int motor3 = 7;
const int motor4 = 8;

String password="murali";
String inputString="";


void setup() {
  Serial.begin(9600);
  bt.begin(9600);
}

void readingpassword(){
  Serial.print("Enter password : ");
  while(!Serial.available());
  inputString=Serial.readString();
}

bool passCheck(){
  if(inputString==password) {
    Serial.print("password matched");
    return true;
  }
  else {
    Serial.print("password not matched");
    return false;
  }
}

void forward(){
   bt.print("Moving forward");
   digitalWrite(motor1,HIGH);
   digitalWrite(motor2,LOW);
   digitalWrite(motor3,HIGH);
   digitalWrite(motor4,LOW);
}

void backward(){
   bt.print("Moving backward");
   digitalWrite(motor1,LOW);
   digitalWrite(motor2,HIGH);
   digitalWrite(motor3,LOW);
   digitalWrite(motor4,HIGH);
}

void left(){
  bt.print("Moving left");
   digitalWrite(motor1,HIGH);
   digitalWrite(motor2,HIGH);
   digitalWrite(motor3,HIGH);
   digitalWrite(motor4,LOW);
}

void right(){
   bt.print("Moving right");
   digitalWrite(motor1,HIGH);
   digitalWrite(motor2,LOW);
   digitalWrite(motor3,HIGH);
   digitalWrite(motor4,HIGH);
}

void Stop(){
   bt.print("Motion stop");
   digitalWrite(motor1,LOW);
   digitalWrite(motor2,LOW);
   digitalWrite(motor3,LOW);
   digitalWrite(motor4,LOW);
}

void sendFromArduinoTerminal(){
  bt.print("Enter data : ");
  while(!bt.available());
  inputString=bt.readString();
  bt.print(inputString);
  Serial.print("Recieved data : ");
  Serial.print(inputString);
}

void cardrive(){
  while(1){
    Serial.println("5 services are provided : ");
    Serial.println("1) Forward (press f)");
    Serial.println("2) Backward (press b)");
    Serial.println("3) Left (press l)");
    Serial.println("4) Right (press r)"); 
    Serial.println("5) Stop (press s)");
    //Serial.println("6) Recieve data from Arduino (press d)");
    Serial.println("6) Press any other key to exit.");
    Serial.print("Enter your choice : ");
    while(!Serial.available());
    inputString=Serial.readString();
    Serial.print(inputString);
    if(inputString=="f") forward();
    else if(inputString=="b") backward();
    else if(inputString=="l") left();
    else if(inputString=="r") right();
    else if(inputString=="s") Stop();
    else if(inputString=="d") sendFromArduinoTerminal();
    else break;
  }
}

void loop() {
  readingpassword();
  if(passCheck()== true) 
  cardrive();

}
