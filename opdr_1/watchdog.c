//
// Created by zain on 5/13/18.
//

#include <avr/interrupt.h>
#include "uart.h"
#include "watchdog.h"

static wdt_on_reset on_reset = 0;

ISR(WDT_vect)
{
    if (on_reset != 0)
    {
        (*on_reset)();
    }
}


void watchdog_init(void)
{
    cli();

    MCUSR &= ~_BV(WDRF);

    WDTCSR |= (1<<WDCE) | (1<<WDE);

    // Interrupt, reset, 4s
    WDTCSR = 1<<WDIE | 1<<WDE | 1<<WDP3;


    sei();
}


void watchdog_on_reset(wdt_on_reset reset)
{
    on_reset = reset;
}
