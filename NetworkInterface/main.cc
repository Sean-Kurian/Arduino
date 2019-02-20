//The code creates an static address named ledPin and 
// sets pin 13 as an output

const int ledPin = 13; 			


// The following code line creates an address to read incoming serial 
// data into	
						  
int incomingByte;      			
 
void setup() {


// The following code line initializes serial communication at 9,600 baud rate 
Serial.begin(9600); 	
		
// The following code line sets the pin address (pin 13) as a static output   
pinMode(ledPin, OUTPUT);		

}
 
void loop() {
// The following code line checks if there is incoming serial data it 
// has to be greater than 0  

if (Serial.available() > 0) {		

// The following code line creates an address named incomingByte and 
//stores the data from the Serial port    

incomingByte = Serial.read();	


// The following code line chceks if the incoming data is equal to H 
// then apply 5V DC to pin 13 
   
    if (incomingByte == 'H') {		
      digitalWrite(ledPin, HIGH);
}
// The following code line checks if the incoming data is equal to L 
// then apply 0V DC to pin 13    

    if (incomingByte == 'L') {		
      digitalWrite(ledPin, LOW);
      }
  }
}
