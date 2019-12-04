#include<Keyboard.h>
#include<Mouse.h>
const int FLEX_PIN = A0;// Pin connected to voltage divider output
const int x=A1;
const int y=A2;
const int z=A3;
const int trigPin = 9;
const int echoPin = 10;
const int receivepin = 7;
const int receivepin2 = 8;

//wssad

const float VCC = 4.98; 
const float R_DIV = 47500.0;


const float STRAIGHT_RESISTANCE = 37300.0; 
const float BEND_RESISTANCE = 90000.0; 
long duration;
int distance;

void setup() 
{
  Serial.begin(9600);
  pinMode(FLEX_PIN, INPUT);
  pinMode(x, INPUT);
  pinMode(y, INPUT);
  pinMode(z, INPUT);
  pinMode(receivepin, INPUT);
  pinMode(receivepin2, INPUT);
  pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT); 
 Mouse.begin();
  Keyboard.begin();                  
}

void loop() 
{

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance= duration*0.034/2;

  

//EE
  int flex=digitalRead(receivepin);
  int flex2=digitalRead(receivepin2);
  Serial.println(String(flex));
    Serial.println("Sensor of E: "+String(flex2));
  // Read the ADC, and calculate voltage and resistance from it
  int flexADC = analogRead(FLEX_PIN);
  int X = analogRead(x);
  int Y = analogRead(y);
  int Z = analogRead(z);
  if(flex==1)
  Keyboard.press(129);
  else
  Keyboard.releaseAll();
  
  
  if(flex2==1)
  Keyboard.press('e');
  else
  Keyboard.releaseAll();



if(distance<7)
Keyboard.press(' ');
else
Keyboard.releaseAll();



if(X<280)
{Keyboard.press('a');
}
else if(X>310)
{
  Keyboard.press('d');
}
else if(Y>365)
{
  Keyboard.press('w');
}
else if(Y<300)
{
  Keyboard.press('s');
}
else
Keyboard.releaseAll();



 

 Serial.println(String(X)+"    "+String(Y)+"    "+String(Z)+"    ");

 


}
