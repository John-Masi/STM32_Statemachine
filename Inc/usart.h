#ifndef USART_H
#define USART_H

typedef struct USARTDevice USARTDevice;

extern USARTDevice* const USART2;

char get_char(void);
void send_char(char c);
void send_str(char*  buffer);
void USART2_INIT(void);

#endif
