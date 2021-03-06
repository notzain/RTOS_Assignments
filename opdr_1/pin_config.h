//
// Created by zain on 5/11/18.
//

#ifndef OPDR_1_PIN_CONFIG_H
#define OPDR_1_PIN_CONFIG_H

#include <avr/io.h>

#define LED_HZ_DDR DDRB
#define LED_HZ_PORT PORTB
#define LED_HZ_PIN PB7

#define SERVO_DDR DDRA
#define SERVO_PORT PORTA
#define SERVO_PIN PA7

#define SENSOR_TRIG_DDR DDRB
#define SENSOR_TRIG_PORT PORTB
#define SENSOR_TRIG_PIN_REG PINB
#define SENSOR_TRIG_PIN PB0

#define SENSOR_ECHO_DDR DDRB
#define SENSOR_ECHO_PORT PORTB
#define SENSOR_ECHO_PIN_REG PINB
#define SENSOR_ECHO_PIN PB1

#endif //OPDR_1_PIN_CONFIG_H
