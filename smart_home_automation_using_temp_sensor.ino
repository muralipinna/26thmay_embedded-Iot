const int fan = 3,cooler =5;
int temp;

void setup() {
  pinMode(fan,OUTPUT);
  pinMode(cooler,OUTPUT);

}
void temperature()
{
int v = analogRead(A0);
int x = analogRead(A1);
int dif = v - x ;
  float mv = ( dif/1024.0)*5000;
  float cel = mv/10;
 temp= cel;
}

void loop() {
  temperature();
 if(temp>=40)
 {for(int i=120;i<=255;i++)
 {
  analogWrite(fan,i);
  analogWrite(cooler,i);
 }
  }
  else if(temp<=30)
 {for(int i=0;i<=120;i++)
 {
  analogWrite(fan,i);
  analogWrite(cooler,i);
 }
  }
   else if(30>temp<40)
 {for(int i=90;i<=200;i++)
 {
  analogWrite(fan,i);
  analogWrite(cooler,i);
 }
  }
 }
