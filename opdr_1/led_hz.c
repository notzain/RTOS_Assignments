//
// Created by zain on 5/11/18.
//

#include "led_hz.h"
#include "pin_config.h"

void led_hz_init(void) {
    LED_HZ_DDR |= _BV(LED_HZ_PIN);
}

void led_hz_on(void) {
    LED_HZ_PORT |= _BV(LED_HZ_PIN);
}

void led_hz_off(void) {
    LED_HZ_PORT &= ~_BV(LED_HZ_PIN);
}

void led_hz_toggle(void) {
    LED_HZ_PORT ^= _BV(LED_HZ_PIN);
}
