#include<stdio.h>
int main()
{
    int a=476;
    int *p = &a;
    int **ptr=&p;
    //A Value and Address
    printf("Value of A : %d \n", a);
    printf("Address of A : %p \n",(void*) &a);
    //Pointer p
    printf("Value Stored in p : %p\n",(void*)p); // P stores adress of A
    printf("Address of P : %p\n",(void*)&p);    //Address of p 
    printf("Value p points to : %d\n",*p); //derefencing
    //Double Pointer ptr
    printf("Value Stored in ptr : %p\n",(void*)ptr); //Ptr stores address of p
    printf("Address of Ptr : %p\n",(void*)&ptr); //Address of ptr - Double Pointer
    printf("Value Ptr Points to : %p\n",(void*)*ptr);  //Value Stored at p, Address of A
    printf("Value Pointed by the value pointed by ptr : %d",**ptr); //Value of A

}



