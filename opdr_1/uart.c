//
// Created by zain on 5/11/18.
//

#ifndef BAUD
#define BAUD 9600
#warning "BAUD not defined, default 9600"
#endif

#include <avr/io.h>
#include <util/setbaud.h>
#include <stdlib.h>
#include <string.h>

#include "uart.h"

void uart0_init(void) {
    UBRR0H = UBRRH_VALUE;
    UBRR0L = UBRRL_VALUE;

    UCSR0B |= _BV(RXEN0) | _BV(TXEN0);
    UCSR0C |= _BV(UCSZ00) | _BV(UCSZ01);
}

void uart0_putch(char const c) {
    loop_until_bit_is_set(UCSR0A, UDRE0);
    UDR0 = c;
}

void uart0_putstr(char const *str) {
    while (*str) {
        uart0_putch(*str);
        (*str++);
    }
}

void uart0_putln(void) {
    uart0_putstr("\r\n");
}

void uart0_putint(uint8_t const num) {
    static char buffer[16];
    itoa(num, buffer, 10);
    uart0_putstr(buffer);
}

char uart0_getch(void) {
    loop_until_bit_is_set(UCSR0A, RXC0);
    return UDR0;
}

char *uart0_getstr(void) {
    static char buffer[32];

    uint8_t idx = 0;
    for (;;) {
        char received = uart0_getch();

        uart0_putch(received);

        if (received == '\n') {
            break;
        }

        buffer[idx++] = received;
    }

    buffer[idx] = '\0';

    return &buffer[0];
}

