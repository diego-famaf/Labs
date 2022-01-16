#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

#include "set.h"
#include "list.h"

struct s_set {
    list sorted_list;
};


set set_empty(void){

    set s = calloc(1, sizeof(struct s_set));

    s->sorted_list = list_empty();

    assert(s!= NULL);

    return (s);
}


set set_add(set s, type_elem e){

    assert(s!= NULL);

    int n = 0;
    type_elem d;

    set saux = calloc(1, sizeof(struct s_set));

    saux->sorted_list = list_copy(s->sorted_list);

    bool is_member= false;

    while(!list_is_empty(saux->sorted_list) && !is_member) {
            d = list_head(saux->sorted_list);
        if (d == e) {
            is_member = true;
        } else if (d < e) {
            n = n + 1;
        }
        saux->sorted_list = list_tail(saux->sorted_list);
    }
    if (!is_member) {
        s->sorted_list = list_add_at(s->sorted_list, n, e);
    }
    set_destroy(saux);
    return s;
}


/* OPERATIONS   */


unsigned int set_cardinal(set s){

    assert(s!= NULL);

    unsigned int n;
    n = list_length(s->sorted_list);
    return n;
}


bool set_is_empty(set s){

    bool is_empty= list_is_empty(s->sorted_list);

    return (is_empty);
}


bool set_member(type_elem e, set s) {

    assert(s != NULL);

    set saux = calloc(1, sizeof(struct s_set));
    saux->sorted_list = list_copy(s->sorted_list);
    bool member = false;
    type_elem d;

    while(!list_is_empty(saux->sorted_list) && !member){
            d = list_head(saux->sorted_list);
            if(e == d){
                member = true;
            }
            saux->sorted_list = list_tail(saux->sorted_list);
    }
    set_destroy(saux);
    return (member);
}


set set_elim(set s, type_elem e){

    assert(s!= NULL);

    set saux = calloc(1, sizeof(struct s_set));
    saux->sorted_list= list_copy(s->sorted_list);
    type_elem d;

    unsigned int n = 0;
    bool member = false;

    while (!list_is_empty(saux->sorted_list) && !member ) {
        d = list_head(saux->sorted_list);
         if(d == e) {
            member = true;
        } else if (d < e) {
            n++;
        }
        saux->sorted_list = list_tail(saux->sorted_list);
    }
    if(member){
        s->sorted_list = list_elim_at(s->sorted_list,n);
    }

    set_destroy(saux);

    return s;
}


set set_union(set s, set s0){

    set saux = calloc(1, sizeof(struct s_set));
    saux->sorted_list = list_copy(s0->sorted_list);

    type_elem d;

    while(!list_is_empty(saux->sorted_list)) {
        d = list_head(saux->sorted_list);
        s = set_add(s, d);
        saux->sorted_list = list_tail(saux->sorted_list);
    }

    set_destroy(saux);

    return(s);
}


set set_inters(set s, set s0){

    assert(s != NULL && s0!= NULL);

    set saux = calloc(1, sizeof(struct s_set));
    saux->sorted_list= list_copy(s->sorted_list);
    type_elem d;

        while (!list_is_empty(saux->sorted_list)) {
            d = list_head(saux->sorted_list);
            if(!set_member(d,s0)) {
                s = set_elim(s,d);
            }
            saux->sorted_list = list_tail(saux->sorted_list);
        }
    set_destroy(saux);

    return (s);
}


set set_dif(set s, set s0){

    assert(!set_is_empty(s));

    set saux = calloc(1, sizeof(struct s_set));
    saux->sorted_list= list_copy(s0->sorted_list);
    type_elem d;

    while (!list_is_empty(saux->sorted_list)) {
        d = list_head(saux->sorted_list);
        if(set_member(d,s)) {
            s = set_elim(s,d);
        }
        saux->sorted_list = list_tail(saux->sorted_list);
    }

    set_destroy(saux);

    return s;
}


type_elem set_get(set s){

    type_elem e;

    if(set_is_empty(s)){

        e = set_cardinal(s);
    } else {

        e = list_head(s->sorted_list);
    }

    return e;
}


set set_copy(set s){


    set saux = set_empty();
    saux->sorted_list = list_copy(s->sorted_list);

    return saux;
}


set set_destroy(set s){

    s->sorted_list = list_destroy(s->sorted_list);
    free(s);
    s = NULL;
    return(s);
}
