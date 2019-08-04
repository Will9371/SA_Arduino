#include "pitches.h"
#include "songs.h"

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
  SimpleLightSwitch();
  //ButtonTone();

  if(digitalRead(BUTTON) == HIGH)
  {
    LowChime song;
    PlaySong(song.noteCount, song.notes, song.timeSignature);
  }
}

void PlaySong(int noteCount, int notes[], int timeSignature[])
{
  for(int i = 0; i < noteCount; i++)
  {
    int note_duration = 1000/timeSignature[i];
    
    if (notes[i] == 0)
    {
      noTone(SPEAKER);
    }
    else
    {
      tone(SPEAKER, notes[i]);
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
