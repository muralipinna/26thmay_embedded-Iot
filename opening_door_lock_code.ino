#include<Servo.h>
Servo motor;
String pas = "murali";
int i = 180;
void setup() {
  Serial.begin(9600);
  Serial.begin(9600);
  motor.attach(9);
}
char ch;
String localPass = "";
void loop() {

  if (Serial.available()) {
    ch = Serial.read();
    if (ch == '\n' || ch == '\r') {// when Newline is detected (Enter)
      if (localPass == pas) {
        Serial.println("Passowrd Matched");
        motor.write(i);
      } else {
        Serial.println("Password NOT Matched");
      }
      localPass = "";
    } else {
      localPass += ch;
    }
  }

  /*
    if (Serial.available()) {
        String st = Serial.readString();

        if (st == pas){
          Serial.println();
          Serial.println("Password Matched");
        }else{
          Serial.println();
          Serial.println("Password Not Matched");
        }
    }
    /*
      while (Serial.available())
      {
      String val = Serial.readString();

      if ( val == pas )
      {Serial.print("You are welcome ");
      motor.write(i);

      }
      else
      {
      Serial.print("You entered a wrong password ");
      }
      }
  */

}
