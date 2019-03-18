#include <Servo.h>
#include<SoftwareSerial.h>
#define RX 10
#define TX 11
SoftwareSerial BlueT(RX,TX);
char Data;
int PWM=190;
Servo esc;   // Création de l'objet permettant le contrôle de l'ESC
 
void setup() {
   esc.attach(3); // On attache l'ESC au port numérique 9 (port PWM obligatoire)
   delay(15);
   Serial.begin(9600);
   BlueT.begin(9600);
 
   // Initialisation de l'ESC
   //  (certains ESC ont besoin d'une "procédure d'initialisation"
   //   pour devenir opérationnels - voir notice)
   esc.write(0);
   delay(1000);
   esc.write(180);
   delay(1000);
   esc.write(0);
 
   // Quelques informations pour l'utilisateur
   Serial.println("Saisir un nombre entre 0 et 179");
   Serial.println("(0 = arret - 179 = vitesse maxi");
   Serial.println(" demarrage a partir de 20)");
   }
 
void loop() {
  if (BlueT.available()){
    Data=BlueT.read();
    if(Data=='A'){
      PWM=BlueT.parseInt();
    }
    if (PWM>0){
      esc.write(PWM);
      delay(15);
    }
    else{
      esc.write(PWM);          
      delay(15);
      }
  }
}
