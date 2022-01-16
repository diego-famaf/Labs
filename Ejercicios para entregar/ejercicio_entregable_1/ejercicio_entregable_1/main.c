/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/* Then, this project's includes, alphabetically ordered */
#include "array_helpers.h"

/* Maximum allowed length of the array */
static const unsigned int MAX_SIZE = 100000u;

void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n"
           "Save an array given in a file in disk.\n"
           "\n"
           "The input file must have the following format:\n"
           " * The first line must contain only a positive integer,"
           " which is the length of the array.\n"
           " * The second line must contain the members of the array"
           " separated by one or more spaces. Each member must be an integer."
           "\n\n"
           "In other words, the file format is:\n"
           "<amount of array elements>\n"
           "<array elem 1> <array elem 2> ... <array elem N>\n\n",
           program_name);
}

// Ej 1: Funtion that finds the peak on the array, if it does not exist, return -1

bool tiene_cima(int a[],unsigned int length){


    unsigned int i = 0;
    unsigned int j = length-1;
    bool b = true;
    while(i < length && i!=j && b){                      // while(i < j && b){                                
        if(a[i] < a[i+1]){
            ++i;
        }
        else if(a[j] < a[j-1]){
            --j;
        }
        else{
            b = false; 
        }
    }
    return i == j;
}
int array_peak_sequential(int a[], unsigned int length) {
  
  
      unsigned int i = 0;
    if(tiene_cima(a, length) && length > 0){
        while(i < length && a[i] < a[i+1]){
            ++i;
        }
    }
    else{
        return -1;
    }
    return i;
                  /* for(unsigned int i=0;i<length-1;i++){
  	
                 	if(a[i]>a[i+1]&&tiene_cima(a,length)){
  	         	return a[i];
  	                }
  	                else{
  		        return -1;
  	                }
  	
                        }
  
                       return a[length-1];*/
  
    
    	  
    	  
    	  
    
/*bool ordenas(int a[],unsigned int lft, unsigned int rgt){
  bool bandera = true;
  lft = 0;
  
   while(lft<rgt && bandera){
      if(a[lft]<a[lft+1]){
            return bandera;
     }else
       { bandera = false;}
   lft++;
   }
   return bandera;
}
*/
  //please change whatever you need here to make it work.
  return 0;
}
unsigned int array_peak_binary_rec(int a[], unsigned int lft, unsigned int rgt){
    
     unsigned int mid;
     unsigned int cima;
    
     if(lft == rgt){//caso de un elemento en el array
        return rgt;
     }
     if(a[lft] > a[lft+1]){ //caso [7,6]  aca podria ser solo con: orddescendente(a,lft,rgt)?
         return lft;
     }
     if(lft < rgt){         
        mid = (lft+rgt)/2;
     }
     if(a[mid-1] < a[mid] && a[mid] < a[mid+1]){//&& ordenas(a,lft,mid)){      //caso ej [1,2,6,7,3] 
         cima = array_peak_binary_rec(a, mid+1, rgt);
     }
     else if(a[mid-1] < a[mid] && a[mid] > a[mid+1]){ // && ordasc(a,lft,mid) caso ej [3,6,7,2,1] cima = 2 mid coincide con la cima
         cima = mid;
     }
     else if(a[mid-1] > a[mid] && a[mid-1] > a[mid+1]){ //caso ej [3,7,6,2,1]
         cima = array_peak_binary_rec(a, lft, mid);
     }
     return cima;
}

// Ej 2: Funtion that finds the peak on the array, if it does not exist, return -1
int array_peak_binary(int a[], unsigned int length) {
  
  unsigned int cima = array_peak_binary_rec(a,0,length);
  return cima;
 

  

  //please change whatever you need here to make it work.
  return 0;
}

char *parse_filepath(int argc, char *argv[]) {
    /* Parse the filepath given by command line argument. */
    char *result = NULL;

    if (argc < 2) {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return (result);
}

int main(int argc, char *argv[]) {
  char *filepath = NULL;

  /* parse the filepath given in command line arguments */
  filepath = parse_filepath(argc, argv);

  /* create an array of MAX_SIZE elements */
  int array[MAX_SIZE];

  /* parse the file to fill the array and obtain the actual length */
  unsigned int length = array_from_file(array, MAX_SIZE, filepath);

  /* show the ordered array in the screen */
  array_dump(array, length);

  int this_is_the_peak = array_peak_sequential(array, length);
  printf("The peak secuential is: %d", this_is_the_peak);

  //TODO: Uncomment this to do part b
  int this_is_the_peak2 = array_peak_binary(array, length);
  printf("The peak binary is: %d", this_is_the_peak2);

  return (1);
}
