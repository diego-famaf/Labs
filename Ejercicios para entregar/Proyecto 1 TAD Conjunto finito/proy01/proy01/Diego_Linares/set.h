#ifndef _SET_H_
#define _SET_H_

#include <stdbool.h>   /* Definition of bool      */
#include "type_elem.h" /* Definition of type_elem */

typedef struct s_set * set;


/* CONSTRUCTORS */

set set_empty(void);
/*
 * DESC: Creates a new empety set
 * USAGE: s = set_empty();
 * POS  : {set_is_empty(s)}
 */

set set_add(set s, type_elem e);
/*
 * DESC: Adds element 'e' to the start of set 's'
 * PRE  : {set_cardinal(s) == N}
 * USAGE: s = set_add(s, e);
 * POS  : {set_cardinal(s) == N + 1 /\ e == set_head(s)}
 */

/* OPERATIONS   */

unsigned int set_cardinal(set s);
/*
 * DESC: Returns the size of set 's'
 * USAGE: n = set_cardinal(s);
 */

bool set_is_empty(set s);
/*
 * DESC: Indicates if there are no elements in set 's'
 * USAGE: is_empty = set_is_empty(s);
 * POS  : {is_empty == (set_cardinal(s) == 0)}
 */

bool set_member(type_elem e, set s);
/*
 * DESC: Return True if there the element e to set s 
 * PRE: {!set_is_empty(s)}
 * USAGE: b = set_member(s,e)
 */
set set_elim(set s, type_elem e);
/*
 * DESC: - Delete the element e of set s, in case it is 
 * PRE  : {!set_is_empty(s)}
 * USAGE: s = set_elim(s,e);
 * POS  : {set_cardinal(s) == N \/  set_cardinal(s) == N-1}
 */

set set_union(set s, set s0);
/*
 * DESC : Add to s all the elements of s0   
 * PRE  : {!set_is_empty(s0) /\ set_cardinal(s) == N /\ set_cardinal(s0) == M}
 * USAGE: s = set_union(s, s0);
 * POS  : {set_cardinal(s) == N + M}
 */

set set_inters(set s, set s0);
/*
 * DESC: Delete of s all the elements with NOT belong to s0   
*  USAGE: s = set_inters(s, s0);
*/

set set_dif(set s, set s0);
/*
 * DESC :Elimina de s todos los elementos que pertenecen a s0 
*/
type_elem set_get(set s);
/*
 * DESC :Obtiene algun elemento cualquiera del conjunto s 
 * PRE  : {!set_is_empty(s) /\ set_length(s) == N}
*  USAGE: b = set_get(s);
*  POS  : {b= set_get(s)};
*/


set set_copy(set s);
/*
 * DESC: Returns a copy of the set 's' with new memory.
 * USAGE: s2 = set_copy(s);
 * POS  : {set_length(s) == set_length(s2) /\ (s != s2 \/ is_empty(s)}
 */

set set_destroy(set s);
/*
 * DESC: Destroy set 's' by freeing all the allocated resources.
 * USAGE: s = set_destroy(s);
 * POS  : {s == NULL}
 */

#endif
