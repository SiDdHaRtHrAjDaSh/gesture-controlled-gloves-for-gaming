
const int FLEX_PIN = A0; // Pin connected to voltage divider output
const int FLEX_PIN2 = A1; // Pin connected to voltage divider output


void setup() 
{
  Serial.begin(9600);
  pinMode(FLEX_PIN, INPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
}

void loop() 
{

  int flexADC = analogRead(FLEX_PIN);
  int flexADC2 = analogRead(FLEX_PIN2);
 
  Serial.println("Resistance: " + String(flexADC) + " ohms"+" "+String(flexADC2));
 
  if(flexADC>620)
  digitalWrite(8,HIGH);
  else
  digitalWrite(8,LOW);

  if(flexADC>660)
  digitalWrite(9,HIGH);
  else
  digitalWrite(9,LOW);

  
  Serial.println();

  delay(500);
}
