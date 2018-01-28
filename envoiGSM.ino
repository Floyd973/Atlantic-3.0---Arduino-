#include <GSM.h>
#include <SPI.h>
#include <SD.h>
#define PINNUMBER "1234" //code PIN
GSM gsmAccess;
GSM_SMS sms;
File myFile;
char c[278]; //278 = nb de caractère sur une ligne de LOG

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ;
  }

  boolean notConnected = true; //initialisation du GSM
  while (notConnected) {
    if (gsmAccess.begin("1234") == GSM_READY) {
      notConnected = false;
    } else {
      Serial.println("Not connected");
      delay(1000);
    }
  }
  Serial.println("GSM initialized");

  if (!SD.begin(53)) { //initialisation de la carte SD
    Serial.println("initialization failed!");
    while (1);
  }
  Serial.println("SD initialized");

  myFile = SD.open("test.txt"); //ouverture du fichier texte de la carte SD

}

void loop() {

  if (myFile) { //lecture du fichier texte 
    int count = 0;
    while (count < 278) {
      if (myFile.available()) {
        c[count] = (myFile.read());
        count++;
      }
    }
  } else {
    Serial.println("error opening test.txt");
  }
  Serial.println(c); //affichage du fichier texte
  sms.beginSMS("0608734958"); //entrez le numéro
  sms.print(c); //envoi du fichier texte par SMS
  sms.endSMS();
  Serial.println("\nCOMPLETE!\n");
  delay (1000);
}
