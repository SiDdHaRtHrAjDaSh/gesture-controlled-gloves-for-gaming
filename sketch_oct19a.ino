//#include <Keyboard.h>
#include<SoftwareSerial.h>
SoftwareSerial s(8,9);//(RX,TX)
const int FLEX_PIN1 = A0; 
const int FLEX_PIN2 = A1; 
const int FLEX_PIN3 = A2; 
const int FLEX_PIN4 = A3; 
const int FLEX_PIN5 = A4; 



const float VCC = 4.98;
const float R_DIV = 47500.0; 
int led = 13;


const float STRAIGHT_RESISTANCE = 0.0;
const float BEND_RESISTANCE = 100.0; 

void setup() 
{
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(FLEX_PIN1, INPUT);
  pinMode(FLEX_PIN2, INPUT);
  pinMode(FLEX_PIN3, INPUT);
  pinMode(FLEX_PIN4, INPUT);
  pinMode(FLEX_PIN5, INPUT);
  pinMode(8, OUTPUT);
  //Keyboard.begin();
}

void loop() 
{
  
  int flexADC1 = analogRead(FLEX_PIN1);
  int flexADC2 = analogRead(FLEX_PIN2);
  int flexADC3 = analogRead(FLEX_PIN3);
  int flexADC4 = analogRead(FLEX_PIN4);
  int flexADC5 = analogRead(FLEX_PIN5);
  
  Serial.println("Resistance: " +String(flexADC1)+"   "+ String(flexADC2)+"   "+String(flexADC3)+"   "+String(flexADC4)+"   "+String(flexADC5));
  /*Serial.println("Resistance: " +String(flexADC2));
  Serial.println("Resistance: " +String(flexADC3));
  Serial.println("Resistance: " +String(flexADC4));
  Serial.println("Resistance: " +String(flexADC5));*/
  
  
  
  if(flexADC1>200 && flexADC4>8 && flexADC3>800 && flexADC5>700 && flexADC2>59)
  Serial.println("HALT");
  if(flexADC3>800 && flexADC5>700 && flexADC2>59 && flexADC1<200 && flexADC4<8)
  Serial.println("MOVE IN");
  Serial.println();
  digitalWrite(8,1);
  /*if(flexADC1>10)
  {
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.println("SPACE IS PRESSED");
  }
  else
  {
  digitalWrite(LED_BUILTIN, LOW);
  //Serial.println("SPACE IS PRESSED")
  }
  delay(500);*/
}
