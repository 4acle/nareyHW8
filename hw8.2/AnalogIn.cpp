#include "AnalogIn.h"
#include <sstream>
#include <fstream>
#include <iostream>

#define ADC_PATH "/sys/bus/iio/devices/iio:device0/in_voltage"

AnalogIn::AnalogIn() : number(0) {}

AnalogIn::AnalogIn(unsigned int n) : number(n) {}

void AnalogIn::setNumber(unsigned int n) {
    number = n;
}

int AnalogIn::readAdcSample() {
    std::stringstream ss;
    ss << ADC_PATH << number << "_raw";
    std::fstream fs;
    fs.open(ss.str().c_str(), std::fstream::in);
    fs >> number;
    fs.close();
    return number;
}

AnalogIn::~AnalogIn() {}
