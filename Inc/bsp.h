#ifndef BSP_H
#define BSP_H

#include "usart.h"
#include "gpio.h"
#include "exti.h"
#include "rcc.h"
#include "timer.h"

void EXTI15_10_INIT(void);
void CLOCK_EN(void);
void init_bsp(void);

#endif

