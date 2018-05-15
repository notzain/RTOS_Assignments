cmake_minimum_required(VERSION 3.0)

# Set the default MCU for this project
set(DEFAULT_AVR_MCU "atmega2560" CACHE STRING "")
# Set the default programmer for AVRDUDE
set(AVRDUDE_PROGRAMMER "wiring" CACHE STRING "")
# Set the default port to communicate with the programmer
set(AVRDUDE_PORT "/dev/ttyACM0" CACHE STRING "")
# Set the default port speed
set(AVRDUDE_BITRATE 9600 CACHE STRING "")

# Notify CMake that this project is build for the AVR architecture
set(CMAKE_TOOLCHAIN_FILE "../Generic-avr.cmake")

# Project definition
project(opdr_1
        VERSION 0.0.1
        LANGUAGES C
        )

## Declare the clock speed project-wide
add_definitions(-D F_CPU=16000000L)
add_definitions(-D BAUD=9600)

add_executable(opdr_1
        pin_config.h
        led_hz.h
        led_hz.c
        main.c
        uart.h uart.c ping_sensor.c ping_sensor.h watchdog.c watchdog.h servo.c servo.h)

target_compile_options(opdr_1 PRIVATE -std=gnu99 -Wall -Wpedantic -Os)

add_avr_firmware(opdr_1)
