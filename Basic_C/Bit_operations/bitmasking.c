#include<stdio.h>

int main()
{

    unsigned char num = 0xAB; // BINARY: 10101011

    unsigned char lower_nibbble = num & 0x0F; // Mask to get lower nibble (00001011)
    unsigned char upper_nibbble = (num & 0xF0) >> 4; // Mask to get upper nibble (00001010)

    printf("Lower nibble: 0x%02X\n", lower_nibbble); // Expected: 0x0B
    printf("Upper nibble: 0x%02X\n", upper_nibbble); // Expected: 0x0A  
    return 0;
}