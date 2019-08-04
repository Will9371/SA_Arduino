#include "pitches.h"

#define BUTTON 4
#define LED 12
#define SPEAKER 10

int noteCount = 8;
int chime[] = { NOTE_C5, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_G4, 0, NOTE_B4, NOTE_C5 };
int time_signature[] = { 4, 8, 8, 4, 4, 4, 4, 4 };

void setup() 
{
  pinMode(BUTTON, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(SPEAKER, OUTPUT);

  Serial.begin(9600);
}

void loop() 
{
  SimpleLightSwitch();
  //ButtonTone();

  if(digitalRead(BUTTON) == HIGH)
  {
    PlaySong();
  }
}

void PlaySong()
{
  for(int i = 0; i < noteCount; i++)
  {
    int note_duration = 1000/time_signature[i];
    
    if (chime[i] == 0)
    {
      noTone(SPEAKER);
    }
    else
    {
      tone(SPEAKER, chime[i]);
    }  
    delay(note_duration);
    noTone(SPEAKER);
    delay(note_duration / 3); 
  } 
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
