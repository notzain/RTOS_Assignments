//
// Created by zain on 5/14/18.
//

#include <avr/io.h>
#include "pin_config.h"
#include "servo.h"

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

