/*
This script tests the AnalogIn class by reading the analog values from a temperature sensor.
Command Line Arguments: None
Example invocation: ./test_analog
*/

#include "AnalogIn.h"
#include <iostream>

int main() {
    AnalogIn analog(0); // instantiate an AnalogIn object with number zero
    std::cout << "The number is: " << analog.getNumber() << std::endl; // call getNumber
    std::cout << "The ADC sample is: " << analog.readAdcSample() << std::endl; // call readAdcSample
    return 0;
}
