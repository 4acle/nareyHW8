#include "myGpio.h"
#include <fstream>
#include <string>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

MYGPIO::MYGPIO(int number)
{
    this->number = number;
    this->path = "/sys/class/gpio/gpio" + to_string(number) + "/";
}

int MYGPIO::write(string path, string filename, string value)
{
    ofstream fs;
    fs.open((path + filename).c_str());
    if (!fs.is_open())
        return -1;
    fs << value;
    fs.close();
    return 0;
}

int MYGPIO::write(string path, string filename, int value)
{
    return write(path, filename, to_string(value));
}

string MYGPIO::read(string path, string filename)
{
    ifstream fs;
    fs.open((path + filename).c_str());
    string input;
    getline(fs, input);
    fs.close();
    return input;
}

void MYGPIO::setDirection(GPIO_DIRECTION dir)
{
    write(this->path, "direction", dir == INPUT ? "in" : "out");
}

GPIO_DIRECTION MYGPIO::getDirection()
{
    string dir = read(this->path, "direction");
    return dir == "in" ? INPUT : OUTPUT;
}

int MYGPIO::setValue(GPIO_VALUE val)
{
    return write(this->path, "value", val == HIGH ? "1" : "0");
}

GPIO_VALUE MYGPIO::getValue()
{
    string val = read(this->path, "value");
    return val == "1" ? HIGH : LOW;
}

void MYGPIO::toggleOutput()
{
    GPIO_VALUE val = getValue();
    setValue(val == HIGH ? LOW : HIGH);
}

MYGPIO::~MYGPIO()
{
}
