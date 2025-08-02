#include<stdio.h>


int main() {
    unsigned char num = 0x05;  // binary: 00000101

    // Toggle bit 1
    num ^= (1 << 1);  // Flip bit 1
    printf("After toggling bit 1: 0x%02X\n", num);  // Expected: 0x07

    // Read bit 2
    int bit = (num >> 2) & 1;
    printf("Value of bit 2: %d\n", bit);  // Expected: 1

    return 0;
}

