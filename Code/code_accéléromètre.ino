#include <Wire.h>
const int MPU_addr = 0x68;
float Acc_X, Acc_Y, Acc_Z; 
float angle_x,angle_y,angle_z;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Wire.begin(); 
  Wire.beginTransmission(MPU_addr); 
  Wire.write(0x6B); 
  Wire.write(0);
  Wire.endTransmission(); 

}

void loop() {
  // put your main code here, to run repeatedly:
  Wire.beginTransmission(0x68);
  Wire.write(0x3B);
  Wire.endTransmission(false); 
  Wire.requestFrom(0x68,6,true);

  Acc_X=(Wire.read()<<8|Wire.read());
  Acc_Y=(Wire.read()<<8|Wire.read());
  Acc_Z=(Wire.read()<<8|Wire.read()); 

  angle_x = (atan((Acc_X/16384) / sqrt(pow((Acc_Y/16384),2) + pow((Acc_Z/16384),2))) * 180/PI);
  angle_y = (atan((Acc_Y/16384) / sqrt(pow((Acc_X/16384),2) + pow((Acc_Z/16384),2))) * 180/PI);
  Serial.print(angle_x);
  Serial.print("  ");
  Serial.println(angle_y);
  Serial.print("  ");

  


}
