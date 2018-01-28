#include <GSM.h>
#include <SD.h>
#define PINNUMBER "1234" //code PIN
GSM gsmAccess;
GSM_SMS sms;
File myFile;
char senderNumber[20];
int count;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // attente
  }
  boolean notConnected = true;
  while (notConnected) { //initialisation connexion GSM
    if (gsmAccess.begin("1234") == GSM_READY) {
      notConnected = false;
    } else {
      Serial.println("Not connected");
      delay(1000);
    }
  }
  Serial.println("GSM initialized");
  
  if (!SD.begin(53)) { //initialisation connexion SD
    Serial.println("initialization failed!");
    while (1);
  }
  Serial.println("SD initialized");
}

void loop() {
  count = 0;
  char c;
  char tablo[278]; //nombre de caractères sur une ligne
  if (sms.available()) { //ouverture du SMS
    sms.remoteNumber(senderNumber, 20);
    if (sms.peek() == '#') {
      Serial.println("Discarded SMS");
      sms.flush();
    }
    while (count < sizeof(tablo)) { //lecture du SMS et remplissage du tableau
      while (c = sms.read()) {
        tablo[count] = c;
      }
      count++;
    }
    Serial.println(tablo); //affichage du SMS
    myFile = SD.open("test.txt", FILE_WRITE); //ouverture du fichier texte de la carte SD
    if (myFile) { //écriture sur fichier texte
      myFile.println(tablo);
    }
    myFile.close();
    sms.flush(); //supprime le SMS
    delay(1000);

  }

