int ledPin = 13;
int butonPin = 2;
int butonDurum =  0;

void setup() 
{
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(butonPin, INPUT);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  butonDurum = digitalRead(butonPin);
  
  if(butonDurum == HIGH)
  {
    digitalWrite(ledPin, HIGH)//Led'i yak
    delay(1000);
    digitalWrite(ledPin, LOW)//Led'i söndür
    delay(1000);
  }
  else
  {
    digitalWrite(ledPin, LOW);
  }
}
