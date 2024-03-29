/*
* Solution to the intermediate problem
* Arduino Workshop, Progfest 2024
* Nathan Bérubé, 15 Feb. 2024
*
* Threshold was fixed with a 20k resistor for the tension divider
*
*
*/
byte readingPin = A0;
int reading;
int threshold = 700;

void setup() {             
  Serial.begin(57600);
  Serial.println();
  Serial.println();
  Serial.println("Mise en marche");
  pinMode(readingPin, INPUT);
}

void loop() {
  reading = analogRead(readingPin);
  Serial.println(reading);
  if (reading < threshold){
    Serial.println("C'est le jour!");
  }
  else{
    Serial.println("C'est la nuit!");
  }
  delay(1000);
}

