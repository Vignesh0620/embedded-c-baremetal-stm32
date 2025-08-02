#include <stdio.h>

// Function to check if a number is a power of 4
int isPowerOfFour(unsigned int n) {
    // A number 'n' is a power of 4 if:
    // 1. It is a power of 2 (n > 0 and (n & (n - 1)) == 0)
    // 2. The only set bit is at an even position (0-indexed from right)
    //    This can be checked by ensuring that n & 0xAAAAAAAA is 0.
    //    0xAAAAAAAA in binary is 10101010101010101010101010101010.
    //    If a number is a power of 4, its only set bit will be at an even position.
    //    Masking with 0xAAAAAAAA checks if any odd-positioned bit is set.

    return (n > 0) && ((n & (n - 1)) == 0) && ((n & 0xAAAAAAAA) == 0);
}

int main() {
    unsigned int num;

    printf("Enter an integer: ");
    scanf("%u", &num);

    if (isPowerOfFour(num)) {
        printf("%u is a power of 4.\n", num);
    } else {
        printf("%u is not a power of 4.\n", num);
    }

    return 0;
}