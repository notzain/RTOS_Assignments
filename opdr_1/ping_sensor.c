//
// Created by zain on 5/11/18.
//

#include <util/delay.h>

#include "ping_sensor.h"
#include "pin_config.h"

uint8_t ping_sensor_measure(void) {
    SENSOR_TRIG_DDR |= _BV(SENSOR_TRIG_PIN);

    //low pulse on trigger
    SENSOR_TRIG_PORT &= ~_BV(SENSOR_TRIG_PIN);
    _delay_us(5);

    //high pulse on trigger
    SENSOR_TRIG_PORT |= _BV(SENSOR_TRIG_PIN);
    _delay_us(10);

    //low pulse on trigger
    SENSOR_TRIG_PORT &= ~_BV(SENSOR_TRIG_PIN);

    SENSOR_ECHO_DDR &= ~_BV(SENSOR_ECHO_PIN);

    TCNT3 = 0;

    loop_until_bit_is_set(SENSOR_ECHO_PIN_REG, SENSOR_ECHO_PIN);
    //while (~SENSOR_ECHO_PIN_REG & _BV(SENSOR_ECHO_PIN));

    //while (SENSOR_ECHO_PIN_REG & _BV(SENSOR_ECHO_PIN)) {
    while (bit_is_set(SENSOR_ECHO_PIN_REG, SENSOR_ECHO_PIN)) {
        TCCR3B = _BV(CS31);
    }

    TCCR3B = 0;

    return (TCNT3 / 116);
}
