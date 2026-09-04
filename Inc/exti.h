#ifndef EXTI_H
#define EXTI_H

#include <stdint.h>

typedef struct {
	volatile uint32_t r[5];
	volatile uint32_t EXTICR4;
} SYSCFG_Typedef;
#define SYSCFG ((SYSCFG_Typedef *)0x40013800)
#define SYSCFGEN 14

typedef struct {
	volatile uint32_t IMR;
	volatile uint32_t r[2];
	volatile uint32_t FSTR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;
} EXTI_Typedef;
#define EXTI ((EXTI_Typedef *)0x40013C00)


typedef struct {
	volatile uint32_t ISER0[7];
} NVIC_Typedef;

#define NVIC ((NVIC_Typedef*)0xE000E100)

#endif
