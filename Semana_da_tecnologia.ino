#include <Ultrasonic.h>

#include <MsTimer2.h>



#define TRIGGER_PIN  12  //verde
#define ECHO_PIN     13 //amarelo

#define TRIGGER_PIN2  8  //verde
#define ECHO_PIN2     9 //amarelo


Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);
Ultrasonic ultrasonic2(TRIGGER_PIN2, ECHO_PIN2);

volatile char centesimos, segundos, minutos;
volatile boolean mudouCrono = true;
volatile boolean cronoLigado = false;


void ajustaCronometro () {
   // Ajusta a cronometragem, a cada 10ms.
   centesimos++;

   if (centesimos == 100)  { // Completou 1 seg.
      centesimos = 0;
      segundos++;
      
      if (segundos == 60) {  // Completou 1 min.
         segundos = 0;
         minutos ++;
      }
   }
   
   // -Seta a bandeira, sinalizando mudan�a na
   // cronometragem...
   mudouCrono = true;
}



void setup () {
  Serial.begin(9600);
  pinMode(7, OUTPUT);
   //Incia valores de cronometragem:
   minutos = segundos = centesimos = 0;
  
//  Serial.println(x);
  digitalWrite(7,HIGH);
   
  // Exibe linha de t�tulo:
  //Serial.print ("Cronometragem");
  
   //Configura��o de MsTimer2:
  // MsTimer2::set (10, ajustaCronometro);  
  
}

void loop () {
int x = Serial.read();

  if( x== 1){

    digitalWrite(7, LOW);
    delay(2000);
    
    }
  
  float cmMsec, inMsec,cmMsec2, inMsec2;
  long microsec = ultrasonic.timing();
  long microsec2 = ultrasonic2.timing();
  
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  inMsec = ultrasonic.convert(microsec, Ultrasonic::IN);
  cmMsec2 = ultrasonic2.convert(microsec, Ultrasonic::CM);
  inMsec2 = ultrasonic2.convert(microsec, Ultrasonic::IN);
  //int x = 0;
   if  ( ( cmMsec > 6.0) )
   {  // Se bot�o acionado e cron�metro desligado,
      //liga-o e ativa o MsTimer2.
      //cronoLigado = true;
      //MsTimer2::start();
      //Serial.println("I");
   }   
   if     (   ( cmMsec2 < 6.0) )
  {  // Se bot�o liberado, e cron�metro ligado,
      // desliga-o e para o MsTimer2.      
      //cronoLigado = false;
     //Serial.println("F");
      //MsTimer2::stop();
      
      
   }
    /*  
   if (mudouCrono) {   
     // Se houve mudan�a na cronometragem, exibe o novo valor.
     
      
       Serial.print (minutos,DEC);    Serial.print (':');
       Serial.print (segundos,DEC);   Serial.print (':');
       Serial.print (centesimos,DEC); Serial.print ("   ");
     
      mudouCrono = false; // Desmarca o -flag-.

   }*/
}
