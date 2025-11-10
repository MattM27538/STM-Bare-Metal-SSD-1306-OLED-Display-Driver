#include "stm32f4xx.h"
#include <stdint.h>
#include <stdbool.h>

#ifndef i2c_h
#define i2c_h

void i2cInit();
void setPB9andPB9ToAltFunctionI2C();
void setPB8AndPB9AsOpenDrain();
void softwareResetI2C();
void setI2CClockFrequency(const uint32_t i2cClockFrequencyMHz);
void setI2CMode(const uint32_t fastMode);
void setI2CModeDutyCycle(const uint32_t dutyCycle16Low9High);
void setI2CClockSpeed(const uint32_t clockSpeed);
void setI2CSignalMaximumRiseTime(const uint32_t maximumRiseTime);
void enableI2C();

#endif