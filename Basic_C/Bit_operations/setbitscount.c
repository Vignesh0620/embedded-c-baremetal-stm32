//This Program Counts the number of bits set in a given integer

#include <stdio.h>

int main()
{
    int val;
    scanf("%d", &val);

    int count = setbits_count(val);
    printf("The number of bits set in %d is: %d\n", val, count);
}

int setbits_count(int val)
{
    int count = 0;
    while (val > 0) {
        if (val & 1) {
            count++;
        }
        val >>= 1; // Right shift to check the next bit   
    }
    return count;
}