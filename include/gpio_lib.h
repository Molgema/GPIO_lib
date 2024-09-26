/*
 * gpio_lib.h
 *
 *  Created on: 26 sep. 2024
 *      Author: niels
 */

#include <msp430.h>
#include <stdint.h>
#include <stdbool.h>

#ifndef INCLUDE_GPIO_LIB_H_
#define INCLUDE_GPIO_LIB_H_

#define P1                  (0x0000)
#define P2                  (0x0001)
#define P3                  (0x0020)
#define P4                  (0x0021)

#define INPUT               (0)
#define OUTPUT              (1)


void pinMode(uint16_t port, uint16_t bit, bool mode);
void pinSet(uint16_t port, uint16_t bit, bool val);
void pinToggle(uint16_t port, uint16_t bit);
bool pinGet(uint16_t port, uint16_t bit);
void pinConfigInput(uint16_t port, uint16_t bit, bool pullResistor, bool pullUP, bool IES, bool IE);
//void pinConfigOutput(uint16_t port, uint16_t bit, uint16_t val);
void pinConfigAnalog(uint16_t port, uint16_t bit);
void pinConfigTimer(uint16_t port, uint16_t bit);
void pinConfigCLK(uint16_t port, uint16_t bit);

#endif /* INCLUDE_GPIO_LIB_H_ */
