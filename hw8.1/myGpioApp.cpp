//This script is used for manipulating the GPIO pins of a device.
//It takes no command line arguments.
// Example invocation: /myGpioApp

#include "myGpio.h"
#include <unistd.h>

int main() {
    // a. Instantiate an object as an output gpio using pin p9.12.
    MYGPIO outputGpio(9);

    // b. Instantiate an object as an input gpio using pin p8.16.
    MYGPIO inputGpio(8);

    // c. Set p9.12 high for 3 seconds, and then set it low. Print out its value in both cases.
    outputGpio.setDirection(OUTPUT);
    outputGpio.setValue(HIGH);
    cout << "Output GPIO value: " << outputGpio.getValue() << endl;

	// Sleep for 3 seconds.
	usleep(3000000);

    outputGpio.setValue(LOW);
    cout << "Output GPIO value: " << outputGpio.getValue() << endl;

    // d. Read p8.16 and print out its value.
    inputGpio.setDirection(INPUT);
    cout << "Input GPIO value: " << inputGpio.getValue() << endl;

    return 0;
}

