#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


static unsigned int partition(int a[], unsigned int izq, unsigned int der) {
    
    unsigned int i = (izq + 1);
    unsigned int j = der;        
    unsigned int pivot = izq;
    
    
   while (i<=j){

          if(goes_before(a[i],a[pivot])){
              i++;}
          else if(goes_before(a[pivot],a[j])){
              j--;}
          else {//if (goes_before(a[i],a[pivot])&&goes_before(a[j],a[pivot])){
            swap(a,i,j);
             i++;
             j--;
}
}
 swap(a,pivot,j);
 pivot=j;

   
return (pivot);






/* Needs implementation */

    /* Permutes elements of a[izq..der] and returns pivot such that:
     - izq <= pivot <= der
     - elements in a[izq,pivot) all 'go_before' (according to function goes_before) a[pivot]
     - a[pivot] 'goes_before' all the elements in a(pivot,der]
    */
}

static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {
   unsigned int pivot;
 if(der > izq){
             pivot=partition(a,izq,der);
             quick_sort_rec(a,izq,(pivot == 0u) ? 0u : pivot - 1u);
             quick_sort_rec(a,pivot+1,der);





/* copiá acá la implementación que hiciste en el ejercicio 3 */

}
}
void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}

