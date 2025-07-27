#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int *p = arr; // points to first element

    printf("Base Address of p : %p\n",(void*)p);

    for(int i=0;i<5;i++)
    {
        printf("Value of p+ %d is %d ,Address = %p\n", i,*(p+i),(void*)(p+i));

    }

    //Pointer Increment
    p=arr; //reset
     for (int i = 0; i < 5; i++) {
        printf("Value = %d, Address = %p\n", *p, (void*)p);
        p++; // move to next element
    }
}