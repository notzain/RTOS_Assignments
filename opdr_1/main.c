#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <avr/interrupt.h>

#include "watchdog.h"
#include "led_hz.h"
#include "uart.h"
#include "servo.h"
#include "ping_sensor.h"

static uint8_t ask_hz(void) {
    uart0_putstr("Enter hz: ");
    uart0_putln();

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
    uart0_putstr("Watchdog triggered, resetting device...");
    uart0_putln();
}

void routine_sensor(void)
{
    watchdog_reset();

    uint8_t const distance = ping_sensor_measure();

    uart0_putint(distance);
    uart0_putln();

    watchdog_reset();
}

void routine_servo(void)
{
    watchdog_reset();

    uart0_putstr("Enter servo degrees: ");
    char* c = uart0_getstr();
    uart0_putln();

    uint8_t const degrees = atoi(c);

    watchdog_reset();

    servo_set(degrees);

    watchdog_reset();
}

void (* const routines[]) (void) = {
        routine_sensor,
        routine_servo
};

enum ROUTINES {
    ROUTINE_SENSOR,
    ROUTINE_SERVO,
};

int main() {

    led_hz_init();

    servo_init();

    uart0_init();

    uart0_putstr("Starting device...");
    uart0_putln();

    watchdog_init();
    watchdog_on_reset(on_reset);

//    uint8_t const hz = ask_hz();

    while (1) {
        routines[ROUTINE_SERVO]();
        routines[ROUTINE_SENSOR]();
    }
}