#include <iostream>
#include <thread>
// A simple program that computes the square root of a number
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "cmake/TutorialConfig.h"
//#include "TutorialConfig.h"

int main (int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stdout,"%s Version %d.%d.%d\n",
                argv[0],
                Tutorial_VERSION_MAJOR,
                Tutorial_VERSION_MINOR,
                Tutorial_VERSION_PATCH);
        fprintf(stdout,"Usage: %s number\n",argv[0]);
        return 1;
    }
    double inputValue = atof(argv[1]);
    double outputValue = sqrt(inputValue);
    fprintf(stdout,"The square root of %g is %g\n",
            inputValue, outputValue);
    //
    std::cout << "Hello, World!" << std::endl;
    unsigned long const hardware_threads =
            std::thread::hardware_concurrency();
    std::cout << "hardware_threads：" <<hardware_threads;
    return 0;
}
