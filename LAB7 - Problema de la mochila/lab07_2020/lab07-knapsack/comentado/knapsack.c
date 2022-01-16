#include <stdio.h>
#include "stdlib.h"
#include "item.h"
#include "string.h"
#include "stdbool.h"
#include "knapsack.h"


value_t maxim(value_t v, value_t v1){
    return v > v1? v : v1;
}


value_t knapsack_backtracking(item_t* items, unsigned int array_length, weight_t max_weight)
{
                 value_t val ;
	
                 if (max_weight==0u){
		    val = 0u;
                 }
	         else if(array_length==0u){
		   val = 0u;
	         }
     
	         else if((item_weight(items[array_length - 1u])) > max_weight){
		   val = knapsack_backtracking(items,array_length - 1u,max_weight);
	         }
      
	         else{
		   val = maxim(knapsack_backtracking(items,array_length - 1u,max_weight),item_value(items[array_length - 1u]) + knapsack_backtracking(items,array_length - 1u, max_weight - (item_weight(items[array_length - 1u]))));
	         }
                 
                 return val;

}

value_t knapsack_dynamic(item_t* items, unsigned array_length, weight_t max_weight){

                  
           
     value_t **moch = calloc((array_length + 1u),sizeof(value_t*));
     
      for(unsigned int i=0u;i<(array_length + 1u);i++){
             moch[i] = calloc((max_weight +1u),sizeof(value_t));
      }

      for(unsigned int i=0;i<array_length;i++){
             moch[i][0] = 0 ;
      }
      
      for(unsigned int j=1;j<max_weight;j++){
             moch[0][j] = 0 ;

      }

    
   
      for(unsigned int i=1u;i<array_length + 1u ;i++){
             for(unsigned int j=1u;j<max_weight + 1u ;j++){
               
                if((item_weight(items[i-1])) > j){
                  moch[i][j] = moch[i-1][j];
                }
                else {
                  moch[i][j] = maxim(moch[i-1][j],item_value(items[i-1]) + moch[i-1][j-(item_weight(items[i-1]))]);
                }
                
             }
      }

  value_t res = (moch[array_length][max_weight]);
      
   for(unsigned int i=0u;i < array_length + 1u ;i++){
            
          free(moch[i]);
          moch[i] = NULL;
   }

          free(moch); 
          moch = NULL;
     


   return res;

   
      

}

value_t knapsack_dynamic_selection(item_t* items, bool* selected, unsigned int array_length, weight_t max_weight){


                  
     value_t **moch = calloc((array_length +1u),sizeof(value_t*));
            

      for(unsigned int i=0u;i<(array_length + 1u);i++){
             moch[i] = calloc((max_weight +1u ),sizeof(value_t));
     }
     

      
     
      for(unsigned int i=0;i<array_length;i++){
             moch[i][0] = 0 ;
      }
      
      for(unsigned int j=1;j<max_weight;j++){
             moch[0][j] = 0 ;

      }
       
      for(unsigned int i=1u;i<array_length +1u;i++){
             for(unsigned int j=1u;j<max_weight + 1u;j++){
                
                if((item_weight(items[i-1]))>j){
                  moch[i][j] = moch[i-1][j];
                }
                else{
                  moch[i][j] = maxim(moch[i-1][j],item_value(items[i-1]) + moch[i-1][j-(item_weight(items[i-1]))]);
                }
             }
      }
      



    unsigned  int  r = array_length ;
    unsigned  int  s = max_weight  ;

       
          

      

      while(moch[r][s] > 0){
          if(moch[r][s] == moch[r-1][s]){
            selected[r-1] = false;
          }
          else{
            selected[r-1] = true;
            s = s-(item_weight(items[r-1]));
          }
          
          r = r-1;
      }
      
   value_t res = (moch[array_length][max_weight]);
      
   for(unsigned int i=0u;i < array_length + 1u ;i++){
            
          free(moch[i]);
          moch[i] = NULL;
   }

          free(moch); 
          moch = NULL;

      return res;


 }


