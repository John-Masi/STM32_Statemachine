#ifndef I2C_H
#define I2C_H

#include <stdint.h>

typedef struct I2CDevice I2CDevice;

extern I2CDevice* const I2C1;

void i2c_init(void);
void i2c_poll(void);
void i2c_read(void);
void tempCalc(uint16_t temp);
void humidCalc(uint16_t humid);
I2CDevice* get_instance(void);

#define I2C1_EN 0
#define I2C1_ADDR 0x0

#endif
