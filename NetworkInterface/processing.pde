/* Processing script for web interface to illuminate or turn 
// off an LED on an Arduino */
 
 import processing.serial.*;      //Import file from library 
 Serial port;                     //Creates an address called port linking 
                                  //it to the serial port
 
 void setup()  {                  
 
/* The number in brackets after "Serial.list()[1]" determines the COM port 
   the Arduino is connected to.
   For example: My computer has COM1 and Com5. My Arduino is connected to Com 5; 
   therefore, I am using Serial.list()[1]
   If your Arduino is connected to COM 1 then use Serial.list()[0]. 
   If you have three COM ports as: COM1, COM3, COM 5 and you are using 
   COM 5 then use Serial.list()[2]. 
   This is how the serial Com ports are numbered:
       COM 1  = Serial.list()[0]
       COM 3  = Serial.list()[1]
       COM 5  = Serial.list()[2]
*/

// The following code line prints out the active serial COM port list 

    println(Serial.list());
    
    
// The following code line opens the serial port that the Arduino 
// board is connected to at 9,600 baud rate  
                              
    port = new Serial(this, Serial.list()[1], 9600);   
 
}
// Called directly after setup(), the draw() function continuously executes 
// the lines of code contained inside its block until 
// the program is stopped or noLoop() is called. draw() is called 
// automatically and should never be called explicitly.
// It should always be controlled with noLoop(), redraw() and loop(). 
// If noLoop() is used to stop the code in draw() from executing, 
// then redraw() will cause the code inside draw() to be executed 
// a single time, and loop() will cause the code inside draw() to 
// resume executing continuously.


 void draw() {
  // The following code creates an variable array address 
  // called onoffdata and loads the .txt 
  // file data into the address from the website text file
  String onoffdata[] = loadStrings("http://laxton.ca/ard_php/LED_data.txt"); 
  
  
// The following code line prints whatever the data is in the LED_data file (1 or 0)  
  print(onoffdata[0]);                                  
 
 
// The following code line checks if the data in LED_data text file = 1 
// then run the next two lines of code 
  
  if (onoffdata[0].equals("1") == true) {               
    println(" - LED ON");
    
    
 // The following code line sends "H" over serial to set the LED to HIGH    
    port.write('H');                                   
   } 
   
 
  else {                    	
 
    println(" - LED OFF");
    port.write('L');          // Send "L" over serial to set LED to LOW
}
 
  delay(1000);                // Set your desired interval here, in milliseconds
 }
