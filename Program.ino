#include<Servo.h> //Importing Servo library
Servo servo1,servo2,servo3,servo4; //Creating instances under the Servo class
#define glassdoor 3
#define pir 2
#define trig 4
#define echo 5
#define sanitizer 6
#define gate1 9
#define gate2 10
#define greenled 11
#define redled 12
#define buzzer 13
int sig1=0,angle=0,distance=0,deg=0,deg1=0,i=0,j=0;
long duration;
void setup()
{
pinMode(glassdoor,OUTPUT);
pinMode(pir,INPUT);
servo1.attach(glassdoor);
pinMode(trig,OUTPUT);
pinMode(echo,INPUT);
servo2.attach(sanitizer);
pinMode(sanitizer,OUTPUT);
pinMode(gate1,OUTPUT);
pinMode(gate2,OUTPUT);
servo3.attach(gate1);
servo4.attach(gate2);
pinMode(greenled,OUTPUT);
pinMode(redled,OUTPUT);
pinMode(buzzer,OUTPUT);
Serial.begin(9600);
}
void loop()
{
  sig1=digitalRead(pir);
  if(sig1==HIGH)// Condition to operate the glass door
  {
    for(angle=0;angle<=180;angle+=10)
    {
      Serial.println("Opening glass door");
      servo1.write(angle); // To actuate the glass door,to open.
      delay(100);
    }
    delay(5000);
    for(angle=180;angle>=0;angle-=10)
    {
      Serial.println("Closing glass door");
      servo1.write(angle); // To actuate the glass door,to close.
      delay(100);
    }
  }
  digitalWrite(trig,LOW);
  delayMicroseconds(10);
  digitalWrite(trig,HIGH); // Send the pulse
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  duration=pulseIn(echo,HIGH); // Recieve the reflected pulse
  distance=(duration/58.138)*0.39; // distance is in inches
  if(distance==6)//For an approximate distance of 6 inches
  {
   for(deg=0;deg<=90;deg+=10)
    {
     Serial.println("Sanitizer getting dispensed");
      servo2.write(deg); // Actuate the sanitizer nozzle in order to get dispensed
     delay(100);
    }
    delay(500);
    for(deg=90;deg>=0;deg-=10)
    {
      Serial.println("Sanitized");
      servo2.write(deg); // Retraction of the sanitizer nozzle
      delay(150);
    }
    Serial.println("Please sanitize your hands & proceed towards the gate");
    delay(5000); // Time to clean the hands and move away from the dispenser
    for(deg1=0;deg1<=90;deg1+=10)
    {
      Serial.println("Pass-gates opening");
     servo3.write(deg1); // To open the pass gate
      servo4.write(deg1); // To open the pass gate
      delay(100);
    }
    for(i=0;i<3;i+=1)
    {
      digitalWrite(greenled,HIGH);// Green light indication
      delay(500);
      digitalWrite(greenled,LOW);
      delay(500);
    }
    
    for(deg1=90;deg1>=0;deg1-=10)
    {
      Serial.println("Pass-gates closing");
      servo3.write(deg1); // To close the pass gate
      servo4.write(deg1); //To close the pass gate
      delay(100);
    }
   digitalWrite(redled,HIGH);//Red light indication
   tone(buzzer,500);//Beep sound
   delay(2000);
   noTone(buzzer);
   digitalWrite(redled,LOW);
  }
}
