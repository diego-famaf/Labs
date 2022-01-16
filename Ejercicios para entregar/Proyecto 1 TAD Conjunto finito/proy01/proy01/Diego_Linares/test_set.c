#include <stdio.h> /* printf()...           */
#include "set.h"   /* Interfaz del TAD set  */

static void
print_set(set s) {
    /* Muestra por pantalla el contenido de un conjunto de enteros */
    /*
     * Es crucial que las funciones:
     *   - set_copy()
     *   - set_get()
     *   - set_elim()
     *   - set_is_empty()
     *
     * estén bien programadas para que se muestre correctamente.
     */
    set saux=set_copy(s);
    printf("{");
    while (!set_is_empty(saux)) {
        type_elem e;
        e = set_get(saux);
        printf("%i", e);
        saux = set_elim(saux, e);
        if (!set_is_empty(saux))
            printf(", ");
     }
    printf("}");
    saux = set_destroy(saux);
}

static void
show_status(set s, const char *name) {
    /*
     * Muestra por pantalla: - La etiquena 'name'
     *                       - El contendio del conjunto
     *                       - Su longitud
     *                       - Si es o no vacío
     */
    /* Se muestra la etiqueta */
    printf("{ %s == ", name);
    /* Se muestra el contenido del conjunto */
    print_set(s);
    printf(" /\\ ");
    /* Se muestra el cardinal */
    printf("|%s| = %i /\\ ", name, set_cardinal(s));
    /* Se indica si es vacío o no */
    if (set_is_empty(s)) printf("empty"); else printf("not empty");
    printf(" }");
    printf("\n\n");
}

int main(void) {
    set s, s2,saux;
    unsigned int n =0;
    bool b = false;
    type_elem d;

    /* Construimos los conjuntos s y s0 */
    s = set_empty();
    s2 = set_empty();

    /* Mostramos el estado de s */
    printf("s = set_empty(s)\n");
    show_status(s, "s");
    /*Vemos si hay o no hay elementos en s */
    b= set_is_empty(s);
    if (b==1)
     {printf("b=set_is_empty(s)\n");printf("true\n");}
    else{printf("b=set_is_empty(s)\n");printf("false\n");}
   /* Mostramos el estado de s2 */
    printf("s2 = set_empty(s2)\n");
    show_status(s2, "s2");
    /* Agregamos un elemento a s y vemos que pasa */
    s = set_add(s, 5);
    printf("s = set_add(s, 5)\n");
    show_status(s, "s");
    /* Agregamos un elemento a s2 y vemos que pasa */
    s2 = set_add(s2, 10);
    printf("s2 = set_add(s2, 10)\n");
    show_status(s2, "s2");
    /* Agregamos varios elementos s y vemos que pasa */
    s = set_add(set_add(s, 8), 2);
    printf("s = set_add(2, set_add(s, 5))\n");
    show_status(s, "s");
    /*Vemos cuantos elementos tiene s */
    n= set_cardinal(s);
    printf("n = set_cardinal(s)\n");
    printf("n = %u\n\n", n);
    /*Vemos si hay o no hay elementos en s */
    b= set_is_empty(s);
    if (b==1)
     {printf("b=set_is_empty(s)\n");printf("true\n");}
    else{printf("b=set_is_empty(s)\n");printf("false\n");}
    /*Verificamos si un elemento pertenece al conjunto s */
    b = set_member(5, s);
    if (b==1)
     {printf("b=set_member(5, s)\n");printf("true\n");}
    else{printf("b=set_member(5, s)\n");printf("false\n");}
    /*Eliminamos un elemento a s y vemos que pasa */
    s = set_elim(s,2);
    printf("s = set_elim(s,2)\n");
    show_status(s, "s");
    /* Agregamos varios elementos  a s2 */
    s2 = set_add(set_add(set_add(s2, 8), 11), 12);
    printf("s2 = set_add(set_add(set_add(s2, 8), 11), 12)\n");
    show_status(s2, "s2");
    /*Unimos s y s2 y vemos que pasa */
    s = set_union(s, s2);
    printf("s = set_union(s, s2)\n");
    show_status(s, "s");
    /* Hacemos la interseccion de s y s2 y vemos que pasa */
    s = set_inters(s,s2);
    printf("s = set_inters(s,s2)\n");
    show_status(s, "s");
    /* Eliminamos de s todos los elementos que pertenecen a s2 */
    s = set_dif(s, s2);
    printf("s = set_dif(s, s2)\n");
    show_status(s, "s");
    /* Agregamos varios elementos s y vemos que pasa */
    s = set_add(set_add(s, 8), 2);
    printf("s = set_add(2, set_add(s, 8))\n");
    show_status(s, "s");
    /*Tomamos un elemento cualquiera de s y vemos que pasa*/
    d= set_get(s);
    printf("d = set_get(s)\n");
    printf("d = %d\n\n", d);
    /*copiamos el conjunto s*/
    saux = set_copy(s);
    printf("saux = set_copy(s)\n");
    show_status(saux, "saux");
    show_status(s, "s");
    /*destruimos saux y s y s2 */
    saux = set_destroy(saux);
    

    
    s = set_destroy(s);
    s2 = set_destroy(s2);
    
    return 0;
}

