#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


static void insert(int a[], unsigned int i) {
    
    unsigned int j = i;
  while(j>0 && goes_before(a[j],a[j-1])){
      swap(a,j,j-1); 
      j--;   // Intercambia elementos de la matriz 'a' en                 las              posiciones dadas 'i' y 'j'
                       //La matriz permanece igual si las dos                       posiciones son iguales
     


}  
           /* needs implementation */
}

void insertion_sort(int a[], unsigned int length) {
    
	
	for (unsigned int i = 1u; i < length; ++i) {
       insert(a,i);
        assert (array_is_sorted( a,i));
     }



                                     /* needs implementation */
    
    
}

