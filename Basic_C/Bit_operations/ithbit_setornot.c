#include<stdio.h>

int main()
{
    int val, bit_position;

    printf("Enter a number: ");
    scanf("%d", &val);
    printf("Enter the bit position to check (0-31): ");
    scanf("%d", &bit_position);

    if (bit_position < 0 || bit_position > 31) {
        printf("Invalid bit position. Please enter a value between 0 and 31.\n");
        return 1;
    }

    if (val & (1 << bit_position)) {
        printf("The bit at position %d in number %d is set.\n", bit_position, val);
    } else {
        printf("The bit at position %d in number %d is not set.\n", bit_position, val);
    }

    return 0;
}