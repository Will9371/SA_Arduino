int trigPin = 11;    // Trigger
int echoPin = 12;    // Echo
int speaker = 10;    // PWM Output
int light = 9;       // PWM Output
float duration, cm, inches;
float intensity;

const int MAX_INTENSITY = 125;
 
void setup() 
{
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(light, OUTPUT);
  pinMode(speaker, OUTPUT);

  Serial.begin (9600);
}
 
void loop() 
{
  SendPulse(trigPin, 5, 10);

  duration = ReadPulse(echoPin);
  //Serial.print(duration);
  //Serial.println(" microseconds");
 
  // Convert the time into a distance
  cm = duration / 29.1;
  inches = duration / 74;

  intensity = GetIntensity(cm, 4, 40);
  //Serial.print("Intensity = ");
  //Serial.println(intensity);

  analogWrite(speaker, intensity);
  analogWrite(light, intensity);
}

// The sensor is triggered by a HIGH pulse of 10 or more microseconds.
// Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
void SendPulse(int pin, int clearDuration, int pulseDuration)
{
  digitalWrite(pin, LOW);
  delayMicroseconds(clearDuration);
  digitalWrite(pin, HIGH);
  delayMicroseconds(pulseDuration);
  digitalWrite(pin, LOW);  
}

// a HIGH pulse whose duration is the time (in microseconds)
// from the sending of the ping to the reception of its echo off of an object.
long ReadPulse(int pin)
{
  pinMode(pin, INPUT);
  long travelTime = pulseIn(pin, HIGH);
  return travelTime / 2;  
}

float GetIntensity(float distance, float minimum, float maximum)
{
  if (distance > maximum)
  {
    distance = maximum;
  }
  if (distance < minimum)
  {
    distance = minimum;
  }
  
  float percent = 1 - ((distance - minimum) / (maximum - minimum));
  
  //Serial.print("Distance (cm) = ");
  //Serial.print(distance);
  //Serial.print(", Percent = ");
  //Serial.println(percent);

  return MAX_INTENSITY * percent;
}
