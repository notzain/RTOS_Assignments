#include <avr/io.h>
#include <util/delay.h>

#include "watchdog.h"
#include "led_hz.h"
#include "uart.h"
#include "servo.h"
#include "ping_sensor.h"

static uint8_t ask_hz(void) {
    switch (uart0_getch()) {
        case '1':
            return 1;
        case '2':
            return 2;
        case '3':
            return 10;
        default:
            return 1;
    }
}

static void wait(uint8_t n) {
    while (n--) {
        _delay_ms(100);
    }
}

static void wait_hz(uint8_t const hz) {
    uint16_t const delay_in_ms = 1000 / hz;
    wait(delay_in_ms / 100);
}

void on_reset(void)
{
    uart0_putstr("watchdog trigger");
}

int main() {
    led_hz_init();

    uart0_init();

    // watchdog_init();
    // watchdog_on_reset(on_reset);

//    uint8_t const hz = ask_hz();
//    uart0_putint(hz);
//    uart0_putln();


    servo_init();

    while (1) {
        uart0_putstr("test");
        servo_set(0);

        _delay_ms(1000);

        servo_set(1000);

        _delay_ms(1000);

        servo_set(2000);

        _delay_ms(1000);
    }
}
