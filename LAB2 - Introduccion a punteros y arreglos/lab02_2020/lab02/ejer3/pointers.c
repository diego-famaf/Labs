#include <stdio.h>
#include <stdlib.h>

typedef struct _person {
    int age;
    char name_initial;
} person_t;


int main(void) {

    int x = 1;
    person_t m = {90, 'M'};
    int a[] = {0, 1, 2, 3};


    /*
      PLEASE COMPLETE
      Do not use variables 'x', 'm' or 'a' on the left hand side of an assignment.
     */

    printf("x = %d\n", x);
    printf("m = (%d, %c)\n", m.age, m.name_initial);
    printf("a[1] = %d\n", a[1]);

    return (EXIT_SUCCESS);
}
