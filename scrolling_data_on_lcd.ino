#include<LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 4, 5, 6, 7);
int i=0,j=0,k=1;
int x;

void setup() {

lcd.begin(16,2);
pinMode(2,INPUT);

}

void loop() {
x=digitalRead(2); 
if(x==HIGH)
{
for(j =-8;j<=16;j++)
{
lcd.setCursor(j,i);
lcd.print(" HI ALL ");
delay(200);

}
}
else if(x==LOW)
{
for(j=16;j>=-14;j--)
lcd.setCursor(j,k);
lcd.print(" HOW ARE YOU ? ");
delay(200);

}  
}
}
