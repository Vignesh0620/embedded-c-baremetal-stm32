#include<stdio.h>

void updateVal (int *ptr)
{
    //Add 10 to the value of the var at it's address
    ptr+=10;
}

int main()

{
    int val = 10;
    printf("Before Update : %d",val);
    updateVal(&val);
    printf("After Update: %d",val);
    return 0;
}