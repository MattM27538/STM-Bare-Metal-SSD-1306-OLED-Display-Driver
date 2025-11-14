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

void i2c_writeByte(const uint8_t targetAddress, const uint8_t controllerAddress, const char data);
bool i2cBusIsBusy();
void startI2CBus();
bool startCommandAcknowledged();
void setI2CTargetAddressAndWritebit(uint8_t targetAddress);
bool targetAddressAcknowledged();
void clearAddressFlag();
bool dataRegisterIsNotEmpty();
void setI2CControllerAddress(const uint8_t controllerAddress);
void insertDataIntoDataRegister(const char data);
bool dataTransferCompleted();
void stopI2CBus();

#endif