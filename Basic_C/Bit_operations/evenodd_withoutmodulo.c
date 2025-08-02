#include<stdio.h>

int main()
{
    int vall;

    printf("Enter a number: ");
    scanf("%d", &vall);

    if (vall & 1) {
        printf("The number %d is odd.\n", vall);
    } else {
        printf("The number %d is even.\n", vall);
    }
}