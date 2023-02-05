#include "../main.hpp"
#include <gtest/gtest.h>


TEST(Test_Stabilizer, testTemperature)
{   
    srand(time(NULL));                                                                                                    //  Initialize the seed of random in each run of the code to get a different random result by time
    for(int j=0; j<8; j++)
        {
        currentTemperature = getTemperature();                                                                            //  Get temperature value from sensors (getting random value for test)
        std::cout << "[----------] ______________________________________" << std::endl;
        std::cout << "[----------] Value of current temperature is (" << currentTemperature <<") Celcius"<< std::endl;    //  Print current temperature to terminal
    
        setTemperature();                                                                                                 //  Set cooler and heater for changing temperature to acceptable range

        if(abs(currentTemperature - defaultTemperature) < acceptableRange)                                                //  If it is of acceptable value, we expect it to do nothing
        { 
            std::cout << "[----------] Cooler status must be OFF" << std::endl;                                           // Expected situation of Cooler
            std::cout << "[----------] Heater status must be OFF" << std::endl;                                           // Expected situation of Heater
            EXPECT_EQ(coolerStatus,OFF);                                                                                  // Testing Cooler Status
            EXPECT_EQ(heaterStatus,OFF);                                                                                  // Testing Heater Status
        }

        else if(currentTemperature < defaultTemperature)                                                                  // If the room is cold
        {
            std::cout << "[----------] Cooler status must be OFF" << std::endl;                                           // Expected situation of Cooler
            std::cout << "[----------] Heater status must be ON" << std::endl;                                            // Expected situation of Heater
            EXPECT_EQ(coolerStatus,OFF);                                                                                  // Testing Cooler Status
            EXPECT_EQ(heaterStatus,ON);                                                                                   // Testing Heater Status
        }

        else if(currentTemperature > defaultTemperature)                                                                  // If the room is warm
        {
            std::cout << "[----------] Cooler status must be ON" << std::endl;                                            // Expected situation of Cooler
            std::cout << "[----------] Heater status must be OFF" << std::endl;                                           // Expected situation of Heater
            EXPECT_EQ(coolerStatus,ON);                                                                                   // Testing Cooler Status
            EXPECT_EQ(heaterStatus,OFF);                                                                                  // Testing Heater Status
        }

        else                                                                                                              // If the room temperature is as it's supposed to be
        {
            std::cout << "[----------] Cooler status must be OFF" << std::endl;                                           // Expected situation of Cooler
            std::cout << "[----------] Heater status must be OFF" << std::endl;                                           // Expected situation of Heater
            EXPECT_EQ(coolerStatus,OFF);                                                                                  // Testing Cooler Status
            EXPECT_EQ(heaterStatus,OFF);                                                                                  // Testing Heater Status
        } 
            std::cout << "[----------] ______________________________________" << std::endl;
    }


}