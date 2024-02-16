/*
* Solution to the hard problem
* Arduino Workshop, Progfest 2024
* Nathan Bérubé, 15 Feb. 2024
*
*
*/



byte sensorPin = 7;
byte ledPin = 6;
byte alarmPin = 5;
bool reading;
bool is_armed;
long iteration=0;

void setup() {             
  Serial.begin(57600);
  Serial.println();
  Serial.println();
  Serial.println("Mise en marche du système d'alarme");
  pinMode(sensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(alarmPin, INPUT_PULLUP);
  digitalWrite(ledPin, LOW);

}

void loop() {
  is_armed = !digitalRead(alarmPin); // LOW is armed, HIGH is desactivated since pins are pull up.
  if (is_armed){
    reading = !digitalRead(sensorPin);
    if(reading==true){
      Serial.println("Il y a quelqu'un!!!");
      digitalWrite(ledPin, HIGH);
      delay(200);
      digitalWrite(ledPin, LOW);
      delay(200);
      digitalWrite(ledPin, HIGH);
      delay(200);
      digitalWrite(ledPin, LOW);
    }
    else {
      if(iteration % 20 == 0){
      Serial.println("Le système d'alarme est armé...");
      delay(1000);
      }
    }
  }
  else{
    if(iteration % 20 == 0){
      Serial.println("Le système d'alarme est désactivé...");
      delay(1000);

    }
  }
  iteration++;
}
