#include <iostream>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include "GPIOClass.h"

using namespace std;

int main (void)
{
    string inputstate;
    GPIOClass* gpio17 = new GPIOClass("17"); //create new GPIO object to be attached to  GPIO17
    gpio17->export_gpio(); //export GPIO17
    cout << " GPIO pins exported" << endl;
    gpio17->setdir_gpio("out"); //GPIO4 set to output
    cout << " Set GPIO pin directions" << endl;
    
    while(1)
    {
        usleep(500000);  // wait for 0.5 seconds
    	gpio17->setval_gpio("1"); // turn LED ON
    	usleep(500000);  // wait for 0.5 seconds
    	gpio17->setval_gpio("0"); // turn LED ON
    }
    gpio17->unexport_gpio();
    cout << "Exiting....." << endl;
    return 0;
}