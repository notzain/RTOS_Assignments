//
// Created by zain on 5/11/18.
//

#ifndef OPDR_1_UART0_H
#define OPDR_1_UART0_H

void uart0_init(void);
void uart0_putch(char const c);
void uart0_putstr(char const * str);
void uart0_putint(uint8_t const num);
void uart0_putln(void);
char uart0_getch(void);
char* uart0_getstr(void);

#endif //OPDR_1_UART0_H
