#include <MsTimer2.h>
#include <Ultrasonic.h>

#define TRIGGER_PIN  12  //BRANCO
#define ECHO_PIN     13 //VERDE

#define TRIGGER_PIN2  8  //BRANCO
#define ECHO_PIN2     9 //VERDE


Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);
Ultrasonic ultrasonic2(TRIGGER_PIN2, ECHO_PIN2);

volatile boolean cronoLigado = false;



void setup () {
  Serial.begin(9600);


}

void loop () {
  float cmMsec, inMsec, cmMsec2, inMsec2;
  long microsec = ultrasonic.timing();
  long microsec2 = ultrasonic2.timing();

  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  inMsec = ultrasonic.convert(microsec, Ultrasonic::IN);
  cmMsec2 = ultrasonic2.convert(microsec2, Ultrasonic::CM);
  inMsec2 = ultrasonic2.convert(microsec2, Ultrasonic::IN);
  
  if  ( ( cmMsec > 6.5) && (cmMsec2 > 6.5))
  {
        Serial.println("I");

  } else if  ( ( cmMsec2 < 6.5) && (cmMsec > 6.5))
  {
        Serial.println("F");
  }
  
}


