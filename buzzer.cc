int i;

void setup()
{
Serial.begin(9600);
pinMode(13,OUTPUT);

}

void loop()
{
Serial.println("The buzzer is on.");
for (i=0; i <= 2; i++){
     tone(13, 800, 2000);
     delay(1000);
   }
  
Serial.println("The buzzer is off.");
for (i=0; i <= 2; i++){
     noTone(13);
     delay(1000);
   }
}
