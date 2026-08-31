#include <cstdint>
#include "gpio_typedef.hpp"

#ifndef GPIO_HPP
#define GPIO_HPP

// Defaults to Pin x Pos 0
template<uintptr_t BASE,uint8_t PIN = 0>
class GPIO {
    public:
        GPIO(uint8_t rcc_pos) {
            RCC->AHB1ENR |= (1 << rcc_pos);
        };
        void pin_on(void);
        void pin_off(void);
        void open_drain(void);
        void push_pull(void);
        void pullup_en(void);
        void pulldown_en(void);
        void alternate_func(void);
        void set_output(void);


    private:
        const uint8_t PIN_POS{PIN * 2};
        inline static auto gpio = reinterpret_cast<GPIO_Typedef*>(BASE);
};

#endif 