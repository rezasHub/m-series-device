
#include <TM1637Display.h>
const int CLK = 3; //Set the CLK pin connection to the display
const int DIO = 2; //Set the DIO pin connection to the display
const int volumeup = 4; // the number of the pushbutton pin
const int volumedown = 5; // the number of the pushbutton pin
int numCounter = 1;
int button = 1; // variable for reading the pushbutton status
int button2 = 1; // variable for reading the pushbutton status
TM1637Display display(CLK, DIO); //set up the 4-Digit Display.
void setup()
{
display.setBrightness(0x0a); //set the diplay to maximum brightness
pinMode(volumeup, INPUT);
digitalWrite(volumeup,HIGH);
pinMode(volumedown, INPUT);
digitalWrite(volumedown,HIGH);
}
void loop()
{
// read the state of the pushbutton value:
button = digitalRead(volumeup);
button2 = digitalRead(volumedown);
if ( button == LOW && numCounter < 1000 ) {
numCounter++;
display.showNumberDec(numCounter); //Display the numCounter value;
delay(200);
}
else if ( button2 == LOW && numCounter > 1 ) {
numCounter--;
display.showNumberDec(numCounter); //Display the numCounter value;
delay(200);
}
}