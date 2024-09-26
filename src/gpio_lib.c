#include <msp430.h>
#include <stdint.h>
#include <stdbool.h>

void pinMode(uint16_t port, uint16_t bit, bool mode) {
    mode? (*(&P1DIR + port) |= bit) : (*(&P1DIR + port) &= ~bit);
}

void pinSet(uint16_t port, uint16_t bit, bool val) {
    val? (*(&P1OUT + port) |= bit) : (*(&P1OUT + port) &= ~bit);
}

void pinToggle(uint16_t port, uint16_t bit) {
    *(&P1OUT + port) ^= bit;
}

bool pinGet(uint16_t port, uint16_t bit) {
    return *(&P1IN + port) & bit;
}

