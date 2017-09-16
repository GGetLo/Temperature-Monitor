#define LED_GOOD 13
#define LED_BAD 12

int val;
int tempPin = 1;

// Magic 0.48828125
void setup()
{
  // Sets up the two pins as output provide power to LED
  pinMode(LED_GOOD, OUTPUT);
  pinMode(LED_BAD, OUTPUT);
  Serial.begin(9600);
}
void loop()
{
val = analogRead(tempPin);
float mv = ( val/1024.0)*5000; 
float cel = mv/10;
float farh = (cel*9)/5 + 32;

Serial.print("TEMPRATURE = ");
Serial.print(cel);
Serial.print("*C | ");

Serial.print(farh);
Serial.print("*F");
Serial.println();

if(farh > 82)
{
  digitalWrite(LED_BAD, HIGH);
  digitalWrite(LED_GOOD, LOW);
}
else
{
  digitalWrite(LED_BAD, LOW);
  digitalWrite(LED_GOOD, HIGH);  
}
  
  delay(1000);

}

