#ifndef TIMER_H
#define TIMER_H

#include <stdint.h>

typedef struct TIMDevice TIMDevice;

extern TIMDevice* const TIM2;

void tim_init(void);
void start_tim(void);
void stop_tim(void);
void TIMIRQ(uint32_t cnt);

#endif
