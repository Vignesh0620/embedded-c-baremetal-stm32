#include <stdio.h>

// Function to convert decimal to binary
void printBinary(int num) {
    printf("Binary of %d: ", num);
    for (int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;
        printf("%d", bit);
    }
    printf("\n");
}

// Count number of 1s in binary (Hamming Weight)
int countOnes(int num) {
    int count = 0;
    while (num) {
        if (num & 1)
            count++;
        num >>= 1;
    }
    return count;
}

// Check parity: Even or Odd
void checkParity(int num) {
    int ones = countOnes(num);
    if (ones % 2 == 0)
        printf("Even parity\n");
    else
        printf("Odd parity\n");
}

int main() {
    int number = 29; 

    printBinary(number);
    int ones = countOnes(number);
    printf("Number of 1s: %d\n", ones);
    checkParity(number);

    return 0;
}
