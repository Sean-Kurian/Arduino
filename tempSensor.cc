#include <OneWire.h>
#include <DallasTemperature.h>
double x;

// Data wire is plugged into port 7 on the Arduino
#define ONE_WIRE_BUS 7

// Setup a oneWire instance to communicate with any OneWire device
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);

void setup()
{
Serial.begin(9600);
Serial.println("Dallas Temperature IC Demo");
pinMode(13,OUTPUT);
sensors.begin();
}

void loop()
{
sensors.requestTemperatures(); // Send command to get temperature
Serial.print("Temp =  ");
x = (sensors.getTempCByIndex(0));
Serial.println(x); 
if (x < 28.50) {
   Serial.println("The buzzer is off"); 
   noTone(13);
   }
if (x >= 28.50) {
   Serial.println("The buzzer is on"); 
   tone(13,800); //turn the buzzer on
}
delay(2000);
}
