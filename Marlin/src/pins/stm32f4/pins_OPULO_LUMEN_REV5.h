/**
 * STM32F407VET6 on Opulo Lumen PnP REV5.
 * https://opulo.io/
 */
#pragma once

#define ALLOW_STM32DUINO
#include "env_validate.h"

#define BOARD_INFO_NAME      "LumenPnP Motherboard REV05"
#define DEFAULT_MACHINE_NAME "LumenPnP"

#define SRAM_EEPROM_EMULATION
#define MARLIN_EEPROM_SIZE 0x2000

// Limit switches
#define X_STOP_PIN PC6
#define Y_STOP_PIN PD15
#define Z_STOP_PIN PD14

// TMC2209 diagnostic pins
#define X_DIAG_PIN PB10
#define Y_DIAG_PIN PB11
#define Y2_DIAG_PIN PC12
#define Z_DIAG_PIN PB5
#define I_DIAG_PIN PC10
#define J_DIAG_PIN PC11

// Steppers
#define X_STEP_PIN PB15
#define X_DIR_PIN PB14
#define X_ENABLE_PIN PD9
#define Y_STEP_PIN PE15
#define Y_DIR_PIN PE14
#define Y_ENABLE_PIN PB13
#define Y2_STEP_PIN PD6
#define Y2_DIR_PIN PD7
#define Y2_ENABLE_PIN PA3
#define Z_STEP_PIN PE7
#define Z_DIR_PIN PB1
#define Z_ENABLE_PIN PE9
#define I_STEP_PIN PC4
#define I_DIR_PIN PA4
#define I_ENABLE_PIN PB0
#define J_STEP_PIN PE11
#define J_DIR_PIN PE10
#define J_ENABLE_PIN PE13

// TMC2209 software UART
#define X_SERIAL_TX_PIN PD8
#define X_SERIAL_RX_PIN X_SERIAL_TX_PIN
#define Y_SERIAL_TX_PIN PB12
#define Y_SERIAL_RX_PIN Y_SERIAL_TX_PIN
#define Y2_SERIAL_TX_PIN PA2
#define Y2_SERIAL_RX_PIN Y2_SERIAL_TX_PIN
#define Z_SERIAL_TX_PIN PE8
#define Z_SERIAL_RX_PIN Z_SERIAL_TX_PIN
#define I_SERIAL_TX_PIN PC5
#define I_SERIAL_RX_PIN I_SERIAL_TX_PIN
#define J_SERIAL_TX_PIN PE12
#define J_SERIAL_RX_PIN J_SERIAL_TX_PIN
#define TMC_BAUD_RATE 19200

// Fans and buzzer
#define FAN0_PIN PB8
#define FAN1_PIN PB9
#define FAN2_PIN PE5
#define FAN3_PIN PE6
#define BEEPER_PIN PA7

// NeoPixel strips
#define NEOPIXEL_PIN PC7
#define NEOPIXEL2_PIN PC8

// Hardware SPI pins used by optional peripherals
#define MISO_PIN PB4
#define MOSI_PIN PB5
#define SCK_PIN PB3
#define TMC_SPI_MISO MISO_PIN
#define TMC_SPI_MOSI MOSI_PIN
#define TMC_SPI_SCK SCK_PIN

// I2C
#define I2C_SDA_PIN PB7
#define I2C_SCL_PIN PB6

// REV5 auxiliary header
#define LUMEN_AUX_PWM1 PA5
#define LUMEN_AUX_PWM2 PA6
#define LUMEN_AUX_PWM3 PA15
#define LUMEN_AUX_A1 PC0

#define RS485_TX_ENABLE_PIN PD11
#define RS485_RX_ENABLE_PIN PD12
