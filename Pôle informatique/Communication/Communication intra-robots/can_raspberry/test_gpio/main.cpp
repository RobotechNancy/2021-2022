#include <iostream>		// Include all needed libraries here
#include <wiringPi.h>

using namespace std;		// No need to keep using “std”

int main()
{
wiringPiSetup();			// Setup the library
pinMode(7, OUTPUT);		// Configure GPIO0 as an output
pinMode(21, INPUT);		// Configure GPIO1 as an input
pullUpDnControl (21, PUD_UP);

    // Main program loop
    while(1)
    {
            // Toggle the LED
           /* digitalWrite(7, 1);
            delay(1000); 	// Delay 500ms
            digitalWrite(7, 0);
            delay(1000);*/
	if(digitalRead(21) == 1){
		digitalWrite(7,1);
		cout << "ok" << endl;
	}else{
		digitalWrite(7,0);
	}
    }
	return 0;
}
