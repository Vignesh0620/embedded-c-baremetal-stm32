#include<stdio.h>

int main()
{
    unsigned char num = 0x0A; //BINARY: 00001011

    //set bit 2 to 1

    num = num | (1<<2);  //bit mask : 00000100 and setting the bit  

    printf("After setting bit 2: %02X\n", num); // Expected: 0x0E (BINARY: 00001110)

    //Clear bit 3 

    num = num | ~(1<<3) //` bit mask: 11110111 and clearing the bit
    printf("After clearing bit 3: %02X\n", num); // Expected: 0x0A (BINARY: 00001010)
}