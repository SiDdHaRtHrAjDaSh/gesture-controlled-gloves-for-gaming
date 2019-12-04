#include<SoftwareSerial.h>
SoftwareSerial s(8,10);//RX,TX
void setup() {
  s.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  int data=50;
  if(s.available()>0)
  {
    char c=s.read();
    if(c=='s')
    {
      s.write(data);
    }
  }
  // put your main code here, to run repeatedly:

}
