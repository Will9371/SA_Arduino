#include "pitches.h" 

#define ECHO 9
#define TRIGGER 11
#define SPEAKER 10

int duration;
long distance;
unsigned long lastNoteTime;

int notes[8] = { NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5 };
int distances[8] = { 10, 15, 20, 25, 30, 35, 40, 50 };

void setup() 
{
  pinMode(SPEAKER, OUTPUT);
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);

  Serial.begin(9600);
}

void loop() 
{
  SendPulse();

  // Get the distance information from the sensor
  duration = pulseIn(ECHO, HIGH);

  // Calculate the distance based on duration
  distance = duration / (29.1 * 2);
  
  CheckForNote();  
  //Serial.println(distance);
}

void SendPulse()
{
  digitalWrite(TRIGGER, LOW);
  delayMicroseconds(5);
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER, LOW); 
}

void CheckForNote()
{  
  if (millis() - lastNoteTime > 100 && distance > 0)
  {
    // Play notes on a scale
    PlayNote();

    // Play notes on a continuous range
    //tone(SPEAKER, distance);
    
    lastNoteTime = millis();
  }
  else if (distance > 50)
  {
    noTone(SPEAKER);
  }
}

void PlayNote()
{ 
  for (int i = 0; i < 8; i++)
  {
    if (distance < distances[i])
    {
      tone(SPEAKER, notes[i]);
      return;
    }
  } 
}
