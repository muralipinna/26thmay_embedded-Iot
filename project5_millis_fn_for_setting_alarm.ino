#include<LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
unsigned long x = 0;
byte sec = 20;
byte minute = 10;
byte hr = 8;
int p2 = 3;
int p3 = 4;
byte hourupg = 8;
byte minupg = 11;
byte secong = 25;
int mode = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(p2, INPUT_PULLUP);
  pinMode(p3, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(5, OUTPUT);
  lcd.begin(16, 2);
  DisplayTime();
}
//getting error sir
// just make a prototye in such cases
void DisplaySetHour()
{ // this is okay
  lcd.setCursor(0,0);
  lcd.print("Hour Change         ");
  lcd.setCursor(0,1);
  lcd.print(hourupg);
  lcd.print("                   ");
  if (digitalRead(p2) == LOW)
  { while (digitalRead(p2) == LOW);
    if (hourupg == 23)
    {
      hourupg = 0;
    }
    else
    {
      hourupg = hourupg + 1;
    }
  }


  if (digitalRead(p3) == LOW)
  {
    while (digitalRead(p3) == LOW);
    if (hourupg == 0)
    {
      hourupg = 23;
    }
    else
    {
      hourupg = hourupg - 1;
    }
  }

}

void DisplaySetMinute()
{
  // Display these times also so we can make changes to it
  lcd.setCursor(0,0);
  lcd.print("Minutes Change        ");
  lcd.setCursor(0,1);
  lcd.print(minupg);
  lcd.print("                      ");
  if (digitalRead(p2) == LOW)
  {
    while (digitalRead(p2) == LOW);
    if (minupg == 59)
    {
      minupg = 0;
    }
    else
    {
      minupg = minupg + 1;
    }
  }
  if (digitalRead(p3) == LOW)
  {
    while (digitalRead(p3) == LOW);
    if (minupg == 0)
    {
      minupg = 59;
    }
    else
    {
      minupg = minupg - 1;
    }
  }
}
void DisplaySetSecond()
{
  lcd.setCursor(0,0);
  lcd.print("Seconds Change   ");// this space will replace the clear function role
  lcd.setCursor(0,1);
  lcd.print(secong);
  lcd.print("                ");
  if (digitalRead(p2) == LOW)
  {
    while (digitalRead(p2) == LOW);
    if (secong == 59)
    {
      secong = 0;
    }
    else
    {
      secong = secong + 1;
    }
  }
  if (digitalRead(p3) == LOW)
  {
    while (digitalRead(p3) == LOW);
    if (secong == 0)
    {
      secong = 59;
    }
    else
    {
      secong = secong - 1;
    }
  }

}
void Alarm()
{ 
  lcd.setCursor(0, 0);
  lcd.print("set alarm");
  lcd.setCursor(0, 1);
  lcd.print(hourupg);
  lcd.print(":");
  lcd.print(minupg);
  lcd.print(":");
  lcd.print(secong);
  delay(10);// if you dont stop it for a time and will keep clearing you wont able to see it correctly
}
void  final()
{
  if ((hr == hourupg) && (minute == minupg) && (sec == secong))
  {
    tone(5, 880);
    delay (300);
    tone(5, 698);
    // this delay will cause a probl

  }
}
// i think we have do it like this way sir
// yes bring all the f/n above loop() & Then simulate it
// I dont see any logic error in code, it must work fine, unless flow of code disrupts
//  Try it and tell the status

void DisplayTime() {
  if (millis() >= x) { // time cahge parameteres should be kept in main program not in functions
    //////// Keep this segment in loop() start
    x = x + 1000;
    sec = sec + 1;
    if (sec == 60)
    { sec = 0;
      minute = minute + 1;
    }
    if (minute == 60)
    { minute = 0;
      hr = hr + 1;
    }

    if (hr == 24)
    { hr = 1;
      minute = minute + 1;
    }
    //////////

    // Show 0 alongside the single digit time parameter that will remove your lcd.clear() function
    lcd.setCursor(0, 0);
    lcd.print("DIGITAL CLOCK");
    lcd.setCursor(0, 1);
    // like
    if (hr < 10) {
      lcd.print(0);
      lcd.print(hr);
      // In this senerio you wont need the clear(), and the i used the clear function to clear the display for digital clock and show the set alarm
      // yes, and that is also causing the blink problem, you must use it in such manner so that it must not call multiple time unneccesary
      lcd.print(":");
      lcd.print(minute);
      lcd.print(":");
      lcd.println(sec);
      delay(10);
    }

  }

}
void loop() {
  if (digitalRead(2) == LOW) {
    while (digitalRead(2) == LOW);
    mode = mode + 1;
    if (mode == 5){
      mode = 0;
    }
  }

  if (mode == 1) {
    lcd.clear(); // This statremeent will cause constant blink of alarm time
    Alarm(); // ehere some it through error when function are defined after its use (IDE issue)
  } else if (mode == 2){
    DisplaySetHour();
  } else if (mode == 3) {
    DisplaySetMinute();
  } else if (mode == 4) {
    DisplaySetSecond();
  } else {
    DisplayTime();// this part will not run when this code starts so an logical Error, It must be showing after start of code
    final(); // play buzzer when time is displaying not in time set mode
  }
  

  // where did you reset the mode parameter
  // only one of these statemets will work so better use else if
}
