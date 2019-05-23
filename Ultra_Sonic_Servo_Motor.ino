#include<Servo.h>
Servo myservo;
int pos=0;
const int trigPin=4;
const int echoPin=5;
long duration;
int distance;
void setup()
{
  // put your setup code here, to run once:
  myservo.attach(13);
  pinMode(2,OUTPUT);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  Serial.begin(115200);

}

void loop()
{
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin,LOW);
  duration=pulseIn(echoPin,HIGH);
  //calculate the distance
  distance=duration*0.032/2;
  Serial.print("Distance:");
  Serial.println(distance);
   if(distance<10)
   {
     for(pos=0;pos<=180;pos++)
     {
       myservo.write(pos);
       if(pos==90)
       delay(200);
       delay(15);
     }
   
      delay(2000);
      for(pos=180;pos>=0;pos--)
     {
       myservo.write(pos);
       if(pos==90)
       delay(200);
       delay(15);
     } 
   }   
}


  
  
