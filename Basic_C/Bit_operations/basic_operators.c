#include<stdio.h>
#include<stdint.h>

int main()
{
    uint8_t a = 0x55; // 01010101
    uint8_t b = 0xAA; // 10101010

    uint8_t and, or, xor, not, left_shift, right_shift;

    and = a && b;
    printf("AND operation: %02X\n", and); // Should print 00

    or = a || b;
    printf("OR operation: %02X\n", or); // Should print 01

    xor = a ^ b;
    printf("XOR operation: %02X\n", xor); // Should print FF 

    not = ~a;
    printf("NOT operation: %02X\n", not); // Should print AA

    left_shift = a << 1;
    printf("Left Shift operation: %02X\n", left_shift); // Should print AA

    right_shift = b >> 1;
    printf("Right Shift operation: %02X\n", right_shift); // Should print 55
}