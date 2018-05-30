//
// Created by zain on 5/13/18.
//

#ifndef OPDR_1_WATCHDOG_H
#define OPDR_1_WATCHDOG_H

#include <avr/wdt.h>

#define watchdog_reset() wdt_reset()

void watchdog_init(void);


typedef void (*wdt_on_reset)(void);
void watchdog_on_reset(wdt_on_reset reset);

#endif //OPDR_1_WATCHDOG_H
