#include <assert.h>
#include <stdlib.h>

#include "cost.h"
#include "graph.h"
#include "set.h"

cost_t c_con_costo_min(set s,cost_t *c){ //
   
 type_elem d,v;
 set copia = set_copy(s);    //s va ser conj despues,es decir en copia tengo una copia de conj
 d = set_get(copia);
 copia = set_elim(copia,d);

   while(!set_is_empty(copia)){
     
      v = set_get(copia);
      copia = set_elim(copia,v);
       if(cost_le(c[v],c[d])){   
          d = v;//aqui siempre me voy quedando con el menor costo del elemento que voy sacando,comparando de a dos,descarto el mayor
       }
      
    }
      
return d; 
}

cost_t *dijkstra(graph_t graph, vertex_t init){

 unsigned int lenght ;

 vertex_t elem_costo_min ;
 cost_t *costos = calloc(graph_max_size(graph), sizeof(cost_t));
 set conj = set_empty();
 //inicializo con todos los vertices
 for(unsigned int i=0;i<graph_max_size(graph);i++){
    
    conj = set_add(conj,i);//en el ej me quedaria[0,1,2,3,4,5]

 }

 lenght = set_cardinal(conj);
 conj = set_elim(conj,init);// elimino el init,porque y ya se cual es el costo,es 0

//ahora queda [1,2,3,4,5]
//actualizo el costo,ahora para ir de init a cada uno de los demas vertices
 for(unsigned int j = 0;j<graph_max_size(graph);j++){
   	
   costos[j]= graph_get_cost(graph,init,j);//j es la posicion, en el ej quedaria [0,4,1,10,#,#]
                                                                  
 } 

 while(!set_is_empty(conj)){
    elem_costo_min = c_con_costo_min(conj,costos);
   
   conj = set_elim(conj,elem_costo_min);
     
   
   for(unsigned int j=0;j<lenght;j++){
     
     if(!cost_le(costos[j],cost_sum(costos[elem_costo_min],graph_get_cost(graph,elem_costo_min,j)))){

        costos[j] = cost_sum(costos[elem_costo_min],graph_get_cost(graph,elem_costo_min,j));
     }
     
  
     
      
   }
 } 
return costos;  



}





