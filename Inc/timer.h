#ifndef TIMER_H
#define TIMER_H

#include <stdint.h>

typedef struct TIMDevice TIMDevice;

extern TIMDevice* const TIM2;

void tim_init(void);
void start_tim(void);
void stop_tim(void);
void TIM2IRQ(void);
uint32_t get_count(void);
void update_count(uint32_t val);

#endif
