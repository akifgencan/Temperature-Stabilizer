#include "main.hpp" 
#include <cstdlib>       /* rand */
#include <time.h>        /* srand time */ 
#include <iostream>      /* cin/cout */
#include <stdlib.h>      /* abs */

int currentTemperature;

bool coolerStatus = OFF;
bool heaterStatus = OFF;

int getTemperature()                                                             // Get temperature value from sensors (getting random value for test)
{
  //srand(time(NULL));
  const signed int tempRange = 101;                                              // Range of randomly generated temperature for room
  return  (rand() %tempRange) -50;                                               // Convert random value from -50 to +50 degree celcius
  
}

void setTemperature(void)
{

      if(abs(currentTemperature - defaultTemperature) < acceptableRange)         // If it is of acceptable value, do nothing
      {
        coolerStatus = OFF;                                                      // Deactivate the cooler
        heaterStatus = OFF;                                                      // Deactivate the heater
      }


      else if(currentTemperature < defaultTemperature)                           // If the room is cold
      {
        coolerStatus = OFF;                                                      // Deactivate the cooler
        heaterStatus = ON;                                                       // Activate the heater
      }


      else if (currentTemperature > defaultTemperature)                          // If the room is warm
      {
        coolerStatus = ON;                                                       // Activate the cooler
        heaterStatus = OFF;                                                      // Deactivate the heater
      }


      else                                                                       // If the room temperature is as it's supposed to be
      {
        coolerStatus = OFF;                                                      // Deactivate the cooler
        heaterStatus = OFF;                                                      // Deactivate the heater
      }

}
