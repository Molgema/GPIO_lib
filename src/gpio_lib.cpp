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

void pinConfigInput(uint16_t port, uint16_t bit, bool pullResistor, bool pullUP, bool IES, bool IE) {
    pullResistor? (*(&P1REN + port) |= bit) : (*(&P1REN + port) &= ~bit);

    pullUP? (*(&P1OUT + port) |= bit) : (*(&P1OUT + port) &= ~bit);

    IES? (*(&P1IES + port) |= bit) : (*(&P1IES + port) &= ~bit);

    IE? (*(&P1IE + port) |= bit) : (*(&P1IE + port) &= ~bit);
}

void pinClrFlag(uint16_t port, uint16_t bit, bool IFG) {
    IFG? (*(&P1IFG + port) |= bit) : (*(&P1IFG + port) &= ~bit);
}

void pinSelect(uint16_t port, uint16_t bit, uint16_t function, bool mode) {
    mode? (*(&P1DIR + port) |= bit) : (*(&P1DIR + port) &= ~bit);

    if (mode == 0b00) {
        *(&P1SEL1 + port) &= ~bit, *(&P1SEL0 + port) &= ~bit;
    }
    else if (mode == 0b01) {
        *(&P1SEL1 + port) &= ~bit, *(&P1SEL0 + port) |= bit;
    }
    else if (mode == 0b10) {
        *(&P1SEL1 + port) |= bit, *(&P1SEL0 + port) &= ~bit;
    }
    else if (mode == 0b11) {
        *(&P1SEL1 + port) |= bit, *(&P1SEL0 + port) |= bit;
    }
}
