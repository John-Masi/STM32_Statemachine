#include "../Include/gpio.hpp"

template <uintptr_t BASE,uint8_t PIN>
void GPIO<BASE,PIN>::pin_on(void) {
    gpio->ODR |= (1 << PIN);
}

template <uintptr_t BASE,uint8_t PIN>
void GPIO<BASE,PIN>::pin_off(void) {
    gpio->ODR &= ~(1 << PIN);
}

template <uintptr_t BASE,uint8_t PIN>
void GPIO<BASE,PIN>::open_drain(void) {
    gpio->OTYPER |= (1 << PIN);
}

template <uintptr_t BASE,uint8_t PIN>
void GPIO<BASE,PIN>::push_pull(void) {
    gpio->OTYPER &= ~(1 << PIN_POS);
}

template <uintptr_t BASE,uint8_t PIN>
void GPIO<BASE,PIN>::pullup_en(void) {
    gpio->PUPDR |= (0b01 << PIN_POS);
}

template <uintptr_t BASE,uint8_t PIN>
void GPIO<BASE,PIN>::pulldown_en(void) {
    gpio->PUPDR |= (0b10 << PIN_POS);
}

template <uintptr_t BASE,uint8_t PIN>
void GPIO<BASE,PIN>::alternate_func(void) {
    gpio->MODER &= ~(3 << PIN_POS);
    gpio->MODER |= (2 << PIN_POS);

    // Check if pin is in  AFRL index
    if(PIN <= 7) {
        gpio->AFRL &= ~(0xF << PIN_POS);
        gpio->AFRL |= (4 << PIN_POS);
    }
    else if (PIN > 7){
        gpio->AFRH &= ~(0xF << PIN_POS);
        gpio->AFRH |= (4 << ((PIN_POS - 8) * 2) );
    }
}

template <uintptr_t BASE,uint8_t PIN>
void GPIO<BASE,PIN>::set_output(void) {
    gpio->MODER |= (0b01 << PIN_POS);
}

