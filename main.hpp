#ifndef MAIN_HPP
#define MAIN_HPP

#define OFF false
#define ON  true

#define defaultTemperature  22                     // Default room temperature (celcius)
#define acceptableRange     5

extern bool coolerStatus;
extern bool heaterStatus;
extern int currentTemperature;
void setTemperature(void);
int getTemperature();

#endif /* MAIN_HPP */