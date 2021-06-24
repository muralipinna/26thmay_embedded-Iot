#include<LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 4, 5, 6, 7);

void setup() {
Serial.begin(9600);
lcd.begin(16,2);
}
String ch;
void loop() {
  if (Serial.available()){
    ch=Serial.readString();
     unsigned char len = ch.length();
   for(int i=-1;i>=-1*(len-16);i--)
{
lcd.setCursor(i,0);
lcd.print(ch);
delay(200);

}
  }
}
