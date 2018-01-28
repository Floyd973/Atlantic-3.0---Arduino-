#include <SoftwareSerial.h>
#include <SPI.h>
#include <SD.h>
SoftwareSerial mySerial(13, 12); // entrée RX, entrée TX sur la Mega
File myFile; //fichier texte sur carte SD
int count;
const int pinSS = 53; //entrée SS

void setup() {
  Serial.begin(9600);
  while (!Serial) { //attente
    ;
  }
  Serial.println("debut");
  mySerial.begin(9600);
  if (!SD.begin(pinSS)) { //initilialisation carte SD
    Serial.println("initialization failed!");
    while (1);
  }
  Serial.println("initialization done.");
  count = 0; //initialisation du count
}

void loop() { 
  char tablo[278]; //nombre de caractères sur une ligne
  while (count < sizeof(tablo)) { //on remplit le tableau sans sauter aucune case grace au count
    if (mySerial.available()) {
      tablo[count] = mySerial.read();
      count++;
    }
  }
  myFile = SD.open("test.txt", FILE_WRITE); //ouverture fichier texte
  if (myFile) { //ecriture 
    myFile.println(tablo);
    Serial.println(tablo); //affichage sur la console
    myFile.close();
  }
  count = 0;
  delay(1000);
}




