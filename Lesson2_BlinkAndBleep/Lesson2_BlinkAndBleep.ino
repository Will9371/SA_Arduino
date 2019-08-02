#include "pitches.h"

#define BUTTON 4
#define LED 12
#define SPEAKER 10

void setup() 
{
  pinMode(BUTTON, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(SPEAKER, OUTPUT);

  Serial.begin(9600);
}

void loop() 
{
  //SimpleLightSwitch();
  //ButtonTone();
  ButtonBlink();
}

void SimpleLightSwitch()
{
  if(digitalRead(BUTTON) == HIGH)
  {
    //Serial.println("Light ON");
    digitalWrite(LED, HIGH);
  }
  else
  {
    //Serial.println("Light OFF");
    digitalWrite(LED, LOW);
  }
}

void ButtonTone()
{
  if(digitalRead(BUTTON) == HIGH)
  {
    tone(SPEAKER, NOTE_D3);
  }
  else
  {
    noTone(SPEAKER);
  }
}
