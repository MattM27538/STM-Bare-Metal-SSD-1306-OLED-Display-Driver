#include "stm32f4xx.h"
#include "delay.h"
#include <stdint.h>
#include <stdbool.h>

void delayInMilliseconds(const int millisecondsToDelay){
	setSysTickTimerTo1MillisecondCountdown();

	resetSysTickTimerCounter();
	
	setSysTickClockSourceToInternal();
	
	beginSysTickTimerCountDown();
	
	executeDelay(millisecondsToDelay);

	disableSysTickTimerCountDown();	
}

void setSysTickTimerTo1MillisecondCountdown(){
	const uint32_t numberOfClockCyclesPerMillisecond = 16000 - 1;
	SysTick->LOAD = numberOfClockCyclesPerMillisecond;
}

void setSysTickClockSourceToInternal(){
	const uint32_t setClockSourceToInternal = (1U << 2);
	SysTick->CTRL |= setClockSourceToInternal;
}

void beginSysTickTimerCountDown(){
	const uint32_t enableSysTickTimer = (1U << 0);
	SysTick->CTRL |= enableSysTickTimer;
}

void executeDelay(const int millisecondsToDelay){
	for(int millisecondsPassed = 0; millisecondsPassed < millisecondsToDelay; ++millisecondsPassed){
		while(!(sysTickTimerCountdownCompleted())){
		}
	}
}

void resetSysTickTimerCounter(){
	SysTick->VAL = 0;
}

bool sysTickTimerCountdownCompleted(){
	return SysTick->CTRL & 0x10000;
}

void disableSysTickTimerCountDown(){
	SysTick->CTRL = 0;
}
