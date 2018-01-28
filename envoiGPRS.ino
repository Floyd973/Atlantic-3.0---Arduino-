#include <SoftwareSerial.h>
SoftwareSerial GPRS(10, 3); //intrinsèque au shield GSM
unsigned char buffer[64];
int count = 0;
String adresse = "http://phoenix44.pythonanywhere.com/traitement/?nom=movox&date=25janvier2018&logg=coucoucfloydy"; //mettre l'URL 

void setup() {
  Serial.begin(9600);
  GPRS.begin(9600);
  delay(1000);
  GPRS.println("AT");
}

void loop() {
  lecture();
  GPRS.println("AT+QIFGCNT=0"); //initialisation
  lecture();
  GPRS.println("AT+CPIN=\"1234\""); //code pin
  lecture();
  GPRS.println("AT+QICSGP=1,\"free\""); //APN
  lecture();
  GPRS.println("AT+QHTTPURL="+String(adresse.length())+",30"); //longueur de l'URL
  lecture();
  GPRS.println(adresse); //URL
  lecture();
  GPRS.println("AT+QHTTPGET=60"); //envoi de la requête
  lecture();
  delay(1000);
  GPRS.println("AT+QHTTPREAD=30"); //recption et affichage
  delay(1000);
  lecture();
}


void lecture() { //permet l'affichage de la réponse
  delay(1000);
  if (GPRS.available()) {
    while (GPRS.available()) {
      buffer[count++] = GPRS.read();
      if (count == 64)break;
    }
    Serial.write(buffer, count);
    clearBufferArray();
    count = 0;
  }
}

void clearBufferArray() {
  for (int i = 0; i < count; i++) {
    buffer[i] = NULL;
  }
}
