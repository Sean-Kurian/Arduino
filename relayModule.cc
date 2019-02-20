
// Basic 2 Realy board connection
// Each relay is turned on for 2 seconds and then off.

#define RELAY1  2                        
#define RELAY2  3                        


void setup()
{    
// Initialise the Arduino data pins for OUTPUT
  pinMode(RELAY1, OUTPUT);       
  pinMode(RELAY2, OUTPUT);
  
}

void loop()
{
   digitalWrite(RELAY1,LOW);           // Turns ON Relays 1
   delay(2000);                                      
   digitalWrite(RELAY1,HIGH);          // Turns Relay Off

   digitalWrite(RELAY2,LOW);           // Turns ON Relays 2
   delay(2000);                                      
   digitalWrite(RELAY2,HIGH);          // Turns Relay Off
 
 }
