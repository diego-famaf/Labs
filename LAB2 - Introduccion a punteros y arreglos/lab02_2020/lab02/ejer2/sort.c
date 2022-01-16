#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "helpers.h"
#include "sort.h"

static bool goes_before(player_t x, player_t y) {
    x = x; y = y;        // just nonsense to make the compiler happy
    return true;       // replace for something sensible
}

bool array_is_sorted(player_t atp[], unsigned int length) {
    unsigned int i = 1;
    while (i < length && goes_before(atp[i - 1], atp[i])) {
        i++;
    }
    return (i == length);
}

void sort(player_t a[], unsigned int length) {
    if (0 < length) {    // just nonsense to make the compiler happy 
        a[0] = a[0];     // replace with a call to your favorite sorting algorithm
    }                    // using the goes_before relation
}

