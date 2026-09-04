#ifndef RCC_H
#define RCC_H

#include <stdint.h>

typedef struct {
	 volatile uint32_t CR;
	 volatile uint32_t PLLCFGR;
	 volatile uint32_t CFGR;
	 volatile uint32_t reserved0[9];
	 volatile uint32_t AHB1ENR;
	 volatile uint32_t AHB2ENR;
	 volatile uint32_t AHB3ENR;
	 volatile uint32_t reserved1;
	 volatile uint32_t APB1ENR;
	 volatile uint32_t APB2ENR;
} RCC_Typedef;

#define RCC ((RCC_Typedef*)0X40023800)

#endif
