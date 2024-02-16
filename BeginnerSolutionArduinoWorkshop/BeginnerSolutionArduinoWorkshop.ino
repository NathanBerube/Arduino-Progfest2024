/*
* Solution to the beginner problem
* Arduino Workshop, Progfest 2024
* Nathan Bérubé, 15 Feb. 2024
*
*
*/
byte ledPin = 6;
byte frequency = 2;
int start;

void setup() {             
  Serial.begin(57600);
  Serial.println();
  Serial.println();
  Serial.println("Mise en marche de la LED");
  pinMode(ledPin, OUTPUT);
}

void loop() {
  start = millis();
  
  digitalWrite(ledPin, HIGH);
  delay(500/frequency);
  digitalWrite(ledPin, LOW);
  delay(500/frequency);

  Serial.print("Période: ");
  Serial.println(millis() - start);
}


