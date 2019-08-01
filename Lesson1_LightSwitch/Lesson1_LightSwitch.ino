#define BUTTON 4
#define LED 12

void setup() 
{
  pinMode(BUTTON, INPUT);
  pinMode(LED, OUTPUT);

  Serial.begin(9600);
}

void loop() 
{
  SimpleLightSwitch();
}

void SimpleLightSwitch()
{
  if(digitalRead(BUTTON) == HIGH)
  {
    Serial.println("Light ON");
    digitalWrite(LED, HIGH);
  }
  else
  {
    Serial.println("Light OFF");
    digitalWrite(LED, LOW);
  }
}
