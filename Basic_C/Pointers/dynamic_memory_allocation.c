#include<stdio.h>
#include<stdlib.h>
int main()

{
    int *ptr1, *ptr2, *ptr3;
    int i, n=5;

    //malloc , allocates memory but do not initialize
    ptr1=(int*)malloc(n* sizeof(int));
    
    //initialization
    for(i=0;i<n;i++){
        ptr1[i]=i+1;
    }

    //Values in malloc
     printf("Values in ptr1 (malloc): ");
    for (i = 0; i < n; i++) {
        printf("%d ", ptr1[i]);
    }
    printf("\n");
    
    //calloc - allocates and initializes to 0

    ptr2 = (int*)calloc(n*sizeof(int));
    if(ptr2 == NULL)
    [
        printf("Calloc failed \n");
        return 1;
    ]

    //prints all 0s after calloc
    for(i=0; i<n; i++)
    {
        printf("%d ", ptr2[i]);
    }
    printf("\n");

    //relloac - re allocating malloced memory
    ptr3 =(int*)realloc(ptr1, 2*n*sizeof(int));

    if(ptr3==NULL)
    {
        printf("realloc failed\n");
        free(ptr1);  // ptr1 should be freed after reallocating
        return 1; 
    }   

        // Assign more values to new extended memory
    for (i = n; i < 2 * n; i++) {
        ptr3[i] = i + 1;
    }

    printf("Values in ptr3 (after realloc): ");
    for (i = 0; i < 2 * n; i++) {
        printf("%d ", ptr3[i]);
    }
    printf("\n");

    // Clean up
    free(ptr2);
    free(ptr3);

    return 0;
}
