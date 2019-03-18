#include<Servo.h>
#include<SoftwareSerial.h>
#define RX 10
#define TX 11
SoftwareSerial BlueT(RX,TX);
char Data;
int PWM=0;

Servo servo1;

void setup() {
  // put your setup code here, to run once:
  servo1.attach(12);
  BlueT.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (BlueT.available()){
    Data=BlueT.read();
    if(Data=='B'){
      PWM=BlueT.parseInt();
    }
    if (PWM>0){
      servo1.write(PWM);
      delay(15);
    }
    else{
      servo1.write(PWM);          
      delay(15);
      }
   }

}
