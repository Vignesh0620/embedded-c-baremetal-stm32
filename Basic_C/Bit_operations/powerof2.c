//This Program is to find if a given integer is a power of 2

#include <stdio.h>
#include <stdbool.h>

bool is_power_of_2(int value) {
    int count=0;
    if (value <= 0) return false; // Negative numbers and zero are not powers of 2
    while(value)
    {
        count++;
        value = value <<  (value-1);      
    }// A power of 2 has only one bit set
    return count==1;
}

int main()
{
    int val;
    printf("Enter a number: "); 
    scanf("%d", &val);
    if (is_power_of_2(val)) {
        printf("The number %d is a power of 2.\n", val);
    } else {
        printf("The number %d is not a power of 2.\n", val);
    }
}

