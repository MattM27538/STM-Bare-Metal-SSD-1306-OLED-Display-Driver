#include <stdbool.h>

#ifndef delay_h
#define delay_h

void delayInMilliseconds(const int millisecondsToDelay);
void setSysTickTimerTo1MillisecondCountdown();
void setSysTickClockSourceToInternal();
void beginSysTickTimerCountDown();
void executeDelay(const int millisecondsToDelay);
void resetSysTickTimerCounter();
bool sysTickTimerCountdownCompleted();
void disableSysTickTimerCountDown();

#endif

