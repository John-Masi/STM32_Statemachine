
#include "../Inc/i2c.h"

typedef struct {
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t OAR1;
	volatile uint32_t OAR2;
	volatile uint32_t DR;
	volatile uint32_t SR1;
	volatile uint32_t SR2;
	volatile uint32_t CCR;
	volatile uint32_t TRISE;

} I2C_Typedef;

typedef void (*ClockEnable)(void);

struct I2CDevice {
	I2C_Typedef* Reg;
	ClockEnable clock_en;

};

static void enable_i2c(void) {}

static I2CDevice i2c_internal = {
		.Reg = I2C1_ADDR,
		.clock_en = enable_i2c,
};


I2CDevice* const MY_I2C = &i2c_internal;

I2CDevice* i2c_instance(void) {
	return &i2c_internal;
}

/* void i2c_poll(void) {
	I2C1->CR1 |= (1 << 8);
	while(!(I2C1->SR1 & (1 << 0))) {

	}

	(void)I2C1->SR1;
	I2C1->DR = (0x40 << 1);

	// Debugging purposes
	//if((I2C1->SR1 & (1 << 10))) {
	//	GPIOA->ODR |= (1 << 5);
	//}

	while(!(I2C1->SR1 & (1 << 1))) {

	}

	(void)I2C1->SR1;
	(void)I2C1->SR2;

	I2C1->DR = 0x40;

	while (!(I2C1->SR1 & (1 << 7))) {}

	I2C1->CR1 |= (1 << 9);
	return;
}

void i2c_read() {
	I2C1->CR1 |= (1 << 10);
	I2C1->CR1 |= (1 << 8);

	while(!(I2C1->SR1 & (1 << 0))) {

	}

	I2C1->DR = (0x40 << 1);

	while(!(I2C1->SR1 & (1 << 1))) {

	}

	(void)I2C1->SR1;
	(void)I2C1->SR2;

	I2C1->DR = 0x00;

	while (!(I2C1->SR1 & (1 << 7))) {}



	I2C1->CR1 |= (1 << 8);

	while(!(I2C1->SR1 & (1 << 0))) {}

	I2C1->DR = (0x40 << 1) | 1;

	while(!(I2C1->SR1 & (1 << 1))) {}

	 (void)I2C1->SR1;
	 (void)I2C1->SR2;

	 for(int i = 0; i < 5; i++) {
		 while (!(I2C1->SR1 & (1 << 6))) {}

		 data[i] = I2C1->DR;

	 }

	 I2C1->CR1 &= ~(1 << 10);
	 while (!(I2C1->SR1 & (1 << 6))) {}
	 data[5] = I2C1->DR;
	 I2C1->CR1 |= (1 << 9);
	 I2C1->CR1 |= (1 << 10);

} */


