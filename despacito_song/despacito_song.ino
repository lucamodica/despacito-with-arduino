
#include "note.h"

// pin used: 
const int buzzerPin = 5;
const int led1 = 7;
const int led2 = 8;

// notes in the melody:
int melody[] = {
  RE5, DO_5, SI4, FA_4, FA_4, FA_4, FA_4, FA_4, FA_4, SI4, SI4, SI4, SI4, LA4, SI4, SOL4,
  SOL4, SOL4, SOL4, SOL4, SOL4, SI4, SI4, SI4, SI4, DO_5, RE5, LA4, LA4, LA4, LA4, LA4,
  LA4, RE5, RE5, RE5, RE5, RE5, MI5, MI5, MI5, DO_5, DO_5, 0, RE5, DO_5, SI4,
  FA_4, FA_4, FA_4, FA_4, FA_4, FA_4, SI4, SI4, SI4, SI4, LA4, SI4, SOL4, 0, SOL4,
  SOL4, SOL4, SOL4, SOL4, SOL4, SI4, SI4, SI4, SI4, DO_5, RE5, LA4, LA4, LA4, LA4,
  LA4, LA4, LA4, RE5, RE5, RE5, RE5, RE5, MI5, MI5, DO_5, LA5, LA5, LA5, LA5,
  LA5, LA5, 0, LA5, LA5, LA5, LA5, FA_5, MI5, FA_5, MI5, FA_5, MI5, FA_5, MI5, FA_5,
  MI5, FA_5, SOL5, SOL5, RE5, 0, SOL5, SOL5, SOL5, SOL5, SOL5, SOL5, LA5, LA5, FA_5, 0,
  FA_5, FA_5, FA_5, FA_5, 0, LA5, SOL5, FA_5, MI5, MI5, MI5, MI5, MI5, MI5, MI5, MI5,
  MI5, DO_5, RE5, FA_5, MI5, FA_5, MI5, FA_5, MI5, FA_5, 0, MI5, 0, FA_5, MI5, FA_5,
  SOL5, SOL5, RE5, 0, SOL5, SOL5, SOL5, SOL5, SOL5, LA5, SOL5, FA_5, 0, FA_5, FA_5, FA_5,
  FA_5, FA_5, 0, LA5, LA5, SOL5, FA_5, MI5, 0, RE5, RE5, RE5, RE5, RE5, RE5, 
  RE5, SI4, SI4, SI4, 0, SI4, DO_5, RE5, RE5, DO_5, SI4, RE5, SI4, SI4,
  0, SI4, DO_5, RE5, RE5, DO_5, SI4, RE5, SI4, SI4, 0, SI4, DO_5, RE5,
  DO_5, DO_5, SI4, RE5, SI4, SI4, 0, SI4, RE5, RE5, RE5, 0, RE5,
  SI4, SI4, RE5, SI4, SI4, 0, MI5, MI5, MI5, RE5, MI5, MI5, MI5, MI5,
  MI5, FA_5, MI5, MI5, RE5, RE5, RE5, 0, MI5, MI5, MI5, 0, MI5, MI5,
  MI5, MI5, MI5, RE5, MI5, FA_5, MI5, RE5, RE5, RE5, LA4, RE5, RE5, RE5,
  LA4, RE5, RE5, RE5, RE5, RE5, RE5, RE5, RE5, LA4, MI5, RE5, 0, RE5,
  RE5, 0, RE5, RE5, 0, RE5, RE5, RE5, RE5, RE5, RE5, RE5,
  RE5, LA4, MI5, RE5, 0, RE5, RE5, RE5, RE5, FA_5, FA_5, FA_5, FA_5, LA5,
  LA5, RE5, RE5, RE5, RE5, 0, FA_5, FA_5, FA_5, FA_5, MI5, 0, //MI5, 0,
  MI5, 0, MI5, 0, RE5, 0, MI5
  
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
float noteDurations[] = {
  2, 2, 4, 4, 8, 8, 8, 8, 8, 8, 8, 8, 4, 8, 4, 3,
  8, 8, 8, 8, 8, 8, 8, 8, 4, 8, 4, 3, 8, 8, 8, 16,
  16, 8, 8, 16, 16, 4, 8, 8, 8, 2, 8, 4, 2, 2, 4,
  4, 8, 8, 8, 8, 8, 16, 16, 8, 4, 8, 4, 4, 8, 8,
  16, 16, 8, 8, 8, 8, 8, 8, 4, 8, 4, 3, 8, 16, 16,
  8, 8, 8, 8, 8, 16, 16, 8, 4, 4, 8, 8, 8, 8, 8,
  8, 8, 4, 8, 8, 8, 3, 8, 8, 8, 8, 4, 8, 4, 8, 8,
  8, 4, 8, 4, 3, 3, 4, 8, 8, 8, 8, 8, 8, 4, 2, 3,
  8, 8, 8, 8, 8, 4, 8, 4, 4, 8, 8, 8, 8, 8, 8, 8,
  8, 4, 4, 8, 8, 8, 8, 8, 8, 4, 8, 6, 16, 8, 6, 6,
  8, 4, 3, 4, 4, 8, 8, 8, 4, 8, 4, 2, 3, 8, 16, 16,
  8, 8, 8, 8, 8, 5, 6, 1.5, 8, 8, 8, 8, 16, 16, 8, 
  8, 8, 16, 16, 8, 8, 8, 16, 16, 8, 8, 8, 16, 16,
  8, 8, 8, 16, 16, 8, 8, 8, 16, 16, 8, 8, 8, 8,
  16, 16, 8, 9, 16, 16, 8, 8, 16, 16, 16, 16, 8,
  16, 16, 8, 16, 16, 4, 8, 8, 8, 8, 7, 8, 8, 8,
  8, 8, 16, 16, 8, 4, 8, 8, 8, 8, 16, 16, 8, 9,
  16, 16, 8, 8, 8, 8, 8, 8, 4, 8, 8, 8, 8, 8,
  8, 9, 8, 8, 8, 8, 8, 8, 8, 8, 4, 8, 8, 16,
  16, 16, 16, 16, 16, 16, 17, 8, 8, 8, 8, 8,
  8, 8, 4, 8, 8, 8, 8, 8, 8, 17, 8, 8, 8, 8,
  8, 8, 8, 4, 8, 8, 8, 8, 8, 8, 9, 8, //8, 16,
  8, 16, 8, 16, 8, 16, 4
  
  
};

void setup() {
  
  pinMode(buzzerPin, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop(){

  int cont=0; //This variable allow the the leds to altrnate
  
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 333; thisNote++) {

    /* to calculate the note duration, take one second
       divided by the note type.
       e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc. */
    float duration = 1000 / noteDurations[thisNote];
    
    if(melody[thisNote]!=0){
      if(cont%2==0){
        digitalWrite(led1,HIGH);
      }
      else{
        digitalWrite(led2,HIGH);
      }
    }
    tone(buzzerPin, melody[thisNote], duration);
    cont++;
    
    // to distinguish the notes,I set a minimum time between them.
    float pauseBetweenNotes = duration * 1.40;
    delay(pauseBetweenNotes);
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    noTone(buzzerPin);
    
  }
  delay(700);
}
