#include <assert.h>
#include "dict.h"
#include "string.h"
#include "stdlib.h"

struct _node_t {
    dict_t left;
    dict_t right;
    key_t key;
    value_t value;
     
};

dict_t dict_empty() {
    dict_t dict = NULL;
    
    assert(dict_length(dict) == 0);//elimine dict!=NULL
    
    return dict;
}

dict_t dict_add(dict_t dict, key_t word, value_t def) {
    assert(word != NULL && def != NULL);
     
   if(dict==NULL){
        dict = malloc(sizeof(struct _node_t));
        dict->key = word;
        dict->value = def;
        dict->left = NULL;
        dict->right = NULL;
    }else{

      if(key_eq(word,dict->key)){
         
         dict->value = def;
      }
    else if(key_less(word,dict->key)){
            dict->left = dict_add(dict->left,word,def);
    }
    else if(key_less(dict->key,word)){
            dict->right = dict_add(dict->right,word,def);
    }
    
    }
    //assert(value_eq(def, dict_search(dict, word)));
    return dict;
}

value_t dict_search(dict_t dict, key_t word) {
    key_t def = NULL;
    assert(word != NULL);

    
    
   if(dict!=NULL){
      if(key_eq(dict->key,word)){    
     	def = dict->value;
      }
      else if(key_less(word,dict->key)){
		  def = dict_search(dict->left,word);
      }
      else {
         def = dict_search(dict->right,word);	
      }
    }
    
    return def;    
}

bool dict_exists(dict_t dict, key_t word) {
    assert( word != NULL);
    bool existe = false;

 if(dict!=NULL){
    if(key_eq(dict->key,word)){   
     	 existe = true;
    }
    else if(key_less(word,dict->key)){
         existe = dict_exists(dict->left,word);
		  
	}
    else {
          existe = dict_exists(dict->right,word);
    }
    
    
}
return existe;
}
//retorna el numero de palabras contenidas en el diccionario
unsigned int dict_length(dict_t dict) {
                                        
                                
    if(dict != NULL){
    	
       return(dict_length(dict->left) + 1 + dict_length(dict->right));
    }
	
    return 0u;
}

dict_t Encuentra_min(dict_t dict){

 while(dict->left!= NULL){
 	dict = dict->left;
 } 
 return dict;
}

dict_t dict_remove(dict_t dict, key_t word) {
    assert( word != NULL);
    if(dict!=NULL){
    	if(key_less(dict->key,word)){
    		dict->left = dict_remove(dict->left,word);
    	}
    	if(key_less(word,dict->key)){
    		dict->right = dict_remove(dict->right,word);
    	}
        else{
        	//caso no hijos
        	if(dict->left == NULL && dict->right == NULL){//probar tambien con if(dict_lenght == 1)
        	 free(dict);
			 dict = NULL;
			 return dict;	
        	}//caso un hijo a izquierda o derecha
        	else if(dict->left==NULL){
        	  struct _node_t *temp = dict;
			  dict = dict->right;
			  free(temp);
			  return dict;	
        	}
        	else if(dict->right==NULL){
        	  struct _node_t *temp = dict;
			  dict = dict->left;
			  free(temp);
			  return dict;	
        	}//caso 2 hijos
        	else{
        		struct _node_t *temp = Encuentra_min(dict->right);
        		dict->key = temp->key ;
        		dict->right = dict_remove(dict->right,temp->key);
        	}
        }
    }
    
    
   // assert(dict != NULL && !dict_exists(dict, word));
    return dict;
}

dict_t dict_remove_all(dict_t dict) {
    
    if(dict!=NULL){
        dict->right = dict_destroy(dict->right);
        dict->left = dict_destroy(dict->left);
        dict->key = key_destroy(dict->key);
        dict->value = value_destroy(dict->value);
        free(dict);
        dict = NULL;
    }
    //assert(dict != NULL && dict_length(dict) == 0);
    return dict;
}

void dict_dump(dict_t dict, FILE *file) {
    assert( file != NULL);

   if(dict!=NULL){
    dict_dump(dict->left,file);
    dict_dump(dict->right,file);
    key_dump(dict->key,file);
    fprintf(file,":");
    value_dump(dict->value,file);
    fprintf(file,"\n\n");
         
    
   }
}
dict_t dict_destroy(dict_t dict) {
    
    if(dict!=NULL){
        dict->right = dict_destroy(dict->right);
        dict->left = dict_destroy(dict->left);
        dict->key = key_destroy(dict->key);
        dict->value = value_destroy(dict->value);
        free(dict);
        dict = NULL;


    }
    
    assert(dict == NULL);
    return dict;
}

	
	

