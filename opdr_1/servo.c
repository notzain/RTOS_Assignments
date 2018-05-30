//
// Created by zain on 5/14/18.
//

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "pin_config.h"
#include "servo.h"

#define START_POS 1800

ISR(TIMER1_OVF_vect) {
    SERVO_PORT |= _BV(SERVO_PIN);
}

ISR(TIMER1_COMPA_vect) {
    SERVO_PORT &= ~_BV(SERVO_PIN);
}

void servo_init(void) {
    SERVO_DDR |= _BV(SERVO_PIN);

    cli();

    TCNT1 = 0;

    TCCR1A = 0;
    TCCR1B = 0;

    TCCR1A |= _BV(COM1A1) | _BV(WGM11);
    TCCR1B |= _BV(CS11) | _BV(WGM12) | _BV(WGM13);

    TIMSK1 |= _BV(OCIE0A) | _BV(TOIE1);

    ICR1 = 40000;

    OCR1A = START_POS;

    sei();
}

void servo_set(uint16_t const degrees) {
    OCR1A = START_POS + (degrees*15.5);
}

/*
void servo_init(void) {

    ICR1=20000;

    OCR1A=1000; //set 1ms pulse  1000=1ms  2000=2ms

    TCCR1A=(1<<COM1A1);//COM1A1 Clear OCnA when match counting up,Set on
    TCCR1B=(1<<WGM13)|(1<<CS11);// Phase and Freq correct ICR1=Top

   // TCCR1A |= _BV(WGM11);
   // TCCR1B |= _BV(WGM12) | _BV(WGM13);
   // TCCR1B |= _BV(CS10);

   // ICR1 = 20000;

   //  TCCR1A |= _BV(COM1A1);

    DDRB |= _BV(PB5);
}

void servo_set(uint16_t const degrees) {
    OCR1A = degrees;
}
 */
