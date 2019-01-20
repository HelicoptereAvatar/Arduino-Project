/* Here is the code that I used to control the servos and the ESCs via Bluetooth */

#include <Servo.h>
#include<SoftwareSerial.h>
#define RX 10
#define TX 11
SoftwareSerial BlueT(RX,TX);
char Data;
int PWM=190;
int Angled=90;
int Angleg=90;
Servo esc1;   // Création de l'objet permettant le contrôle de l'ESC
Servo esc2;
Servo servo1;
Servo servo2;


 
void setup() {
   servo1.attach(2);
   servo2.attach(3);
   servo1.write(90);
   servo2.write(90);
   esc1.attach(6); // On attache l'ESC au port numérique 9 (port PWM obligatoire)
   esc2.attach(5);
   delay(15);
   //Serial.begin(9600);
   BlueT.begin(9600);
   // Initialisation de l'ESC
   //  (certains ESC ont besoin d'une "procédure d'initialisation"
   //   pour devenir opérationnels - voir notice)
   esc1.write(0);
   esc2.write(0);
   delay(1000);
   esc1.write(180);
   esc2.write(180);
   delay(1000);
   esc1.write(0);
   esc2.write(0);
   
   
   // Quelques informations pour l'utilisateur
   /*Serial.println("Saisir un nombre entre 0 et 179");
   Serial.println("(0 = arret - 179 = vitesse maxi");
   Serial.println(" demarrage a partir de 20)");*/
   }
 
void loop() {
  if (BlueT.available()){
    Data=BlueT.read();
    if(Data=='A'){
      PWM=BlueT.parseInt();
    }
    if (PWM>0){
      esc1.write(PWM);
      esc2.write(PWM+7);
      delay(5);
    }
    else{
      esc1.write(PWM);
      esc2.write(PWM);          
      delay(5);
      }
    if (Data=='D'){ //Angle entre 75deg et 120deg
        Angled=BlueT.parseInt();
        servo1.write(Angled);
        delay(5);
    }
    if (Data=='G'){  //Angle entre 30deg et 120deg
      Angleg=BlueT.parseInt();
      servo2.write(Angleg);
      delay(5);
  }
  }
}
