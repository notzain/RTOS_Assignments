//
// Created by zain on 5/13/18.
//

#ifndef OPDR_1_WATCHDOG_H
#define OPDR_1_WATCHDOG_H

void watchdog_init(void);

void watchdog_reset(void);

typedef void (*wdt_on_reset)(void);
void watchdog_on_reset(wdt_on_reset reset);

#endif //OPDR_1_WATCHDOG_H
