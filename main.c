#include <stdint.h>

#define VIA_PORTB (*(volatile uint8_t*)0x6000)
#define VIA_PORTA (*(volatile uint8_t*)0x6001)
#define VIA_DDRB  (*(volatile uint8_t*)0x6002)
#define VIA_DDRA  (*(volatile uint8_t*)0x6003)

void main(void) {
    VIA_DDRB = 0xFF;
    VIA_PORTB = 0x55;
    while (1) {
        VIA_PORTB ^= 0xFF;  // toggle bits
        
    }
}
