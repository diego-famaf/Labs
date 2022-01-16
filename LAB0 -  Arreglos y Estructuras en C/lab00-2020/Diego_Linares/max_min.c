#include "assert.h"
#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"

#define ARRAY_SIZE 4

struct max_min_result {
    int max_value;
    int min_value;
    unsigned int max_position;
    unsigned int min_position;
}result[1];

struct max_min_result compute_max_min(int array[], unsigned int length)
{
    assert(length > 0);
    array = array;
    struct max_min_result result = { 0,0,0,0 };
   
    unsigned int i; //IMPLEMENTACION INICIA AQUI
    
    result.max_value = array[0];
    result.min_value = array[0];
    result.max_position = 0;
    result.min_position  = 0;
    
  
     for(i=0;i<length;i++){
   	
   	 if(array[i]>result.max_value){               
       	      result.max_value = array[i];           
       	      result.max_position = i;      
       	      
		}
		
		if (array[i]<result.min_value){ 
			  result.min_value = array[i];   
			  result.min_position = i; 
		}
       	  
       	  } 
       	 // IMPLEMENTAR   

    return result;
}

int main()
{
    int array[ARRAY_SIZE] ;
    int i;
    
    
    for(i=0;i<ARRAY_SIZE;i++){
     fflush(stdin);
    	printf("%i.Ingrese datos para el  arreglo : ",i+1);
		scanf("%i",&array[i]);// PEDIR AL USUARIO QUE INGRESE LOS ELEMENTOS DEL ARREGLO.
		
    } 
    

    struct max_min_result result = compute_max_min(array, ARRAY_SIZE);
    
    printf("Maximo: %d\n", result.max_value);
    printf("Posicion del maximo: %u\n", result.max_position);
    printf("Minimo: %d\n", result.min_value);
    printf("Posicion del minimo: %u\n", result.min_position);
    return 0;
}
