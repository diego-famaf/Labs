#include <stdio.h> /* printf()...           */
#include "set.h"   /* Interfaz del TAD set  */
#include <stdlib.h>
#include "list.h"
#include "assert.h"



struct s_set {
     list sorted_list;
};


set set_empty(void){
     set saux = calloc(1,sizeof(struct s_set));
         
	saux->sorted_list = list_empty();
       
	return saux;
}

set set_add(set s, type_elem e){
   
 unsigned int n = 0;
 bool is_member = false;
 type_elem d ;//inicializar esto por favor¡¡
 set saux = calloc(1,sizeof(struct s_set));  
 saux->sorted_list = list_copy(s->sorted_list);


 //encuentro el lugar donde va el elemento 
  while (!list_is_empty(saux->sorted_list) && !is_member){

    d = list_head(saux->sorted_list);
    if (d == e){
  	is_member = true;
    }  
    else if (d < e){
     	n = n+1;
    }  
     
   saux->sorted_list = list_tail(saux->sorted_list);
 } 


  if ( !is_member){

  s->sorted_list = list_add_at(s->sorted_list,n,e);
}
  saux->sorted_list = list_destroy(saux->sorted_list);
  set_destroy(saux);
return s;

}



unsigned int set_cardinal(set s) {

 unsigned int n ;
 n = list_length(s->sorted_list);

return n;
}




bool set_is_empty(set s){
        bool is_empty ;  
	is_empty = list_is_empty(s->sorted_list);
 
 return is_empty;
}



bool set_member(type_elem e, set s){
 assert(!set_is_empty(s));
 type_elem d;
 bool b = false ;
 set saux = calloc(1,sizeof(struct s_set));
 saux->sorted_list=list_copy(s->sorted_list);  


 while(!list_is_empty(saux->sorted_list) && !b){
  d = list_head(saux->sorted_list);
   if (d==e) {            
  	  b = true;
  }	 
   saux->sorted_list = list_tail(saux->sorted_list);          
  } 
  
  saux->sorted_list = list_destroy(saux->sorted_list);

 set_destroy(saux);
                  
return b;
}



set set_elim(set s, type_elem e){
	
	assert(!set_is_empty(s));
	
	unsigned int n=0;
	bool is_member = true ;
	type_elem d;
	
	set saux = set_empty();
        saux->sorted_list = list_copy(s->sorted_list);
    
    // {-encuentro donde esta el elemento,si es que esta-}
    while(!list_is_empty(saux->sorted_list) && is_member){
    	
    	d = list_head(saux->sorted_list);
    	if(d==e){
    		is_member = false;
    	}
    	else if(d<e){
    		n=n+1;
    	}
    	
    	saux->sorted_list = list_tail(saux->sorted_list);
    	
    }
	if(!is_member){
		
	s->sorted_list = list_elim_at((s->sorted_list),n);
	}
	saux->sorted_list = list_destroy(saux->sorted_list);
      set_destroy(saux);
return s;
}



set set_union(set s, set s0){
	assert(!set_is_empty(s0));
	type_elem d;
	set saux = set_empty();
	saux->sorted_list = list_copy(s0->sorted_list);
	
	while(!list_is_empty(saux->sorted_list)){
		
	 d = list_head(saux->sorted_list);
	 s=set_add(s,d);
		
	 saux->sorted_list = list_tail(saux->sorted_list);
		
	}
	
	saux->sorted_list = list_destroy(saux->sorted_list);
       set_destroy(saux);
	return s;
	}

set set_inters(set s, set s0){
	type_elem d;
        set saux = set_empty();
	saux ->sorted_list=list_copy(s->sorted_list);
	
	while(!list_is_empty(saux->sorted_list)){
		
		d = list_head(saux->sorted_list);
		if(!set_member(d,s0)){
			s = set_elim(s,d);
		}
		saux->sorted_list = list_tail(saux->sorted_list);
		
		
		
	}
	
	saux->sorted_list = list_destroy(saux->sorted_list);
   set_destroy(saux);
return s;
}

set set_dif(set s, set s0){
	type_elem  d ;
        set saux = set_empty();
	saux->sorted_list = list_copy(s0->sorted_list);
	
	while(!list_is_empty(saux->sorted_list)){
		
		d = list_head(saux->sorted_list);
		if(set_member(d,s)){
			s=set_elim(s,d);
		}
		saux->sorted_list = list_tail(saux->sorted_list);
		
	}
	saux->sorted_list = list_destroy(saux->sorted_list);
    set_destroy(saux);
	
	return s;
}



//{- PRE: not is_empty_set(s) -}
type_elem set_get(set s){
	assert(!set_is_empty(s));
	type_elem e;
	e=list_head(s->sorted_list);
	return e;
}


set set_copy(set s){
 assert(s!=NULL);  
 set saux = set_empty();
 saux->sorted_list = list_copy(s->sorted_list);
 return saux;

}
set set_destroy(set s){
        s->sorted_list=list_destroy(s->sorted_list);
	free(s);
        s=NULL;
       return s;
       

}
