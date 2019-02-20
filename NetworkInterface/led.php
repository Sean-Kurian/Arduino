
<?php

// The following code creates an address called onoffdata and 
// populates the address with the state from HTML webpage
$onoffdata = $_GET["state"]; 	


// The following code creates an address called textfile and populates 
// the address with the filename	
$textfile = "LED_data.txt"; 
		
// The following code creates an address called fileLocation and 
// populates the address with the the contents of textfile
// In C language, this is basically a "pointer" that points to 
// another address for data 

$fileLocation = "$textfile";		
											
// The following code line creates an address called fh and populates 
// address with the LED_data text file
// If the file won't open, an error will appear on the screen
// The codeline also causes the Adruino interpreter to open the .txt file 
// for writing and overwrites the previous content
$fh = fopen($fileLocation, 'w   ') or die("Error opening file!"); 


// The following code creates an address called stringToWrite and 
// populates address with the contents of onoffdata
// In C language, this is basically a "pointer" that points to another 
// address for data

$stringToWrite = "$onoffdata"; 	

// The following code writes the contents of address stringToWrite (onoffdata) 
// to address fh pointing to LED_data.txt)

fwrite($fh, $stringToWrite); 

// The following code line closes the file once all data is transferred	
fclose($fh);							
 
// The following code returns to the website program (index.html)
header("Location: index.html"); 	
?>
