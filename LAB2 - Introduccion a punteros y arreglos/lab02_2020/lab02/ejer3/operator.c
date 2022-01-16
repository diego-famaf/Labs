#include<stdio.h>
#include<stdlib.h>

int main()
{

    int x = 20;
    int *p = NULL;
    
    p = p; // just nonsense to make the compiler happy, remove it.
    
    /* PLEASE COMPLETE */

    printf("x = %d\n", x);

    return (EXIT_SUCCESS);
}
